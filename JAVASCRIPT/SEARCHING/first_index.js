let arr = [1,2,3,5,5,5,6,7,8]
let key = 5

let start = 0, end = arr.length - 1
let ans = -1

while (start <= end) {
    let mid = Math.floor((start + end) / 2)

    if (arr[mid] === key) {
        ans = mid          // store answer
        end = mid - 1      // move left to find FIRST
    } 
    else if (arr[mid] > key) {
        end = mid - 1
    } 
    else {
        start = mid + 1
    }
}

console.log(ans) // 3

function firstIndex(arr, key) {
    let start = 0, end = arr.length - 1
    let ans = -1

    while (start <= end) {
        let mid = Math.floor((start + end) / 2)

        if (arr[mid] === key) {
            ans = mid
            end = mid - 1   // move left
        } 
        else if (arr[mid] > key) {
            end = mid - 1
        } 
        else {
            start = mid + 1
        }
    }
    return ans
}
