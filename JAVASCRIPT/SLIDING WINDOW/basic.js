const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function subarraySumZero(arr) {
    let set = new Set();
    let sum = 0;
    for (let num of arr) {
        sum += num;
        if (num === 0 || sum === 0 || set.has(sum)) return true;
        set.add(sum);
    }
    return false;
}

function subarraySumK(arr, k) {
    let map = new Map();
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
        if (sum === k || map.has(sum - k)) return true;
        map.set(sum, i);
    }
    return false;
}

function countSubarraysSumZero(arr) {
    let map = new Map();
    let sum = 0, count = 0;
    map.set(0, 1);
    for (let num of arr) {
        sum += num;
        if (map.has(sum)) count += map.get(sum);
        map.set(sum, (map.get(sum) || 0) + 1);
    }
    return count;
}

function maxSubarraySum(arr) {
    let maxEnding = arr[0], maxSoFar = arr[0];
    for (let i = 1; i < arr.length; i++) {
        maxEnding = Math.max(arr[i], maxEnding + arr[i]);
        maxSoFar = Math.max(maxSoFar, maxEnding);
    }
    return maxSoFar;
}

function minSubarraySum(arr) {
    let minEnding = arr[0], minSoFar = arr[0];
    for (let i = 1; i < arr.length; i++) {
        minEnding = Math.min(arr[i], minEnding + arr[i]);
        minSoFar = Math.min(minSoFar, minEnding);
    }
    return minSoFar;
}

function subarrayWithSumK(arr, k) {
    let map = new Map();
    let sum = 0;
    map.set(0, -1);
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
        if (map.has(sum - k)) {
            let start = map.get(sum - k) + 1;
            return arr.slice(start, i + 1);
        }
        map.set(sum, i);
    }
    return [];
}

// Input array
rl.question("Enter array elements separated by commas: ", function(input) {
    let arr = input.split(",").map(Number);

    // Input k for subarray sum k
    rl.question("Enter value of k: ", function(kInput) {
        let k = Number(kInput);

        console.log("\n=== Subarray Problems ===\n");

        console.log("Array:", arr);
        console.log("k:", k);

        console.log("\n1. Subarray with sum 0 exists:", subarraySumZero(arr));
        console.log("2. Subarray with sum k exists:", subarraySumK(arr, k));
        console.log("3. Count of subarrays with sum 0:", countSubarraysSumZero(arr));
        console.log("4. Maximum subarray sum:", maxSubarraySum(arr));
        console.log("5. Minimum subarray sum:", minSubarraySum(arr));
        console.log("6. Subarray with sum k:", subarrayWithSumK(arr, k));

        rl.close();
    });
});
