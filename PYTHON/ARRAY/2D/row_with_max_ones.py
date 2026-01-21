def row_max_ones(mat):
    max_row = -1
    max_count = 0
    for i,row in enumerate(mat):
        cnt = row.count(1)
        if cnt > max_count:
            max_count = cnt
            max_row = i
    return max_row

r,c = map(int,input().split())
mat = [list(map(int,input().split())) for _ in range(r)]
print(row_max_ones(mat))
