# using set
def find_duplicate(arr):
    seen = set()
    for x in arr:
        if x in seen:
            return x
        seen.add(x)
    return -1

arr = list(map(int, input().split()))
print(find_duplicate(arr))

#using set
def find_all_duplicates(arr):
    seen = set()
    duplicates = set()

    for x in arr:
        if x in seen:
            duplicates.add(x)
        else:
            seen.add(x)

    return list(duplicates)

#using dictionary
def find_duplicate(arr):
    freq = {}
    for x in arr:
        freq[x] = freq.get(x, 0) + 1
        if freq[x] > 1:
            return x
    return -1

#using dictionary ( find all duplicate )
def find_all_duplicates(arr):
    freq = {}
    duplicates = []

    for x in arr:
        freq[x] = freq.get(x, 0) + 1

    for key, value in freq.items():
        if value > 1:
            duplicates.append(key)

    return duplicates

#using sorting
def find_duplicate(arr):
    arr.sort()
    for i in range(len(arr)-1):
        if arr[i] == arr[i+1]:
            return arr[i]
    return -1

# remove duplicates while keeping the order
def remove_dup(arr):
    return list(dict.fromkeys(arr))

arr = list(map(int, input().split()))
print(remove_dup(arr))
