/*
optimal


Problem: Rotate Array
Difficulty: Easy
Platform: LeetCode (189) / Striver A2Z DSA Sheet

Description:
Given an integer array nums, rotate the array to the right by k steps.

Example:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Approach (Optimal):
1. Reverse the entire array
2. Reverse first k elements
3. Reverse remaining n-k elements

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;   // Handle case when k > n

        // Step 1: Reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};


// brout force

/*
Alternative Approach: Using Extra Array (Brute Force)

Idea:
- Store last k elements in a temporary array
- Shift the remaining elements
- Copy back to original array

Why NOT optimal:
- Uses extra space O(n)
- Problem expects in-place solution

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> temp;

        // Store last k elements
        for (int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }

        // Store first n-k elements
        for (int i = 0; i < n - k; i++) {
            temp.push_back(nums[i]);
        }

        // Copy back to nums
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};
