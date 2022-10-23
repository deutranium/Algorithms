function kadanesAlgorithm(arr) {
  var max_current = arr[0];
  var max_global = arr[0];
  var size = arr.length;

  for (var i = 0; i < size; i++) {
    max_current = Math.max(arr[i], max_current + arr[i]);
    max_global = Math.max(max_global, max_current);
  }
  return max_global;
}

var a = [-2, -3, 4, 1, -2, 1, 6, -2];
//var a = [-2, 3, 2, -1];
console.log("Maximum contiguous sum is : " + kadanesAlgorithm(a));
document.write("Maximum contiguous sum is : " + kadanesAlgorithm(a));
