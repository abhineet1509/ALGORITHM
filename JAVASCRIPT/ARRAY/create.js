 // Array literals
let arr = [1, 2, 3, 4];
console.log(arr); // [1, 2, 3, 4]

// array constructor
let brr = new Array(5); // creates an empty array of length 5
console.log(brr); // [ <5 empty items> ]

let brr2 = new Array(1, 2, 3);
console.log(brr2); // [1, 2, 3]

// Array form 
let str = "hello";
let crr = Array.from(str);
console.log(crr); // ['h', 'e', 'l', 'l', 'o']

//Array of 
let drr = Array.of(5); 
console.log(drr); // [5] — unlike `new Array(5)` which creates an empty array of length 5

let arr2 = Array.of(1, 2, 3);
console.log(arr2); // [1, 2, 3]

// Spread operator
let arr1 = [1, 2, 3];
let crr2 = [...arr1, 4, 5];
console.log(crr2); // [1, 2, 3, 4, 5]

// concatenate
let arr12 = [1, 2];
let arr22 = [3, 4];
let arr32 = arr1.concat(arr2);
console.log(arr3); // [1, 2, 3, 4]

// loop method
let arr6 = [];
for (let i = 0; i < 5; i++) {
  arr6.push(i * 2);
}
console.log(arr6); // [0, 2, 4, 6, 8]
