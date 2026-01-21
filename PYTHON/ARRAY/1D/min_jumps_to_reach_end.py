def min_jumps(arr):
    jumps = curr_end = far = 0
    for i in range(len(arr)-1):
        far = max(far, i+arr[i])
        if i == curr_end:
            jumps += 1
            curr_end = far
    return jumps

arr = list(map(int, input().split()))
print(min_jumps(arr))
