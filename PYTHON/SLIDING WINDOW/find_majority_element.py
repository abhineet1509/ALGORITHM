def majority_element(arr):
    count = 0
    candidate = None
    for x in arr:
        if count == 0:
            candidate = x
        count += 1 if x == candidate else -1

    if arr.count(candidate) > len(arr)//2:
        return candidate
    return -1

arr = list(map(int, input().split()))
print(majority_element(arr))
