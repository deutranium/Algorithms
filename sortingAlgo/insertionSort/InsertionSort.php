<?php

function insertionSort(&$arr, $n)
{
   for ($i = 1; $i < $n; $i++)
   {
      $key = $arr[$i];
      $j = $i-1;
   
      // Move elements of arr[0..i-1],
      // that are greater than key, to
      // one position ahead of their
      // current position
      while ($j >= 0 && $arr[$j] > $key)
      {
         $arr[$j + 1] = $arr[$j];
         $j = $j - 1;
      }
      
      $arr[$j + 1] = $key;
   }
}

function printArray(&$arr, $n)
{
   for ($i = 0; $i < $n; $i++)
      echo $arr[$i]." ";
   echo "\n";
}

$arr = array(1,2,9,8,3,4);
$n = sizeof($arr);

insertionSort($arr, $n);
printArray($arr, $n);

?>

