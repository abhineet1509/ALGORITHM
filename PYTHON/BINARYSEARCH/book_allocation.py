def isPossible(pages, students, mid):
    count = 1
    pages_sum = 0

    for p in pages:
        if p > mid:
            return False
        if pages_sum + p <= mid:
            pages_sum += p
        else:
            count += 1
            pages_sum = p
            if count > students:
                return False
    return True

def bookAllocation(pages, students):
    if students > len(pages):
        return -1

    low, high = max(pages), sum(pages)
    ans = -1

    while low <= high:
        mid = (low + high) // 2
        if isPossible(pages, students, mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans
