🔹 PROBLEM: Missing Number
/*
Problem: Missing Number
Difficulty: Easy
Platform: LeetCode (268) / Striver A2Z DSA Sheet

Description:
Given an array containing n distinct numbers taken from
the range [0, n], find the one number that is missing.
*/
✅ APPROACH 1: Brute Force (Linear Search)
💡 Idea
For every number from 0 to n, check whether it exists in the array.
/*
Approach 1: Brute Force (Linear Search)

Steps:
1. Loop from 0 to n
2. For each number, check if it exists in the array
3. If not found, return that number

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            bool found = false;

            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found) return i;
        }
        return -1;
    }
};
// 📌 Why not good?
// Too slow for large n.
// ✅ APPROACH 2: Sort + Index Check
// 💡 Idea
// If array is sorted, each index should contain the same value as the index.
/*
Approach 2: Sorting + Index Check

Steps:
1. Sort the array
2. If nums[i] != i, then i is missing
3. If all match, missing number is n

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};
// 📌 Why better than brute?
// Faster, but still not optimal.
// ✅ APPROACH 3: Hash Map / Frequency Array
// 💡 Idea
// Mark all numbers present, then find which one is missing.
/*
Approach 3: Hash Map

Steps:
1. Store all elements in a hash map
2. Check from 0 to n which key is missing

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x] = 1;
        }

        for (int i = 0; i <= n; i++) {
            if (freq[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
// 📌 Why not optimal?
// Uses extra memory.
// ✅ APPROACH 4: Optimal — Sum Formula ⭐
// 💡 Idea
// Sum of numbers from 0 to n minus actual sum gives missing number.
/*
Approach 4: Mathematical Sum Formula (Optimal)

Steps:
1. Calculate expected sum = n * (n + 1) / 2
2. Calculate actual sum of array
3. Missing number = expected sum - actual sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int x : nums) {
            actualSum += x;
        }

        return expectedSum - actualSum;
    }
};
// 📌 Best for interviews