/**
 * Java implementation of Fermat's primality test
 * Execute this file with: java FermatMethod.java
 * @author juanmagutierrez89
 */
public class FermatMethod {
    
    /**
     * This function calculates and returns: (a^b) % mod
     * @param a base number
     * @param b exp number
     * @param mod mod number
     * @return (a^b) % mod
     */   
    static int modpower(int a,int n, int p) { 
        // Initialize result 
        int res = 1; 
          
        // Update 'a' if 'a' >= p 
        a = a % p;  
      
        while (n > 0) { 
            // If n is odd, multiply 'a' with result 
            if ((n & 1) == 1) {
                res = (res * a) % p; 
            }
      
            // n must be even now 
            n = n >> 1; // n = n/2 
            a = (a * a) % p; 
        } 
        return res; 
    } 
    
    /**
     * This function calculates GDC of two numbers 
     * GDC: Greatest Common Divisor
     * If this number is 1, then both numbers are Coprime.
     * @param a
     * @param b
     * @return 
     */
    public static int gcd(int a, int b) { 
        if (a < b) {
            return gcd(b, a); 
        } else if (a%b == 0) {
            return b; 
        } else {
            return gcd(b, a%b);
        }   
    } 

    /**
     * This function determines if a number is prime using Fermat's theorem:
     * If n is a prime number, then for every a, 1 < a < n-1, a^(n-1) ≡ 1 (mod n);
     * 
     * @param n a value to test for primality (n > 0)
     * @param k a parameter that determines the number of times to test for primality
     * @return 
     */
    public static boolean isPrime(int n, int k) {

        if (n <= 1 || n == 4) {
            return false;
        } else if (n <= 3) {
            return true;
        } 

        //Repeat k times:
        while(k > 0) {
            //Pick "a" randomly in the range [2, n − 2]
            int a = 2 + (int)(Math.random()%(n-4));   

            // If a and n are not co-primes then n is not prime
            if (gcd(a, n) != 1) {
                return false;
            }
            if (modpower(a, n-1, n) != 1) { 
                return false; 
            }
            
            k--;
        }
        return true; 
    }

    public static void main(String[] args) {
        System.out.println("isPrime(7 , 4): "+isPrime(7 , 4));
        System.out.println("isPrime(9 , 4): "+isPrime(9 , 4));
        System.out.println("isPrime(16 , 4): "+isPrime(16 , 4));
        System.out.println("isPrime(31 , 4): "+isPrime(31 , 4));
        System.out.println("isPrime(101 , 4): "+isPrime(101 , 4));
        System.out.println("isPrime(237 , 4): "+isPrime(237 , 4));
        System.out.println("isPrime(547 , 4): "+isPrime(547 , 4));
        System.out.println("isPrime(1319 , 4): "+isPrime(1319 , 4));
    }

}