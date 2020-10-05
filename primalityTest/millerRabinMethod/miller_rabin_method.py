import random


def miller_rabin_method(number: int, rounds: int = 40) -> bool:
    """Miller-Rabin primality test

    Test if number could be prime using the Miller-Rabin Primality Test with rounds rounds.
    A return value of false means number is definitely composite, while true means it is probably prime.
    The higher rounds is, the more accurate the test is.
    :param int number: The number to be tested for primality.
    :param int rounds: How many rounds to use in the test.
    :return: A bool indicating if the number could be prime or not.
    :rtype: bool

    """
    # Handle corner cases
    if number == 1:
        return False
    if number == 2:
        return True
    if number == 3:
        return True

    # Factor out the powers of 2 from {number - 1} and save the result
    d = number - 1
    r = 0
    while not d & 1:
        d = d >> 1
        r += 1

    # Cycle at most {round} times
    for i in range(rounds + 1):
        a = random.randint(2, number - 2)
        x = pow(a, d, number)
        if x == 1 or x == number - 1:
            continue
        # Cycle at most {r - 1} times
        for e in range(r):
            x = x * x % number
            if x == number - 1:
                break
        if x == number - 1:
            continue
        return False
    return True


if __name__ == "__main__":
    count = 0
    upper_bound = 1000
    print(f"Prime numbers lower than {upper_bound}:")
    for i in range(1, 1000):
        if miller_rabin_method(i):
            print(f"\t{i}")
            count += 1
    print(f"Total: {count}")