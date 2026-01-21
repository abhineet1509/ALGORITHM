
# maximum element
arr = list(map(int, input().split()))
mx = arr[0]
for x in arr:
    if x > mx:
        mx = x
print(mx)

# reverse an array
arr = list(map(int, input().split()))
n = len(arr)
for i in range(n // 2):
    arr[i], arr[n - i - 1] = arr[n - i - 1], arr[i]
print(arr)

#sum of array
arr = list(map(int, input().split()))
s = 0
for x in arr:
    s += x
print(s)

#second largest
arr = list(map(int, input().split()))
first = second = -10**9
for x in arr:
    if x > first:
        second = first
        first = x
    elif x > second and x != first:
        second = x
print(second)

#remove duplicates
arr = list(map(int, input().split()))
res = []
for x in arr:
    if x not in res:
        res.append(x)
print(res)

# frequency of each element
arr = list(map(int, input().split()))
freq = {}
for x in arr:
    freq[x] = freq.get(x, 0) + 1
print(freq)
# swap using temp variable
a, b = map(int, input().split())
a, b = b, a
print(a, b)
