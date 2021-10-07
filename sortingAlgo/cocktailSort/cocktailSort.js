function cocktailSort(array) {

  var n = array.length;

  var isSorted = false;

  while (!isSorted) {
    isSorted = true;

    for (var i = 0; i < n - 1; i++) {
      if (array[i] > array[i + 1]) {
        var temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        isSorted = false;
      }
    }

    if (isSorted) {
      break;
    }

    isSorted = true;

    for (var j = n - 1; j > 0; j--) {
      if (array[j - 1] > array[j]) {
        var temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        isSorted = false;
      }
    }
  }

  return array;
}
