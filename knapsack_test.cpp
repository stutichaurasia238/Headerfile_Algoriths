#include "algorithm.h"

int main() {
    std::vector<int> val = {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    std::cout << "Maximum value that can be obtained: " << knapSack(W, wt, val, n) << std::endl;

    return 0;
}