using System.Numerics;
using System.Security.Cryptography;

namespace Algorithms.primalityTest
{

    public static partial class PrimalityTest
    {

        /// <summary>
        /// Generate a random BigInteger between <paramref name="min"/> and <paramref name="max"/>, inclusive.
        /// </summary>
        /// <remarks>
        /// Random BigInteger implementation from <see href="https://stackoverflow.com/a/48855115/12771343">this StackOverflow answer</see>
        /// Uses an offset on the <see cref="RandomInRangeFromZeroToPositive(BigInteger)"/> function to return a random BigInteger in a range.
        /// </remarks>
        /// <param name="min">BigInter lower bound.</param>
        /// <param name="max">BigInteger upper bound.</param>
        /// <returns>
        /// A random BigInteger in [<paramref name="min"/>, <paramref name="max"/>].
        /// </returns>
        public static BigInteger RandomInRange(BigInteger min, BigInteger max)
        {

            // If min > max we swap the values
            if (min > max)
            {
                max += min;
                min = max - min;
                max -= min;
            }

            // Offset to set min = 0
            max -= min;

            // Retrieve the random number and offset to get the desired interval
            BigInteger value = RandomInRangeFromZeroToPositive(max) + min;
            return value;
        }

        /// <summary>
        /// Generate a random BigInteger smaller or equal to <paramref name="max"/>.
        /// </summary>
        /// <remarks>
        /// Random BigInteger implementation from <see href="https://stackoverflow.com/a/48855115/12771343">this StackOverflow answer</see>
        /// Returns a random BigInteger lower than <paramref name="max"/> derived from a random byte array" />
        /// </remarks>
        /// <param name="max">BigInteger upper bound.</param>
        /// <returns>
        /// A random BigInteger in [0, <paramref name="max"/>].
        /// </returns>
        private static BigInteger RandomInRangeFromZeroToPositive(BigInteger max)
        {
            using RandomNumberGenerator rng = RandomNumberGenerator.Create();
            BigInteger value;
            byte[] bytes = max.ToByteArray();

            // NOTE: sign bit is always 0 because `max` must always be positive
            byte zeroBitsMask = 0b00000000;

            // Count how many bits of the most significant byte are 0
            var mostSignificantByte = bytes[bytes.Length - 1];

            // Try to set to 0 as many bits as there are in the most significant byte, starting from the left (most significant bits first)
            // NOTE: `i` starts from 7 because the sign bit is always 0
            for (var i = 7; i >= 0; i--)
            {
                // Keep iterating until the most significant non-zero bit
                if ((mostSignificantByte & (0b1 << i)) != 0)
                {
                    var zeroBits = 7 - i;
                    zeroBitsMask = (byte)(0b11111111 >> zeroBits);
                    break;
                }
            }

            do
            {
                rng.GetBytes(bytes);

                // Set most significant bits to 0 (because if any of these bits is 1 `value > max`)
                bytes[bytes.Length - 1] &= zeroBitsMask;

                value = new BigInteger(bytes);

                // `value > max` 50% of the times, in which case the fastest way to keep the distribution uniform is to try again
            } while (value > max);

            return value;
        }

        /// <summary>
        /// Miller-Rabin primality test
        /// </summary>
        /// <remarks>
        /// Test if <paramref name="number"/> could be prime using the Miller-Rabin primality test with <paramref name="rounds"/> rounds.
        /// A return value of false means <paramref name="number"/> is definitely composite, while true means it is probably prime.
        /// The higher <paramref name="rounds"/> is, the more accurate the test is.
        /// </remarks>
        /// <param name="number">The number to be tested for primality.</param>
        /// <param name="rounds">How many rounds to use in the test.</param>
        /// <returns>A bool indicating if the number could be prime or not.</returns>
        public static bool MillerRabin(BigInteger number, int rounds = 40)
        {
            // Handle corner cases
            if (number == 1)
                return false;
            if (number == 2)
                return true;

            // Factor out the powers of 2 from {number - 1} and save the result
            BigInteger d = number - 1;
            int r = 0;
            while (d.IsEven)
            {
                d >>= 1;
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


        public static class MillerRabinMethod
        {
            static void Main(string[] args)
            {
                int count = 0;
                int upper_bound = 1000;
                Console.WriteLine($"Prime numbers lower than {upper_bound}:");
                for (int i = 1; i < upper_bound; ++i)
                {
                    if (PrimalityTest.MillerRabin(i))
                    {
                        Console.WriteLine($"\t{i}");
                        ++count;
                    }
                }
                Console.WriteLine($"Total: {count}");
            }
        }
    }

}
