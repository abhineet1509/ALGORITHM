def search(mat, key):
    i, j = 0, len(mat[0])-1
    while i < len(mat) and j >= 0:
        if mat[i][j] == key:
            return True
        elif mat[i][j] > key:
            j -= 1
        else:
            i += 1
    return False

r,c = map(int,input().split())
mat = [list(map(int,input().split())) for _ in range(r)]
key = int(input())
print(search(mat, key))
