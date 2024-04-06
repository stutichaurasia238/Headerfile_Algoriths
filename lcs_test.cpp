#include "algorithm.h"

int main() {
    std::string a = "ABCDGH";
    std::string b = "AEDFHR";

    int length = lcs_length(a, b);

    std::cout << "The length of the longest common subsequence is: " << length << std::endl;

    return 0;
}