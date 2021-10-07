function cocktailSort(arr) {
  //Swapped is our conditional to check if everything is sorted
  let start = 0, end = arr.length, swapped = true;

  while (swapped) {
    //Setting the flag to false, in case it is true from the previous iteration
    swapped = false;

    //Bubble sort from the left side of the array to the right
    for (let i = start; i < end - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        let temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }

    //This is to update the end, so that next iteration, we don't have to check this index.
    end--;

    //If everything is already sorted, we can break out of the loop early.
    if (!swapped) {
      break;
    }

    //Setting the flag to false, so it can be used for the next phase
    swapped = false;

    //Reverse Bubble sort, moving the smallest to the front.
    for (let i = end - 1; i > start; i--) {
      if (arr[i - 1] > arr[i]) {
        let temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        swapped = true;
      }
    }

    //This is to update the beginning, so that next iteration, we don't have to check this index.
    start++;
  }

  return arr;
}
