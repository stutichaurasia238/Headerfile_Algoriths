#include "algorithm.h"

// Function to solve the 0/1 knapsack problem
int knapSack(int W, std::vector<int> wt, std::vector<int> val, int n) {
    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));

    // Build the table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = std::max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}