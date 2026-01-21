def rotate(arr, k):
    k %= len(arr)
    return arr[-k:] + arr[:-k]

arr = list(map(int, input().split()))
k = int(input())
print(rotate(arr, k))
