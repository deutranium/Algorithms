class QuickSort
{
  static int Partition(int[] array, int low,
                                  int high)
  {
    // Select a pivot point.
    int pivot = array[high];

    int lowIndex = (low - 1);

    // Reorder the collection.
    for (int j = low; j < high; j++)
    {
      if (array[j] <= pivot)
      {
        lowIndex++;

        int temp = array[lowIndex];
        array[lowIndex] = array[j];
        array[j] = temp;
      }
    }

    int temp1 = array[lowIndex + 1];
    array[lowIndex + 1] = array[high];
    array[high] = temp1;

    return lowIndex + 1;
  }

  static void Sort(int[] array, int low, int high)
  {
    if (low < high)
    {
      int partitionIndex = Partition(array, low, high);

      // Recursively continue sorting the array
      Sort(array, low, partitionIndex - 1);
      Sort(array, partitionIndex + 1, high);
    }
  }

  public static void Main()
  {
    int[] array = { 72, 12, 6, 33, 81, 97, 37, 59, 52, 1, 20 };
    int length = array.Length;

    Console.WriteLine("QuickSort");
    CommonFunctions.PrintInitial(array);
    Sort(array, 0, length - 1);

    CommonFunctions.PrintFinal(array);

    Console.ReadKey();
  }
}
