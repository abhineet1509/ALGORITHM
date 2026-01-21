def binary_search(arr, key):
    l, r = 0, len(arr)-1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            l = mid + 1
        else:
            r = mid - 1
    return -1

arr = list(map(int, input().split()))
key = int(input())
print(binary_search(arr, key))
