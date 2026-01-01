/*
Problem: Move Zeroes
Difficulty: Easy
Platform: LeetCode (283) / Striver A2Z DSA Sheet

Description:
Given an integer array nums, move all 0's to the end of the array
while maintaining the relative order of the non-zero elements.
The operation must be done in-place.

Example:
Input:  [0,1,0,3,12]
Output: [1,3,12,0,0]

Approach (Optimal):
1. Use a pointer to place non-zero elements at the front.
2. After all non-zero elements are placed, fill the remaining positions with zero.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;  // position to place next non-zero element

        // Move non-zero elements forward
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        // Fill remaining positions with zero
        while (pos < n) {
            nums[pos] = 0;
            pos++;
        }
    }
};




/*
Alternative Approach: Using Extra Array (Brute Force)

Idea:
- Create a temporary array initialized with zero.
- Copy all non-zero elements into it.
- Copy the result back to the original array.

Why NOT optimal:
- Uses extra space O(n)
- Problem requires in-place solution

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp[j] = nums[i];
                j++;
            }
        }

        // Copy back to original array
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};
