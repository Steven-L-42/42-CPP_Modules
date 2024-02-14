#!/bin/bash

PROGRAM=./RPN

# Build the program
make re

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Error building $PROGRAM."
    exit 1
fi

# Define test cases
TESTS=(
    "2 3 +"
    "5 7 -"
    "4 6 *"
    "8 2 /"
    "1 2 + 3 *"
    "9 3 / 2 *"
    "5 2 / 3 +"
    "0 9 - 2 *"
    "8 4 / 2 -"

    "2 3 4 * + 5 /"
    "1 2 3 * 4 / +"
    "7 3 * 4 2 / -"
    "8 4 / 2 * 6 +"
    "9 2 / 4 * 6 2 / +"
    "5 6 * 2 / 7 +"
    "1 2 + 3 4 * /"
    "4 2 / 3 * 5 -"
    "6 2 * 8 3 / + 3 *"
    "9 4 / 2 * 7 3 / + 6 *"
    "8 9 * 9 - 9 - 9 - 4 - 1 +"
    "7 7 * 7 -"
    "1 2 * 2 / 2 * 2 4 - +"
)

EXPECTED=(
    "5"
    "-2"
    "24"
    "4"
    "9"
    "6"
    "5.5"
    "-18"
    "0"

    "2.8"
    "2.5"
    "19"
    "10"
    "21"
    "22"
    "0.25"
    "1"
    "44"
    "41"
    "42"
    "42"
    "0"
)

BLUE="\033[1;34m"
GREEN="\033[1;32m"
RED="\033[1;31m"
WHITE="\033[1;37m"
RESET="\033[0m"

# Run simple tests
for ((i=0; i<${#TESTS[@]}; i++)); do
    TEST="${TESTS[$i]}"
    EXPECT="${EXPECTED[$i]}"

    echo $WHITE"$(expr $i + 1). Running test: $TEST"
    RESULT=$($PROGRAM "$TEST")

    # Check the result
    if [ "$RESULT" == "$EXPECT" ]; then
        echo $GREEN"Test passed!"$WHITE
    else
        echo $BLUE"Yours: $RESULT Expected: $EXPECT"
        echo $RED"Test failed!\n"$WHITE
    fi
done

ERROR_TEST=(
    "5"
    "7 +"
    "+ 7"
    "2 - -"
    "2 2 2 -"
    "test"
    "(1 + 1)"
)

# Run tests with an error
for TEST in "${ERROR_TEST[@]}"; do
    echo $WHITE"Running test: $TEST"$BLUE
    $PROGRAM "$TEST" 2> /dev/null

    if [ $? -eq 1 ]; then
        echo $GREEN"Program works as expected."
    else
        echo $RED"Program did not catch the error."
    fi
done


echo $BLUE"Testing complete."

make fclean
