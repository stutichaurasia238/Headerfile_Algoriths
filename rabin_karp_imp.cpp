#include "algorithm.h"

int compute_hash(const std::string& text, int start, int length, int base, int modulus) {
    int hash = 0;
    for (int i = start; i < start + length; i++) {
        hash = (hash * base + text[i]) % modulus;
    }
    return hash;
}

int rabin_karp_search(const std::string& text, const std::string& pattern, int base, int modulus) {
    int text_length = text.length();
    int pattern_length = pattern.length();

    // Compute the hash value of the pattern
    int pattern_hash = compute_hash(pattern, 0, pattern_length, base, modulus);

    // Compute the hash value of the first substring of the text
    int text_hash = compute_hash(text, 0, pattern_length, base, modulus);

    // Slide a window of length pattern_length over the text and compute the hash value of each substring
    for (int i = pattern_length; i < text_length; i++) {
        // Check if the hash values match
        if (text_hash == pattern_hash) {
            // Check if the substrings match exactly
            bool match = true;
            for (int j = 0; j < pattern_length; j++) {
                if (text[i - pattern_length + j]!= pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i - pattern_length;
            }
        }

        // Compute the hash value of the next substring
        text_hash = (text_hash - text[i - pattern_length] * pow(base, pattern_length - 1)) * base + text[i];
        text_hash = (text_hash + modulus) % modulus;
    }

    return -1;
}
/* Suppose we have the pattern "ABCD" and the text "ABC ABCDAB ABCDABCDABDE". The Rabin-Karp algorithm first computes the hash value of the pattern, which is 43904. It then computes the hash value of the first substring of the text, which is "ABC" and has a hash value of 43872.

The algorithm then compares the hash values of the pattern and the current substring. Since they don't match, the algorithm moves to the next substring by computing its hash value using the rolling hash function. It subtracts the hash value of the first character of the current substring, which is "A" and has a hash value of 65, and adds the hash value of the next character in the text, which is "B" and has a hash value of 66. The new hash value is 43872 + 66 - 65 = 43873.

The algorithm continues this process until it reaches the end of the text or finds an occurrence of the pattern. In this example, the algorithm finds an occurrence of the pattern at index 4 of the text.

The Rabin-Karp algorithm is an efficient string matching algorithm that uses hashing to compare the pattern with substrings of the text. It has a time complexity of O(n + m), where n is the length of the text and m is the length of the pattern, making it an efficient algorithm for string matching, especially for long texts and patterns. The output of the Rabin-Karp algorithm is the index of the first occurrence of the pattern in the text, or -1 if the pattern is not found in the text.



*/