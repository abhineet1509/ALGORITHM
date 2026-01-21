#last occurence
def first_occurrence(arr, key):
    l, r = 0, len(arr)-1
    ans = -1
    while l <= r:
        mid = (l+r)//2
        if arr[mid] == key:
            ans = mid
            r = mid - 1
        elif arr[mid] < key:
            l = mid + 1
        else:
            r = mid - 1
    return ans

arr = list(map(int, input().split()))
key = int(input())
print(first_occurrence(arr, key))

#last occurence
def last_occurrence(arr, key):
    l, r = 0, len(arr)-1
    ans = -1
    while l <= r:
        mid = (l+r)//2
        if arr[mid] == key:
            ans = mid
            l = mid + 1
        elif arr[mid] < key:
            l = mid + 1
        else:
            r = mid - 1
    return ans

arr = list(map(int, input().split()))
key = int(input())
print(last_occurrence(arr, key))

#count occurence
def count_occurrence(arr, key):
    def first():
        l, r, ans = 0, len(arr)-1, -1
        while l <= r:
            mid = (l+r)//2
            if arr[mid] >= key:
                r = mid - 1
            else:
                l = mid + 1
            if arr[mid] == key:
                ans = mid
        return ans

    def last():
        l, r, ans = 0, len(arr)-1, -1
        while l <= r:
            mid = (l+r)//2
            if arr[mid] <= key:
                l = mid + 1
            else:
                r = mid - 1
            if arr[mid] == key:
                ans = mid
        return ans

    f, l = first(), last()
    return 0 if f == -1 else l - f + 1

arr = list(map(int, input().split()))
key = int(input())
print(count_occurrence(arr, key))
