// Pigeonhole_Sort Algorithm

function SortPigeonhole(input){

        let n=input.length;
        // Find minimum and maximum values in input[]
        let min = input[0], max = input[0];
        for (var i = 1; i < n; i++)
        {
            if (input[i] < min) min = input[i];
            if (input[i] > max) max = input[i];
        }
       
        let range = max - min + 1;// Find range
        var holes =[range];

         for(var i = 0; i < n; i++) {
                   holes[i] = 0; 

         }
            
         // Traverse through input array and put every 
         // element in its respective hole 
         for(var i = 0; i < n; i++) 
            holes[input[i] - min]++; 
  
        // Traverse through all holes one by one. For 
        // every hole, take its elements and put in 
        // array. 
  
        var i=0;  // index in sorted array 
        for(var j = 0; j < range; j++) {
        
            while(holes[j]>0){
            
                holes[j] -= 1;
                input[i] = j+min;
                i += 1;
            }

        }               
 }

 function display(){
    let input=[1, 3, 2, 7,  
                   4, 6, 11];
    SortPigeonhole(input);
    console.log("Element after sort :")
  
    for(var i=0;i<input.length;i++){
              console.log(input[i]);
    }
  
  }
  
  /* for input 1,3,2,7,4,6,11
   * output is 1 2 3 4 6 7 11
   * time complexity
   *-Worst-case Complexity:O(N+n)
   *-Worst-case Space Complexity:O(N+n)
  */