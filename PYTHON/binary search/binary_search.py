# def binary_search(nums,n):
#      left = 0
#      right = len(nums)-1
#      while(left<right):
#           mid = (left+right)//2
#           if nums[mid] == n:
#                return mid
#           elif nums[mid] < n:
#                left = mid+1
#           else:
#                right = mid-1
#                return -1
def binary_search(arr, target, low, high):
    if low > high:
        return -1  
    
    mid = (low + high) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search(arr, target, mid + 1, high)
    else:
        return binary_search(arr, target, low, mid - 1)

nums = [1,2,3,4,5,6,7,8,9]
print(binary_search(nums,5,0,len(nums)-1)) # Output: 4
