# Nom(s) étudiant(s) / Name(s) of student(s):
# Student: Yorguin José Mantilla Ramos - 20253616
import sys

# Espace pour fonctions auxillaires :
# Space for auxilary functions :

## Naive approach with somewhat careful merge
def get_median(numbers):
    n = len(numbers) # len is in O(1) time in the python list implementation
    if n == 0:
        return None
    if n % 2 == 0:
        return (numbers[n//2-1] + numbers[n//2]) / 2
    else:
        return numbers[n//2]
def sorted_merge(nums1, nums2):
    # This one should be on O(n+m) time complexity
    size1 = len(nums1)
    size2 = len(nums2)
    
    if size1 > size2:
        nums1, nums2 = nums2, nums1  # Swap to ensure nums1 is the smaller list
        size1, size2 = size2, size1

    if size1 == 0:  # Edge case: if one list is empty
        size1 = size2
        nums1 = nums2
        size2 = 0
        nums2 = []
    
    i, j = 0, 0
    merged = []
    
    while True:
        if i == size1:
            merged += nums2[j:]  # Add the remaining elements of nums2
            break
        if j == size2:
            merged += nums1[i:]  # Add the remaining elements of nums1
            break
        if nums1[i] < nums2[j]:  # Merge step (sorted merge)
            merged.append(nums1[i])
            i += 1
        else:
            merged.append(nums2[j])
            j += 1
    return merged

## Divide and conquer approach
def find_kth_smallest(nums1, nums2, k):
    #print('Nums1:', nums1, 'Nums2:', nums2, 'K:', k)
    # Function to find the k-th smallest element in two sorted arrays
    # k is always 1-based index (k=1 means the smallest element)
    
    # Base case: if nums1 is empty, return the k-th element from nums2
    if not nums1:
        #print('List 1 is empty')
        return nums2[k-1]  # k is 1-based, so we access k-1 (0-based indexing in Python)
    
    # Base case: if nums2 is empty, return the k-th element from nums1
    if not nums2:
        #print('List 2 is empty')
        return nums1[k-1]  # k is 1-based, so we access k-1 (0-based indexing in Python)
    
    # Base case: if k == 1, return the smallest element from both arrays
    if k == 1:
        #print('K=1', 'Getting the smallest between', nums1[0], nums2[0])
        return min(nums1[0], nums2[0])  # k=1 means smallest element
    
    # Get the k//2-th element from each list, if it exists
    # If the list has fewer than k//2 elements, we set mid to infinity (inf)
    # to effectively ignore it
    mid1 = nums1[k//2 - 1] if len(nums1) >= k//2 else float('inf')  # k is 1-based
    mid2 = nums2[k//2 - 1] if len(nums2) >= k//2 else float('inf')  # k is 1-based
    #print('Middle values:', mid1, mid2)

    # Remove k//2 elements from the list with the smaller mid value
    # Why? Because we know that the k-th smallest element **cannot** be 
    # in the first k//2 elements of this array.
    # This is because:
    # - The k-th smallest element is greater than at least k//2 elements overall.
    # - If mid1 < mid2, then mid1 and all elements before it in nums1 are too small 
    #   to be the k-th smallest element.
    
    if mid1 < mid2:
        # Remove the first k//2 elements from nums1
        # The total number of elements to consider is reduced by k//2
        # We now look for the (k - k//2)-th smallest element in the 
        # remaining part of nums1 and full nums2
        return find_kth_smallest(nums1[k//2:], nums2, k - k//2)  
    else:
        # Remove the first k//2 elements from nums2
        # Similarly, we now look for the (k - k//2)-th smallest element
        return find_kth_smallest(nums1, nums2[k//2:], k - k//2)

def divide_and_conquer(nums1, nums2):
    # Intuition:
    # - The median is the middle element in a sorted list.
    
    # - If the total number of elements (k = len(nums1) + len(nums2)) is even,
    #   the median is the average of the two middle elements.
    #   (the k//2-th and (k//2 + 1)-th smallest in 1-based indexing).
    
    # - If the total number of elements is odd,
    #   the median is the middle element (the (k//2 + 1)-th smallest in 1-based indexing).
    
    # - The challenge is to find these elements without fully merging the two sorted lists.
    #   We use a *divide-and-conquer* approach (binary search on k-th smallest).
    
    # - Instead of merging, we repeatedly remove k//2 elements from one of the arrays.
    
    # - To do this:
    #   0. Suppose you are looking for the k-th smallest element.
    #   1. Compare the k//2-th element in each array.
    #   2. Remove the first k//2 elements from the array with the smaller k//2-th element.
    #      We can ignore these elements as the k-th element you are looking for 
    #      is greater than k//2 elements in that array.
    #   3. Repeat this logic until k=1 (base case).

    total_len = len(nums1) + len(nums2)  # Compute total length of both arrays
    #print('Total Len:',total_len)
    
    # If the total length is odd, return the middle element
    if total_len % 2 == 1:
        #print('Odd Case')
        return find_kth_smallest(nums1, nums2, total_len // 2 + 1)  
        # k is 1-based, so the middle element is at k//2 + 1
    
    # If the total length is even, return the average of the two middle elements
    else:
        #print('Even Case')
        right = find_kth_smallest(nums1, nums2, total_len // 2 + 1)  # Right median
        left = find_kth_smallest(nums1, nums2, total_len // 2)  # Left median, (the one before)
        return (left + right) / 2  # Compute the average

# Fonction à compléter / function to complete:
def solve(nums1,nums2):
    return divide_and_conquer(nums1,nums2)

    # naive approach would be
    # merged = sorted_merge(nums1, nums2)
    # return get_median(merged)

# Ne pas modifier le code ci-dessous :
# Do not modify the code below :

# Ne pas modifier le code ci-dessous :

def process_numbers(input_file):
    try:
        # Read integers from the input file
        with open(input_file, "r") as f:
            lines = f.readlines() 
            l0 = list(map(int, lines[0].split()))    
            l1 = list(map(int, lines[1].split()))    

        return solve(l0,l1)
    
    except Exception as e:
        print(f"Error: {e}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python Q6.py <input_file>")
        return

    input_file = sys.argv[1]

    print(f"Input File: {input_file}")
    res = process_numbers(input_file)
    print(f"Result: {res}")

if __name__ == "__main__":
    main()