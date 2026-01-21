let arr = [1,2,3,4,5,6]
let  max = arr[0]
for(let i = 0;i<arr.length;i++){
    if(arr[i]>max) max = arr[i]
}
console.log(max)
let secondMax = arr[0]
for(let i = 0;i<arr.length;i++){
    if(arr[i]>secondMax && arr[i]!==max) secondMax = arr[i]
}
console.log(secondMax)