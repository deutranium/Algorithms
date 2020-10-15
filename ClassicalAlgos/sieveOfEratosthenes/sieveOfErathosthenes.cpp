//To Find All prime numbers within Range(1 to range).
#include <cstdlib>
#include <iostream>
//NOTE : TAKING 0 AS TRUE AND 1 AS FALSE.
//Sieve of Eratosthenes
//It is an ancient algorithm for finding all prime numbers up to any given limit. It does so by iteratively marking as composite the multiples of each prime, starting with the first prime number, 2.
using namespace std;
class Prime
{
    int *res; //will store 0 or 1 depending on isPrime().
    int range;

public:
    Prime() {}
    void isPrime()
    {
        cout << "Enter max limit (Range: 1 to maxlimit) : ";
        cin >> range;
        res = (int *)calloc(range + 1, sizeof(int)); // all elements initialized to 0.
        res[0] = 1;                                  //false.
        res[1] = 1;                                  //false.
        for (int i = 2; i * i <= range; i++)
        {
            for (int j = 2 * i; j <= range; j += i)
            {
                res[j] = 1;
            }
        }
        return;
    }
    void Display()
    {
        cout << "All the Prime Numbers till " << range << " : ";
        for (int i = 0; i <= range; i++)
        {
            if (res[i] == 0)
                cout << i << " ";
        }
        cout << endl;
    }
    ~Prime()
    {
        delete[] res;
        cout << "Code Terminated!\n";
    }
};
int main() //caller
{
    Prime obj;
    obj.isPrime();
    obj.Display();
    return 0;
}