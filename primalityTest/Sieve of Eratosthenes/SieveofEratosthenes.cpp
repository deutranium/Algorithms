/*The Sieve of Eratosthenes finds its application in generating all prime numbers up to a particular number. The 
prime numbers do not have factors other than one and themselves. We try to exploit the property in reverse order
 i.e. number having more than 2 factors is not a prime number.
 We follow the given steps to do this.
 1.Assume all numbers are prime.
 2.Mark 0 and 1 as non primes.
 3.From 2 to n we iterare and mark all the multiples of these numbers are non prime.(As they have atleast factors now(1,themselves and this number))
 4.For easing out our task we are not going for multiples of numbers marked as non primes as they would have been alraedy dealt by its factors.
    for example: 2 will knock down 4,6,8,10,12,14,16,18,20.
    So we don't need to check for 4 as 2 has already knocked down its multiples.
 5.At the end we will be left with only prime values that are marked as prime.
 ***************************************************************************************************************************************************
 TIME COMPLEXITY: O(N*logN*logN)                          for proof refer this:https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
 SPACE COMPLEXITY:O(N)
 ***************************************************************************************************************************************************
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=100;                                             // defining higher limit, generate prime numbers in range[1:100]
    vector<bool> checkprime(n+1,true);                     // assuming all the numbers are prime numbers
    vector<int> prime;                                     // vector for storing all the prime numbers
    checkprime[0]=false;                                   // knocking out 0 and 1 from the list of prime numbers
    checkprime[1]=false;                                   // starting our search for prime numbers from [2:n]
    for(int i=2;i<=n;i++)
    {
        if(checkprime[i]==true)                             // We will check only those which are not knocked out yet.(POINT 4)
        {
            for(int j=2*i;j<=n;j+=i)                        // this will generate all the multiples of i upto n. 2*i will be the smallest multiple.
            {
                checkprime[j]=false;                        // knocking out the multiples from pt=rime list
            }
        }
    }                              
    for(int i=0;i<n+1;i++)                                   // iterating over checkprime vector
    {
        if(checkprime[i]==true)                              // copying the prime number in prime.
        prime.push_back(i);
    }
    return 0;
}

