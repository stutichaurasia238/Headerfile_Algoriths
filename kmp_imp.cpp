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
/*Suppose we have the pattern "ABCDABD" and the text "ABC ABCDAB ABCDABCDABDE". The KMP algorithm first constructs a table that stores the length of the longest proper prefix of the pattern that matches a suffix of the pattern. For the pattern "ABCDABD", the table is as follows:

Index	0	1	2	3	4	5	6
Value	-1	0	0	0	1	2	0
The table indicates that the longest proper prefix of the pattern that matches a suffix of the pattern is "AB" at index 4, which has a length of 2.

Next, the algorithm searches for occurrences of the pattern in the text. It starts by comparing the first character of the pattern with the first character of the text. If they match, it moves to the next character. If they don't match, it uses the table to determine how many characters to skip in the text.

For example, when the algorithm reaches the fifth character of the text, which is "D", it compares it with the fifth character of the pattern, which is "B". Since they don't match, the algorithm uses the table to determine how many characters to skip in the text. The table indicates that the longest proper prefix of the pattern that matches a suffix of the pattern is "AB" at index 4, which has a length of 2. Therefore, the algorithm skips the next two characters in the text, which are "AB", and moves to the seventh character of the text, which is "C".

The algorithm continues this process until it reaches the end of the text or finds an occurrence of the pattern. In this example, the algorithm finds an occurrence of the pattern at index 11 of the text.

The KMP algorithm is an efficient string matching algorithm that avoids unnecessary comparisons by using a precomputed table to keep track of the longest proper prefix of the pattern that matches a suffix of the pattern. It has a time complexity of O(n), where n is the length of the text, making it an efficient algorithm for string matching, especially for long texts and patterns.



*/