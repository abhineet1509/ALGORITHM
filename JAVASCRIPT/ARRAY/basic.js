class ArrayOperations {

    printAlternate(arr) {
        console.log("Alternate elements:");
        for (let i = 0; i < arr.length; i += 2) {
            console.log(arr[i]);
        }
    }

    searchElement(arr, key) {
        for (let i = 0; i < arr.length; i++) {
            if (arr[i] === key)  // avoid wrong matches caused by type conversion
                return i;
        }
        return -1;
    }

    largestElement(arr) {
        let max = arr[0];
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    reverseArray(arr) {
        let left = 0, right = arr.length - 1;
        while (left < right) {
            [arr[left], arr[right]] = [arr[right], arr[left]];
            left++;
            right--;
        }
        return arr;
    }

    isSorted(arr) {
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
}

// -------- MAIN --------
let arr = [10, 20, 15, 40, 50];
let obj = new ArrayOperations();

obj.printAlternate(arr);

console.log("Index of 15:", obj.searchElement(arr, 15));
console.log("Largest element:", obj.largestElement(arr));
console.log("Reversed array:", obj.reverseArray([...arr]));
console.log("Is array sorted:", obj.isSorted(arr));


let x = 5       // number
x = "hello"    // now string (allowed)
