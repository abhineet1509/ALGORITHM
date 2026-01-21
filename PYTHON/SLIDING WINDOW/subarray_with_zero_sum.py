def zero_sum(arr):
    s = 0
    seen = set()
    for x in arr:
        s += x
        if s == 0 or s in seen:
            return True
        seen.add(s)
    return False

arr = list(map(int, input().split()))
print(zero_sum(arr))
