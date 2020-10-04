using System.Numerics;

namespace Algorithms.primalityTest
{

    public static partial class Algorithms
    {

        /// <summary>
        /// Miller-Rabin primality test
        /// </summary>
        /// <remarks>
        /// Test if <paramref name="number"/> could be prime using the Miller-Rabin Primality Test with <paramref name="rounds"/> rounds.
        /// A return value of false means <paramref name="number"/> is definitely composite, while true means it is probably prime.
        /// The higher <paramref name="rounds"/> is, the more accurate the test is.
        /// </remarks>
        /// <param name="number">The number to be tested for primality.</param>
        /// <param name="rounds">How many rounds to use in the test.</param>
        /// <returns>A bool indicating if the number could be prime or not.</returns>
        public static bool MillerRabin(BigInteger number, int rounds)
        {
            // Handle corner cases
            if (number == 1)
                return false;
            if (number == 2)
                return true;

            // Factor out the powers of 2 from {number - 1} and save the result
            BigInteger d = number - 1;
            int r = 0;
            while (d % 2 == 0)
            {
                d /= 2;
                ++r;
            }

            BigInteger x, a;
            // Cycle at most {round} times
            for (; rounds > 0; --rounds)
            {
                a = RandomInRange(2, (number - 1));
                x = BigInteger.ModPow(a, d, number);
                if (x == 1 || x == number - 1)
                    continue;
                // Cycle at most {r - 1} times
                for (int tmp = 0; tmp < r - 1; ++tmp)
                {
                    x = BigInteger.ModPow(x, 2, number);
                    if (x == number - 1)
                        break;
                }
                if (x == number - 1)
                    continue;
                return false;
            }
            return true;
        }
    }
}
