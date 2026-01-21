function floorCeil(arr, key) {
    let floor = -1, ceil = -1
    let low = 0, high = arr.length - 1

    while (low <= high) {
        let mid = Math.floor((low + high) / 2)

        if (arr[mid] === key) {
            floor = ceil = arr[mid]
            break
        }
        else if (arr[mid] < key) {
            floor = arr[mid]  //valid candidate for floor
            low = mid + 1
        }
        else {
            ceil = arr[mid]
            high = mid - 1
        }
    }
    return { floor, ceil }
}
console.log(floorCeil([1,2,4,6,8], 5))
// { floor: 4, ceil: 6 }
