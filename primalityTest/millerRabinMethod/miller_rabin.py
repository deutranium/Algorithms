import random


def miller_rabin(number: int, rounds: int) -> bool:
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

    # Factor out the powers of 2 from {number - 1} and save the result
    d = number - 1
    r = 0
    while d % 2 == 0:
        d /= 2
        r += 1
    d = int(d)

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
