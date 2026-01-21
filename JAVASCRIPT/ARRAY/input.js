// JavaScript itself has no standard way to read input from the user outside a browser or Node.js.
// If you’re running JS in VS Code without Node.js, the only ways to “take input” are:
// browser console
// Use HTML + browser environment
// Use Node.js modules

//Ask user to enter elements separated by commas
let input = prompt("Enter numbers separated by commas:");

// Convert string to array
let arr = input.split(",").map(Number); // convert strings to numbers
console.log(arr);


{/* <input type="text" id="arrInput" placeholder="Enter elements separated by commas">
<button onclick="getArray()">Submit</button>

<script>
function getArray() {
    let input = document.getElementById("arrInput").value;
    let array = input.split(","); // convert to array
    let numArray = array.map(Number); // optional: convert to numbers
    console.log(numArray);
    alert("Array: " + numArray);
}
</script> */}

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
 // The .question() method is a function on that object that lets you ask the user for input.
rl.question("Enter array elements separated by commas: ", function(input) {
    let array = input.split(","); // split into array of strings
    let numArray = array.map(Number); // convert to numbers
    console.log("Array:", numArray);
    rl.close();
});
