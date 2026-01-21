def nthRoot(n, m):
    low, high = 1, m

    while low <= high:
        mid = (low + high) // 2
        power = mid ** n

        if power == m:
            return mid
        elif power < m:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def sqrtBinary(n):
    low, high = 0, n
    ans = 0

    while low <= high:
        mid = (low + high) // 2
        if mid * mid <= n:
            ans = mid
            low = mid + 1
        else:
            high = mid - 1
    return ans
