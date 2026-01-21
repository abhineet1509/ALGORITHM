// Union of 2 arrays using different methods
let arr1 = [1, 2, 3];
let arr2 = [3, 4, 5];

// Method 1: Using Set
let unionSet = [...new Set([...arr1, ...arr2])];  // set is not actually an array so return ...new
console.log("Union of 2 arrays (Set):", unionSet);

// Method 2: Using loop + includes
let unionLoop = [...arr1];
for (let el of arr2) {
    if (!unionLoop.includes(el)) {
        unionLoop.push(el);
    }
}
console.log("Union of 2 arrays (Loop):", unionLoop);

// Method 3: Using Map/Object
let mapUnion = {};
for (let el of arr1) mapUnion[el] = true;
for (let el of arr2) mapUnion[el] = true;
let unionMap = Object.keys(mapUnion).map(Number);
console.log("Union of 2 arrays (Map/Object):", unionMap);


// Union of 3 arrays
let arr3 = [5, 6, 7];

// Method 1: Using Set
let union3Set = [...new Set([...arr1, ...arr2, ...arr3])];
console.log("Union of 3 arrays (Set):", union3Set);

// Method 2: Using Map/Object
let mapUnion3 = {};
for (let arr of [arr1, arr2, arr3]) {
    for (let el of arr) {
        mapUnion3[el] = true;
    }
}
let union3Map = Object.keys(mapUnion3).map(Number);
console.log("Union of 3 arrays (Map/Object):", union3Map);
