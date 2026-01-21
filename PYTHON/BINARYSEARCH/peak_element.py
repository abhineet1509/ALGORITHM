def find_peak(arr):
    l, r = 0, len(arr)-1
    while l < r:
        mid = (l+r)//2
        if arr[mid] < arr[mid+1]:
            l = mid + 1
        else:
            r = mid
    return l

arr = list(map(int, input().split()))
print(find_peak(arr))

#peak element in matrix
def findPeakGrid(mat):
    rows, cols = len(mat), len(mat[0])
    low, high = 0, cols - 1

    while low <= high:
        mid = (low + high) // 2
        max_row = 0
        for i in range(rows):
            if mat[i][mid] > mat[max_row][mid]:
                max_row = i

        left = mat[max_row][mid - 1] if mid - 1 >= 0 else -1
        right = mat[max_row][mid + 1] if mid + 1 < cols else -1

        if mat[max_row][mid] > left and mat[max_row][mid] > right:
            return [max_row, mid]
        elif mat[max_row][mid] < right:
            low = mid + 1
        else:
            high = mid - 1
