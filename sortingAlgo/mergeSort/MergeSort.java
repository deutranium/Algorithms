class Hacktoberfest
{

   static void mergeS(int arr[],int l,int m,int r)
   {
      int n1 = m - l + 1;
      int n2 = r - m;

      int A[] = new int [n1]; // Create temp arrays 
      int B[] = new int [n2]; // Create temp arrays 

      
      for (int i=0; i<n1; ++i){
         A[i] = arr[l + i];
      }
      for (int j=0; j<n2; ++j){
         B[j] = arr[m + 1+ j];
      }
      int i = 0, j = 0;
      int k = l;
      while (i < n1 && j < n2)
      {
         if (A[i] <= B[j])
         {
            arr[k] = A[i];
            i++;
         }
         else
         {
            arr[k] = B[j];
            j++;
         }
         k++;
      }

      /* Copy remaining elements of A[] if any */
      while (i < n1)
      {
         arr[k] = A[i];
         i++;
         k++;
      }

      /* Copy remaining elements of B[] if any */
      while (j < n2)
      {
         arr[k] = B[j];
         j++;
         k++;
      }
   }

   static void merge(int array[], int left, int right)
   {
      if (left < right)
      {
         
         int mid = (left+right)/2;//the middle point

         merge(array,left,mid); // Divide into two half
         merge(array,mid+1,right);

         mergeS(array,left,mid,right); // merging Two Sorted Half
      }
   }

   public static void main(String args[])
   {
      int array[] = {2,5,6,4,3,2,1};
      int left=0;
      int n=array.length-1;
      merge(array,left,n);

      // Printing Array
      for (int i = 0; i <= n; ++i)
      {
         System.out.print(array[i]+" ");
      }
      System.out.println();
   }
}

