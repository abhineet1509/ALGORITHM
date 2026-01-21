function binarySearch(arr, target) {
    let low = 0, high = arr.length - 1; //must do n-1

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);

        if (arr[mid] === target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
let arr = [1, 3, 5, 7, 9, 11];
console.log(binarySearch(arr, 7)); // 3



function binarySearchRec(arr, target, low = 0, high = arr.length - 1) {
    if (low > high) return -1;

    let mid = Math.floor((low + high) / 2);

    if (arr[mid] === target) return mid;
    if (arr[mid] < target)
        return binarySearchRec(arr, target, mid + 1, high);
    else
        return binarySearchRec(arr, target, low, mid - 1);
}

let brr = [1, 3, 5, 7, 9, 11];
console.log(binarySearchRec(brr, 7)); // 3


let arr1 = [1,2,3,4,5,6,7,8]
let key = 5

let start = 0, end = arr.length - 1
let found = -1

while (start <= end) {
    let mid = Math.floor((start + end) / 2)

    if (arr1[mid] === key) {
        found = mid
        break            
    } 
    else if (arr1[mid] > key) {
        end = mid - 1
    } 
    else {
        start = mid + 1
    }
}

console.log(found)
