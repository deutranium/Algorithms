import java.math.BigInteger;
import java.security.SecureRandom;

class MillerRabinMethod {

    /**
     *
     * Generate a random BigInteger between {@code min} and {@code max}, inclusive.
     * Random BigInteger implementation from
     * <a href="https://stackoverflow.com/a/48855115/12771343">this StackOverflow
     * answer</a> Uses an offset on the
     * {@link #RandomInRangeFromZeroToPositive(BigInteger)} function to return a
     * random BigInteger in a range.
     *
     * @param min lower bound
     * @param max upper bound
     * @return A random BigInteger in [{@code min}, {@code max}].
     */
    public static BigInteger RandomInRange(BigInteger min, BigInteger max) {

        // If min > max we swap the values
        if (min.compareTo(max) == 1) {
            max = max.add(min);
            min = max.subtract(min);
            max = max.subtract(min);
        }

        // Offset to set min = 0
        max = max.subtract(min);

        // Retrieve the random number and offset to get the desired interval
        BigInteger value = RandomInRangeFromZeroToPositive(max).add(min);
        return value;
    }

    /**
     *
     * Generate a random BigInteger smaller or equal to {@code max}. Random
     * BigInteger implementation from
     * <a href="https://stackoverflow.com/a/48855115/12771343">this StackOverflow
     * answer</a> Returns a random BigInteger lower than {@code max} derived from a
     * random byte array" />
     *
     * @param max upper bound
     * @return a random BigInteger in [0, {@code max}].
     */
    private static BigInteger RandomInRangeFromZeroToPositive(BigInteger max) {

        SecureRandom rng = new SecureRandom();
        BigInteger value;
        byte[] bytes = max.toByteArray();

        // NOTE: sign bit is always 0 because `max` must always be positive
        byte zeroBitsMask = 0b00000000;

        // Count how many bits of the most significant byte are 0
        var mostSignificantByte = bytes[0];

        // Try to set to 0 as many bits as there are in the most significant byte,
        // starting from the left (most significant bits first)
        // NOTE: `i` starts from 7 because the sign bit is always 0
        for (var i = 7; i >= 0; i--) {
            // Keep iterating until the most significant non-zero bit
            if ((mostSignificantByte & (0b1 << i)) != 0) {
                var zeroBits = 7 - i;
                zeroBitsMask = (byte) (0b11111111 >> zeroBits);
                break;
            }
        }

        do {
            rng.nextBytes(bytes);

            // Set most significant bits to 0 (because if any of these bits is 1 `value >
            // max`)
            bytes[0] &= zeroBitsMask;

            value = new BigInteger(bytes);

            // `value > max` 50% of the times, in which case the fastest way to keep the
            // distribution uniform is to try again
        } while (value.compareTo(max) == 1);

        return value;
    }

    /**
     *
     * Miller-Rabin primality test Test if {@code number} could be prime using the
     * Miller-Rabin Primality Test with {@code round} rounds. A return value of
     * false means {@code number} is definitely composite, while true means it is
     * probably prime. The higher {@code round} is, the more accurate the test is.
     *
     * @param number the number to be tested for primality
     * @param rounds how many rounds to use in the test
     * @return a Boolean indicating if the number could be prime or not
     */
    public static Boolean MillerRabin(BigInteger number, int rounds) {

        // Handle corner cases
        if (number.equals(BigInteger.valueOf(1)))
            return false;
        if (number.equals(BigInteger.valueOf(2)))
            return true;

        // Factor out the powers of 2 from {number - 1} and save the result
        BigInteger d = number.subtract(BigInteger.valueOf(1));
        int r = 0;
        while (d.mod(BigInteger.valueOf(2)).equals(BigInteger.valueOf(0))) {
            d = d.divide(BigInteger.valueOf(2));
            ++r;
        }

        BigInteger x, a;
        // Cycle at most {round} times
        for (; rounds > 0; --rounds) {
            a = RandomInRange(BigInteger.valueOf(2), number.subtract(BigInteger.valueOf(1)));
            x = a.modPow(d, number);
            if (x.equals(BigInteger.valueOf(1)) || x.equals(number.subtract(BigInteger.valueOf(1))))
                continue;
            // Cycle at most {r - 1} times
            for (int tmp = 0; tmp < r - 1; ++tmp) {
                x = x.modPow(BigInteger.valueOf(2), number);
                if (x.equals(number.subtract(BigInteger.valueOf(1))))
                    break;
            }
            if (x.equals(number.subtract(BigInteger.valueOf(1))))
                continue;
            return false;
        }
        return true;
    }

    public static Boolean MillerRabin(BigInteger number) {
        return MillerRabin(number, 40);
    }

    public static void main(String[] args) {
        int count = 0;
        int upper_bound = 1000;
        System.out.println("Prime numbers lower than " + upper_bound + ":");
        for (int i = 1; i < upper_bound; ++i) {
            if (MillerRabin(BigInteger.valueOf(i))) {
                System.out.println("\t" + i);
                ++count;
            }
        }
        System.out.println("Total: " + count);
    }
}