#include "dsa.h"

int main() {
    std::string text = "abcxabcdabcdabcy";
    std::string pattern = "abcdabcy";

    int index = kmp_search(text, pattern);

    if (index!= -1) {
        std::cout << "Pattern found at index " << index << std::endl;
    } else {
        std::cout << "Pattern not found" << std::endl;
    }

    return 0;
}