mat = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
transpose1 = [list(row) for row in zip(*mat)]  # Break a collection into individual element
print("Using zip():")
print(transpose1)

rows = len(mat)
cols = len(mat[0])

transpose2 = [[0]*rows for _ in range(cols)] #inilialise an empty matrix

for i in range(rows):
    for j in range(cols):
        transpose2[j][i] = mat[i][j]

print("Using nested loops:")
print(transpose2)

transpose3 = [[mat[i][j] for i in range(len(mat))]
              for j in range(len(mat[0]))]

print("Using list comprehension:")
print(transpose3)

mat_inplace = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

n = len(mat_inplace)

for i in range(n):
    for j in range(i + 1, n):
        mat_inplace[i][j], mat_inplace[j][i] = mat_inplace[j][i], mat_inplace[i][j]

print("In-place transpose:")
print(mat_inplace)
