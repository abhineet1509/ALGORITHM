def rotate(mat):
    mat[:] = list(zip(*mat[::-1])) # row reverse-> unpack ->transpose(zip) ->list

n = int(input())
mat = [list(map(int,input().split())) for _ in range(n)]
rotate(mat)
for row in mat:
    print(*row)

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

rotated = list(zip(*matrix[::-1]))
print(rotated)

n = len(matrix)
m = len(matrix[0])
# transpose
for i in range(n):
    for j in range(i, n):
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

# reverse each row
for row in matrix:
    row.reverse()

print(matrix)

#using numpy for large matrices
import numpy as np

matrix = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])

rotated = np.rot90(matrix, -1)  # -1 = clockwise
print(rotated)


rotated = list(zip(*matrix))[::-1]    #90 
rotated = [row[::-1] for row in matrix[::-1]]   #180
rotated = list(zip(*matrix[::-1]))[::-1]    #270
