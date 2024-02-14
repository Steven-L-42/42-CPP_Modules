import random
from datetime import datetime
import subprocess
import argparse
import os

PROGRAM = './btc'
MAKE = ['re', 'fclean']


def generate_random_date(lower_bound, upper_bound):
    """Generate a random valid date."""
    year = random.randint(lower_bound, upper_bound)
    month = random.randint(1, 12)
    day = random.randint(1, 28)
    return datetime(year, month, day).strftime("%Y-%m-%d")


def generate_random_value(ratio_lower, ratio_upper):
    """Generate a random value."""
    return random.randint(ratio_lower, ratio_upper)


def create_file(filename, lines, lower_bound, upper_bound, ratio_lower, ratio_upper):
    """Create and write to the text file."""
    with open(filename, "w") as f:
        f.write("date | value\n")
        for _ in range(lines):
            date_str = generate_random_date(lower_bound, upper_bound)
            value = generate_random_value(ratio_lower, ratio_upper)
            f.write(f"{date_str} | {value}\n")


def build_program():
    """Build the program and check for errors."""
    if not os.system(f"make {MAKE[0]}") == 0:
        print(f"Error building {PROGRAM}.")
        exit(1)


def run_program(filename):
    """Run the program with the given filename."""
    subprocess.run([PROGRAM, filename])


if __name__ == '__main__':

    build_program()

    filename = "test_file_1.txt"
    create_file(filename, 20, 2000, 2030, 0, 500)
    run_program(filename)

    print("\n")

    filename = "test_file_2.txt"
    create_file(filename, 5, 20, 4000, -10, 800)
    run_program(filename)

    print("\n")

    filename = "test_file_3.txt"
    create_file(filename, 50, 2011, 2025, 10, 50)
    run_program(filename)

    print("\n")
    os.system(f"make {MAKE[1]}")
