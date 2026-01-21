function findPeakElement(nums) {
    for (let i = 0; i < nums.length; i++) {
        if ((i === 0 || nums[i] >= nums[i - 1]) &&
            (i === nums.length - 1 || nums[i] >= nums[i + 1])) {
            return i; // return index of peak element
        }
    }
}

let arr = [1, 3, 20, 4, 1, 0];
console.log("Peak index:", findPeakElement(arr)); // could be 2 (element 20)


function majorityElement(nums) {
    const count = {};
    for (let num of nums) {
        count[num] = (count[num] || 0) + 1;
        if (count[num] > nums.length / 2) {
            return num;
        }
    }
    return null; // no majority element
}

let arr2 = [2, 2, 1, 2, 3, 2, 2];
console.log("Majority element:", majorityElement(arr2)); // 2


function twoSum(nums, target) {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (map.has(complement)) {
            return [map.get(complement), i]; // return indices
        }
        map.set(nums[i], i);
    }
    return [];
}

let arr3 = [2, 7, 11, 15];
let target = 9;
console.log("Two sum indices:", twoSum(arr3, target)); // [0, 1]


if ("hello") console.log("Truthy!"); // prints "Truthy!"
if (42) console.log("Truthy!");      // prints "Truthy!"
if ([]) console.log("Truthy!");      // prints "Truthy!" (empty array is truthy)
if ({}) console.log("Truthy!");      // prints "Truthy!" (empty object is truthy)
if (function(){}) console.log("Truthy!"); // functions are truthy

if (false) console.log("This won't print");
if (0) console.log("This won't print");
if (-0) console.log("This won't print");
if (0n) console.log("This won't print");
if ("") console.log("This won't print"); // empty string
if (null) console.log("This won't print");
if (undefined) console.log("This won't print");
if (NaN) console.log("This won't print");
