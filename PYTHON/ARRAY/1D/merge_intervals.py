def subarray_sum(arr, k):
    mp = {0:1}
    s = count = 0
    for x in arr:
        s += x
        count += mp.get(s-k, 0)
        mp[s] = mp.get(s, 0) + 1
    return count

arr = list(map(int, input().split()))
k = int(input())
print(subarray_sum(arr, k))
