/*
Problem: Check if the Array is Sorted
Difficulty: Easy
Platform: Striver A2Z DSA Sheet

Description:
Given an array of integers, check whether the array is sorted
in non-decreasing (ascending) order.
Return true if sorted, otherwise false.

Examples:
Input:  [1, 2, 3, 4, 5]
Output: true

Input:  [1, 3, 2, 4]
Output: false

Approach:
Traverse the array and compare each element with the previous one.
If any element is smaller than the previous, the array is not sorted.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isSorted(vector<int> &nums) {
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
