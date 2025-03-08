# Nom(s) étudiant(s) / Name(s) of student(s): Yorguin José Mantilla Ramos

import sys

# Espace pour fonctions auxillaires :
# Space for auxilary functions :


def get_median(numbers):
    print(numbers)
    n = len(numbers)
    if n % 2 == 0:
        return (numbers[n//2-1] + numbers[n//2]) / 2
    else:
        return numbers[n//2]

def get_pairs_two_pointers(arr, target):
    left, right = 0, len(arr) - 1
    count = 0
    pairs=[]

    while left < right:
        pair_sum = arr[left] + arr[right]

        if pair_sum == target:
            count += 1
            left += 1
            right -= 1  # Move both pointers inward
            pairs.append((arr[left], arr[right]))
            # Skip duplicates by moving past identical values
            while left < right and arr[left] == arr[left - 1]:
                left += 1
            while left < right and arr[right] == arr[right + 1]:
                right -= 1

        elif pair_sum < target:
            left += 1  # Increase sum by moving left pointer
        else:
            right -= 1  # Decrease sum by moving right pointer

    return pairs # im returning the pairs themselves because process_numbers does the len() call

# Fonction à compléter / function to complete:
def solve(numbers):
    median = get_median(numbers)

    # Find pairs using two pointer technique in O(n) time given that the list is ALREADY sorted
    # The idea is that in a single run we scan from the beginning and end of the list with two pointers
    # and check if the sum of the two numbers is equal to the target sum

    return get_pairs_two_pointers(numbers, median)


# Ne pas modifier le code ci-dessous :
# Do not modify the code below :

def process_numbers(input_file):
    try:
        # Read integers from the input file
        with open(input_file, "r") as f:
            content = f.read()
        
        # Convert content into a list of integers
        numbers = list(map(int, content.split()))

        pairs = solve(numbers)

        return(len(pairs))

    except Exception as e:
        print(f"Error: {e}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python Q3.py <input_file>")
        return

    input_file = sys.argv[1]

    print(f"Input File: {input_file}")
    res = process_numbers(input_file)
    print(f"Result: {res}")

if __name__ == "__main__":
    main()