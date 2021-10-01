// Cycle sort function
function cycleSort(arr) {
  let writes = 0;
  const n = arr.length;
  // traverse array elements
  for (let cycleStart = 0; cycleStart <= n - 2; cycleStart++) {
    item = arr[cycleStart];
    // Find position where the item should be.
    // counting all the smaller elements on the right side of the current item.
    pos = cycleStart;
    for (i = cycleStart + 1; i < n; i++) {
      if (arr[i] < item) pos++;
    }
    // If item is already in correct position just continue
    if (pos == cycleStart) {
      continue;
    }
    // ignore all duplicate elements
    while (item == arr[pos]) {
      pos += 1;
    }
    // put the item to it's right position
    if (pos != cycleStart) {
      temp = item;
      item = arr[pos];
      arr[pos] = temp;
      writes++;
    }

    // Rotate rest of the cycle
    while (pos != cycleStart) {
      pos = cycleStart;
      // Find position where we put the element
      for (i = cycleStart + 1; i < n; i++) {
        if (arr[i] < item) pos += 1;
      }
      // ignore all duplicate elements
      while (item == arr[pos]) {
        pos += 1;
      }
      // put the item to it's right position
      if (item != arr[pos]) {
        temp = item;
        item = arr[pos];
        arr[pos] = temp;
        writes++;
      }
    }
  }
  return arr;
}

function main() {
  const arr = [11, 8, 23, 5, 10, 12, 2, 14, 11, 9, 4, 4, 6, 24];
  console.log("Before sort:", arr.join(","));
  result = cycleSort(arr);
  console.log("After sort:", result.join(","));
}

main();
