def max_subarray_sum(arr):
    curr = max_sum = arr[0]
    for x in arr[1:]:
        curr = max(x, curr + x)
        max_sum = max(max_sum, curr)
    return max_sum

arr = list(map(int, input().split()))
print(max_subarray_sum(arr))
