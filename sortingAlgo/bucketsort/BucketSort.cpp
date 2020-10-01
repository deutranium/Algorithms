// Bucket Sort in cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<float> vec) {
   for(int i = 0; i<vec.size(); i++) {
      cout << vec[i] << " ";
   }
   cout << "\n";
}

void bucketSort(vector<float>&vec) {
   int size = vec.size();
   vector<float> bucket[size];

   // put elements into different buckets
   for(int i = 0; i<size; i++)  {          
      bucket[int(size * vec[i])].push_back(vec[i]);
   }

   //sort individual vectors
   for(int i = 0; i<size; i++) {
      sort(bucket[i].begin(), bucket[i].end());       
   }
   
   int index = 0;
   for(int i = 0; i < size; i++) {
      for (int j = 0; j < bucket[i].size(); j++) {
         vec[index++] = bucket[i][j]; 
      }
   }
}

int main() {
   
   vector<float> v(10);
   v = {0.542, 0.512, 0.761, 0.123, 0.541, .0981, 0.841, 0.01, 0.7, 0.901};
   
   cout << "Array before Sorting: ";
   print_vec(v);
   bucketSort(v);
   
   cout << "Array after Sorting: ";
   print_vec(v);
}
