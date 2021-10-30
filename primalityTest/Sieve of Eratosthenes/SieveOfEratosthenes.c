#include <stdio.h>

void sieveOfEratosthenes(int number)
{

    int i, j;
    int primes[number + 1];

    for (i = 2; i <= number; i++) //populating array with naturals numbers
        primes[i] = i;

    i = 2;
    while ((i * i) <= number)
    {
        if (primes[i] != 0)
        {
            for (j = 2; j < number; j++)
            {
                if (primes[i] * j > number)
                    break;
                else
                    primes[primes[i] * j] = 0; // Instead of deleteing , making elemnets 0
            }
        }
        i++;
    }

    int result[number + 1];
    int k = 0;
    for (i = 2; i <= number; i++)
    {
        //If number is not 0 then it is prime
        if (primes[i] != 0)
        {
            result[k++] = primes[i];
        }
    }

    for (i = 0; i < k; i++)
        printf("%d ", result[i]);

    printf("\n");
}

int main()
{
    int number = 100;

    sieveOfEratosthenes(number);

    return 0;
}

/*
TIme Complexity : O(nlog(logn))
Space Complexity : O(n)
*/