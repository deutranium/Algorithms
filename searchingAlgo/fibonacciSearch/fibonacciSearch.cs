using System;

class MainClass {
  public static void Main (string[] args) {
    Console.WriteLine("How big will be the array?");
    int arrayLength = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine();
    int [] array = new int[arrayLength];
    int i;
    for (i=0; i<arrayLength; i++) {
      array[i] = Convert.ToInt32(Console.ReadLine());
    }
    Console.WriteLine("\nWhat's the number you are looking for?");
    int searchedNumber = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine($"Number found at index: {FibonacciSearch(array, searchedNumber, arrayLength)}.");
  }

  public static int RecursiveFibonacci(int n) {
    if (n == 1) {
      return 0;
    } else if ( n == 2 ) {
      return 1;
    } else {
      return RecursiveFibonacci(n-1) + RecursiveFibonacci(n-2);
    }
  }

  public static int FibonacciSearch(int []array, int searchedNumber, int arrayLength) {
    int counter = 1;
    while (RecursiveFibonacci(counter) < arrayLength) {
      counter++;
    }
    int offset = -1;

    while (RecursiveFibonacci(counter) > 1) {
      int index = Math.Min(offset+RecursiveFibonacci(counter-2), arrayLength-1);

      if (array[index] < searchedNumber) {
        counter--;
        offset = index;
      } else if (array[index] > searchedNumber) {
        counter -= 2;
      } else return index;
    }

    if (RecursiveFibonacci(counter-1) == 1 && array[offset-1] == searchedNumber) {
      return offset + 1;
    } else return -1;
  }
}
