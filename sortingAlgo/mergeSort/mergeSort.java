public class mergeSort {
    public static void merge(int[] array_1, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = 0;

        int[] array_2 = new int[high - low + 1];

	    while(i <= mid && j <= high) {
		    if(array_1[i] <= array_1[j]) {
			    array_2[k] = array_1[i];
			    k += 1; i += 1;
		    }
		    else {
			    array_2[k] = array_1[j];
			    k += 1; j += 1;
		    }
	    }
 
	    while(i <= mid) {
		    array_2[k] = array_1[i];
		    k += 1; i += 1;
	    }

	    while(j <= high) {
		    array_2[k] = array_1[j];
		    k += 1; j += 1;
	    }

	    for(i = low; i <= high; i += 1) {
		    array_1[i] = array_2[i - low];
	    }
    }

    public static void sort(int[] array, int low, int high) {
        if(low < high) {
            int mid = (low + high) / 2;
            sort(array, low, mid);
            sort(array, mid + 1, high);
            merge(array, low, mid, high);
        }  
    }      
}
