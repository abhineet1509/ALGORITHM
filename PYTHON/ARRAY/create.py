# ===============================
# ALL WAYS TO CREATE ARRAYS IN PYTHON
# ===============================

# 1. Direct initialization
arr1 = [1, 2, 3, 4, 5]
print("Direct initialization:", arr1)

# 2. Using input (space separated)
# Example input: 10 20 30
arr2 = list(map(int, input("Enter elements: ").split()))
print("Using input:", arr2)

# 3. Using loop
n = int(input("Enter size: "))
arr3 = []
for _ in range(n):      # throw away variable
    arr3.append(int(input()))
print("Using loop:", arr3)

# 4. Using list comprehension
arr4 = [i for i in range(5)]
print("List comprehension:", arr4)

# 5. Using range()
arr5 = list(range(1, 6))
print("Using range:", arr5)

# 6. Creating array with same elements
arr6 = [0] * 5
print("Zero array:", arr6)

arr7 = [7] * 4
print("Same value array:", arr7)

# 7. Using array module
from array import array
arr8 = array('i', [1, 2, 3, 4])
print("Array module:", arr8.tolist())

# 8. From string / iterable
arr9 = list("hello")
print("From string:", arr9)

arr10 = list(map(int, "12345"))
print("From iterable string:", arr10)

# ===============================
# 2D ARRAY CREATION
# ===============================

# 9. Direct 2D array
mat1 = [
    [1, 2, 3],
    [4, 5, 6]
]
print("Direct 2D array:", mat1)

# 10. 2D array using input
# Example:
# 2 3
# 1 2 3
# 4 5 6
r, c = map(int, input("Enter rows and cols: ").split())
mat2 = [list(map(int, input().split())) for _ in range(r)]
print("2D array using input:", mat2)

# 11. Zero matrix
r, c = 3, 4
mat3 = [[0] * c for _ in range(r)]
print("Zero matrix:", mat3)

# ===============================
# END OF PROGRAM
# ===============================
