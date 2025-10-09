
import java.util.*;


class bucketSort {


    static void bucketSort(int arr[], int n)
    {
        if (n <= 0)
            return;


        @SuppressWarnings("unchecked")
        Vector<Float>[] buckets = new Vector[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new Vector<Float>();
        }


        int max = Arrays.stream(arr).max().getAsInt();  // find max element
        for (int i = 0; i < n; i++) {
            int idx = (arr[i] * n) / (max + 1); // bucket index 0..n-1
            buckets[idx].add((float) arr[i]);
        }

        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }


        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i].get(j).intValue();
            }
        }
    }


    public static void main(String args[])
    {
        int arr[] = {10,14,8,78,4,66,542,22,14};

        int n = arr.length;
        bucketSort(arr, n);

        System.out.println("Sorted array is ");
        for (int el : arr) {
            System.out.print(el + " ");
        }
    }
}


