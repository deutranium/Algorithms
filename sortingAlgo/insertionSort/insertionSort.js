function insertionSort(inputArr) {

  let n = inputArr.length;

  for (let i = 1; i < n; i++) {
    // Choosing the first element in the unsorted subarray
    let current = inputArr[i];

    // The last element of the sorted subarray
    let j = i - 1;

    while ((j > -1) && (current < inputArr[j])) {
      inputArr[j + 1] = inputArr[j];
      j--;
    }

    inputArr[j + 1] = current;
  }

  return inputArr;
}

let inputArr = [5, 2, 4, 6, 1, 3];

insertionSort(inputArr);

console.log(inputArr);
