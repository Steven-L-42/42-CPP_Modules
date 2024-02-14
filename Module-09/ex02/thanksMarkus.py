import subprocess
import random


def generate_random_list(size):
    return [str(random.randint(0, 100000000)) for _ in range(size)]

def run_make():
    compile_process = subprocess.run(['make', 're'], capture_output=True, text=True)
    if compile_process.returncode != 0:
        print(f'Compile Error: {compile_process.stderr}')
        exit()

def run_test(data):
    args = ['./PmergeMe'] + data
    subprocess.run("make", capture_output=True, text=True)
    result = subprocess.run(args, capture_output=True, text=True)
    return result.stdout.strip()

if __name__ == '__main__':
    run_make()
    data = generate_random_list(5)
    output = run_test(data)
    print(f"\033[1;34m"f"Test with 5 numbers:\n{output}\n")

    data = generate_random_list(500)
    output = run_test(data)
    print(f"\033[1;34m"f"Test with 500 numbers:\n{output}\n")

    data = generate_random_list(1000)
    output = run_test(data)
    print(f"\033[1;34m"f"Test with 1000 numbers:\n{output}\n")

    data = generate_random_list(5000)
    output = run_test(data)
    print(f"\033[1;34m"f"Test with 5000 numbers:\n{output}\n")

    data = generate_random_list(10000)
    output = run_test(data)
    print(f"\033[1;34m"f"Test with 10000 numbers:\n{output}\n")

    data = generate_random_list(15000)
    output = run_test(data)
    print(f"\033[1;34m"f"Test with 15000 numbers:\n{output}\n")

    subprocess.run(['make', 'clean'], capture_output=True, text=True)
