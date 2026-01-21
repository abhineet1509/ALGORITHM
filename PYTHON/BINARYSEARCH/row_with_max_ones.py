def rowWithMax1s(mat):
    max_ones = -1
    row_index = -1

    for i in range(len(mat)):
        count = mat[i].count(1)
        if count > max_ones:
            max_ones = count
            row_index = i
    return row_index
