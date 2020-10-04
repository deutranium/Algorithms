using System.Numerics;
using System.Security.Cryptography;

namespace Algorithms.primalityTest
{

    /// <summary>
    /// Collection of support tools for primality test algorithms
    /// Random BigInteger implementation from https://stackoverflow.com/a/48855115/12771343
    /// </summary>
    public static partial class Algorithms
    {

        /// <summary>
        /// Generate a random BigInteger between <paramref name="min"/> and <paramref name="max"/>, inclusive.
        /// </summary>
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


    }
}
