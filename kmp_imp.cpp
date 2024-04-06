#include "algorithm.h"

void compute_partial_match_table(const std::string& pattern, std::vector<int>& table) {
    int i = 0;
    int j = -1;
    table[0] = -1;

    while (i < pattern.length()) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            table[i] = j;
        } else {
            j = table[j];
        }
    }
}

int kmp_search(const std::string& text, const std::string& pattern) {
    std::vector<int> table(pattern.length());
    compute_partial_match_table(pattern, table);

    int i = 0;
    int j = 0;

    while (i < text.length()) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = table[j];
        }

        if (j == pattern.length()) {
            return i - j;
        }
    }

    return -1;
}