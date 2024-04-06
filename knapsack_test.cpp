#include "algorithm.h"

int main() {
    std::vector<int> val = {60, 100, 120};
    std::vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    std::cout << "Maximum value that can be obtained: " << knapSack(W, wt, val, n) << std::endl;

    return 0;
}
/*Suppose we have the following items:

Item	Weight	Value
1	10	60
2	20	100
3	30	120
And the maximum weight of the knapsack is 50.

The 0/1 Knapsack algorithm first initializes a 2D array as follows:

0	10	20	30	40	50
0	0	0	0	0	0	0
1	0	0	0	0	0	0
2	0	0	0	0	0	0
3	0	0	0	0	0	0
The algorithm then compares the weights and values of the items and updates the array as follows:

0	10	20	30	40	50
0	0	0	0	0	0	0
1	0	0	0	0	60	60
2	0	0	0	0	100	160
3	0	0	0	120	160	220
The algorithm continues this process until it reaches the end of the items. In this example, the maximum value of the items that can be selected such that the total weight of the selected items is less than or equal to 50 is 220, which is obtained by selecting items 2 and 3.

The 0/1 Knapsack algorithm is an efficient dynamic programming algorithm that solves the 0/1 Knapsack problem. It has a time complexity of O(n * W), where n is the number of items and W is the maximum weight of the knapsack, making it an efficient algorithm for solving the 0/1 Knapsack problem. The output of the 0/1 Knapsack algorithm is the maximum value of the items that can be selected such that the total weight of the selected items is less than or equal to a given capacity.



*/