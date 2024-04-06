#include "algorithm.h"

// Function to compute the length of the longest common subsequence of two strings
int lcs_length(const std::string& a, const std::string& b) {
    int m = a.length();
    int n = b.length();

    // Create a table to store the lengths of the longest common subsequences
    std::vector<std::vector<int>> lcs(m + 1, std::vector<int>(n + 1));

    // Fill the table using dynamic programming
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    // Return the length of the longest common subsequence
    return lcs[m][n];
}