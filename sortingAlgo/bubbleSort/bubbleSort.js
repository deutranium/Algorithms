// This function will return the sorted array given in arguments!

function bubbleSort(arr) {
    for(let i = 0; i < arr.length; i++) {
        for(let j = 0; j < arr.length; j ++) {
            let pos1 = arr[j];
            let pos2 = arr[j+1];

            if(arr[j] > arr[j+1]) {
                arr[j+1] = pos1;
                arr[j] = pos2;
            }
        }
        return arr;
    }
}
console.log(bubbleSort([4, 5, 9, 3])); // Output: 9
