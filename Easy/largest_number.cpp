/*
Problem: Largest Element in an Array
Difficulty: Easy
Platform: Striver A2Z Sheet
Description:
Given an array of integers, return the largest element.

Example:
Input:  [3, 3, 6, 1]
Output: 6

Approach:
Iterate through the array and keep track of the maximum element.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestElement(vector<int> &nums) {
        int n = nums.size();

        // Assume first element is the largest
        int largest = nums[0];

        // Traverse array to find maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }

        return largest;
    }
};
