#include "algorithm.h"

int main() {
    std::string text = "abcxabcdabcdabcy";
    std::string pattern = "abcdabcy";

    int base = 10;
    int modulus = 1000000;

    int index = rabin_karp_search(text, pattern, base, modulus);

    if (index!= -1) {
        std::cout << "Pattern found at index " << index << std::endl;
    } else {
        std::cout << "Pattern not found" << std::endl;
    }

    return 0;
}