#include<bits/stdc++.h>
using namespace std; 

//Using logarithmic exponentiation
int modpow(int a,int b , int mod){
	int x=1;
	while(b){
		if(b&1){
			x*=a;
			x%=mod;
		}
	a*=a;
	a%=mod;
	b>>=1;
	}	
	return x;
}
//Time complexity of modpow = O(log n)
//using fermat's theorem that is If n is a prime number, then for every a, 1 < a < n-1, a^(n-1) ≡ 1 (mod n);
bool isPrime(int n ,int k)
{
	while(k--)
	{
		int a = 2 + rand()%(n-4);   

		if(__gcd(a,n) != 1)
			return false; 
		if (modpow(a, n-1, n) != 1) 
          return false; 

	}
	return true; 
}

int main()
{
  
    cout << isPrime(7 , 4) ; 


}

/*
Time complexity: O(k Log n)
Space complexity: O(1) 
*/


