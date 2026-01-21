#input and print a matrix
r, c = map(int, input().split())
mat = []
for i in range(r):
    mat.append(list(map(int, input().split())))

for row in mat:
    print(*row)

#sum of all element of matrix
r, c = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(r)]
s = 0
for i in range(r):
    for j in range(c):
        s += mat[i][j]
print(s)

#row wise sum
r, c = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(r)]
 
for i in range(r):
    print(sum(mat[i]))

#cloumn wise sum
r, c = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(r)]

for j in range(c):
    s = 0
    for i in range(r):
        s += mat[i][j]
    print(s)

#maximum element in matrix
r, c = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(r)]

mx = mat[0][0]
for i in range(r):
    for j in range(c):
        if mat[i][j] > mx:
            mx = mat[i][j]
print(mx)

#search a element in matrix
r, c = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(r)]
key = int(input())

found = False
for i in range(r):
    for j in range(c):
        if mat[i][j] == key:
            print(i, j)
            found = True
            break
if not found:
    print(-1)
