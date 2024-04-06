#include "algorithm.h"

int main() {
    std::string a = "ABCDGH";
    std::string b = "AEDFHR";

    int length = lcs_length(a, b);

    std::cout << "The length of the longest common subsequence is: " << length << std::endl;

    return 0;
}
/* Suppose we have the two strings "ABCDGH" and "AEDFHR". The LCS algorithm first initializes a 2D array as follows:

A	B	C	D	G	H
A	0	0	0	0	0	0
E	0	0	0	0	0	0
D	0	0	0	0	0	0
F	0	0	0	0	0	0
H	0	0	0	0	0	0
R	0	0	0	0	0	0
The algorithm then compares the characters of the two strings and updates the array as follows:

A	B	C	D	G	H
A	0	0	0	0	0	0
E	0	0	1	1	1	1
D	0	0	1	2	2	2
F	0	0	1	2	2	2
H	0	0	1	2	2	3
R	0	0	1	2	2	3
The algorithm continues this process until it reaches the end of the two strings. In this example, the longest common subsequence of the two strings is "ADH", which has a length of 3.

The LCS algorithm is an efficient dynamic programming algorithm that finds the longest sequence of characters that is common to two strings. It has a time complexity of O(n * m), where n and m are the lengths of the two strings, making it an efficient algorithm for comparing two strings and finding the longest common subsequence. The output of the LCS algorithm is the length of the longest common subsequence of the two strings.



 */