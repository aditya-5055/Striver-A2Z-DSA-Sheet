/*
Problem: Second Largest Element in an Array
Difficulty: Easy
Platform: Striver A2Z DSA Sheet

Description:
Given an array of integers, return the second-largest element.
If the second-largest element does not exist, return -1.

Examples:
Input:  [8, 8, 7, 6, 5]
Output: 7

Input:  [10, 10, 10, 10]
Output: -1

Approach:
1. Find the largest element.
2. Find the largest element smaller than the maximum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int secondLargestElement(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return -1;

        int largest = nums[0];
        int secondLargest = -1;

        // Find the largest element
        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }

        // Find the second largest element
        for (int i = 0; i < n; i++) {
            if (nums[i] < largest && nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }

        return secondLargest;
    }
};
