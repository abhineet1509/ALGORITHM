def missing(arr, n):
    return n*(n+1)//2 - sum(arr)

arr = list(map(int, input().split()))
n = int(input())
print(missing(arr, n))
