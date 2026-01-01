/*
Problem: Maximum Consecutive 1s or 0s
Difficulty: Easy
Platform: GFG / Practice

Description:
Given a binary array consisting of only 0s and 1s,
return the maximum number of consecutive 1s or 0s present in the array.

Examples:
Input:  [0, 1, 0, 1, 1, 1, 1]
Output: 4

Input:  [0, 0, 1, 0, 1, 0]
Output: 2

Input:  [0, 0, 0, 0]
Output: 4

Approach:
Traverse the array and count consecutive equal elements.
Reset count when the current element is different from the previous one.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxConsecBits(vector<int> &arr) {
        int n = arr.size();

        int count = 1;  // count of current consecutive elements
        int maxi = 1;   // maximum consecutive count

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            maxi = max(maxi, count);
        }

        return maxi;
    }
};
