def trap(arr):
    l, r = 0, len(arr)-1
    left_max = right_max = 0
    water = 0
    while l < r:
        if arr[l] < arr[r]:
            left_max = max(left_max, arr[l])
            water += left_max - arr[l]
            l += 1
        else:
            right_max = max(right_max, arr[r])
            water += right_max - arr[r]
            r -= 1
    return water

arr = list(map(int, input().split()))
print(trap(arr))
