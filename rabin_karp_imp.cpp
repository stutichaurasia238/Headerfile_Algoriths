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