/*
In mathematics, the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.

It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the first prime number, 2. 
The multiples of a given prime are generated as a sequence of numbers starting from that prime, with constant difference between them 
that is equal to that prime.[1] This is the sieve's key distinction from using trial division to sequentially test each candidate number 
for divisibility by each prime.[2] Once all the multiples of each discovered prime have been marked as composites, the remaining unmarked
numbers are primes.

Algorithm:
1) Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2) Initially, let p equal 2, the smallest prime number.
3) Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them in the list (these will be 2p, 3p, 4p, ...; 
   the p itself should not be marked).
4) Find the smallest number in the list greater than p that is not marked. If there was no such number, stop. Otherwise, let p now equal 
   this new number (which is the next prime), and repeat from step 3.
5) When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.

Source : https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/ 


import java.util.*;

class driver{
    public static void main(String[] args) {
        int MAX = 1000;                                    // setting upper limit => Sieve generates prime numbers in [1, MAX]

        boolean isPrime[] = new boolean[MAX + 1];          // List of numbers 
        Arrays.fill(isPrime, true);                        // assuming all numbers to be prime

        isPrime[0] = false;                                // 0 is not a prime number hence eliminating it at first
        isPrime[1] = false;                                // 1 is not a prime number hence eliminating it at first

        for(int i = 2; i * i <= MAX; i++) {                // search space is from [2 : sqrt(MAX)]    => where sqrt = square root
            if(isPrime[i]) {
                for(int j = i * i; j <= MAX; j += i) {     // this generates all multiples of i starting from i*i. All previous multiples of i have already been checked
                    isPrime[j] = false;                    // removes the multiples of i from the prime list
                }
            }
        }

        for(int i = 0; i <= MAX; i++) {                    // iterating over isPrime vector
            if(isPrime[i]) {                               // if isPrime[i] is true, it means that i is a prime number
                System.out.println(i);                     // prints i
            }
        }

    }
}

/*
TIme Complexity : O(nlog(logn))
Space Complexity : O(n)
*/