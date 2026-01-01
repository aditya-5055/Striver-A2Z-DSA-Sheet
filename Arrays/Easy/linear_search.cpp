/*
Problem: Linear Search
Difficulty: Easy
Platform: Striver A2Z DSA Sheet

Description:
Given an array of integers nums and an integer target,
find the smallest index (0-based) where the target appears.
If the target is not found, return -1.

Examples:
Input:  nums = [2, 3, 4, 5, 3], target = 3
Output: 1

Input:  nums = [2, -4, 4, 0, 10], target = 6
Output: -1

Approach:
Traverse the array from left to right.
Return the index as soon as the target is found.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;   // first occurrence
            }
        }
        return -1;  // target not found
    }
};
