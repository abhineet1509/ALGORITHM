def set_zero(mat):
    rows, cols = set(), set()
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == 0:
                rows.add(i); cols.add(j)
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if i in rows or j in cols:
                mat[i][j] = 0

r,c = map(int,input().split())
mat = [list(map(int,input().split())) for _ in range(r)]
set_zero(mat)
for row in mat:
    print(*row)
