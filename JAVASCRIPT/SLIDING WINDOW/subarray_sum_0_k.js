function subarraysWithSumZero(arr) {
    let map = new Map(); // prefix sum -> list of indices
    let sum = 0;
    let result = [];

    // Initialize with sum 0 at index -1 to handle subarrays starting at index 0
    map.set(0, [-1]);

    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];

        if (map.has(sum)) {
            let indices = map.get(sum);
            for (let startIdx of indices) {
                result.push(arr.slice(startIdx + 1, i + 1)); // extract subarray
            }
            indices.push(i); // add current index
        } else {
            map.set(sum, [i]);
        }
    }

    return result;
}

// Example usage:
let arr = [1, 2, -3, 3, -1, -2];
console.log("All subarrays with sum 0:");
let zeroSubarrays = subarraysWithSumZero(arr);
for (let sub of zeroSubarrays) {
    console.log(sub);
}

function subarraysWithSumK(arr1, k) {
    let map = new Map(); // prefix sum -> list of indices
    let sum = 0;
    let result = [];

    // Initialize with sum 0 at index -1 to handle subarrays starting at index 0
    map.set(0, [-1]);

    for (let i = 0; i < arr1.length; i++) {
        sum += arr1[i];

        // Check if there is a prefix sum that equals (sum - k)
        if (map.has(sum - k)) {
            let indices = map.get(sum - k);
            for (let startIdx of indices) {
                result.push(arr.slice(startIdx + 1, i + 1)); // extract subarray
            }
        }

        // Add current index to the map
        if (map.has(sum)) {
            map.get(sum).push(i);
        } else {
            map.set(sum, [i]);
        }
    }

    return result;
}

// Example usage:
let arr1 = [1, 2, 3, 4, 2, -1];
let k = 5;

console.log(`All subarrays with sum ${k}:`);
let subarrays = subarraysWithSumK(arr1, k);
for (let sub of subarrays) {
    console.log(sub);
}
