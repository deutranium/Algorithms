def rabinKarp(text, pattern):
    # Define prime number to use in hashing (it's a good practice to choose a prime number)
    prime = 101

    # Calculate the length of the text and pattern
    n = len(text)
    m = len(pattern)

    # Calculate the hash value for the pattern
    pattern_hash = 0
    for i in range(m):
        pattern_hash = (pattern_hash + ord(pattern[i])) % prime

    # Calculate the hash value for the initial window of text
    text_hash = 0
    for i in range(m):
        text_hash = (text_hash + ord(text[i])) % prime

    # Iterate through the text with a sliding window
    for i in range(n - m + 1):
        # Check if the hash values match
        if pattern_hash == text_hash:
            # If hash values match, perform a character-by-character comparison
            match = True
            for j in range(m):
                if pattern[j] != text[i + j]:
                    match = False
                    break
            if match:
                # Pattern found at index 'i'
                return i

        # Update the hash value for the next window of text
        if i < n - m:
            # Remove the leftmost character and add the rightmost character
            text_hash = (text_hash - ord(text[i]) + ord(text[i + m])) % prime

            # Ensure the hash value is non-negative
            if text_hash < 0:
                text_hash += prime

    # Pattern not found in the text
    return -1

# Test the algorithm
text = "AABBACHADA"
pattern = "BBAC"
index = rabinKarp(text, pattern)
if index != -1:
    print(f"Pattern found at index: {index+1}")
else:
    print("Pattern not found")
