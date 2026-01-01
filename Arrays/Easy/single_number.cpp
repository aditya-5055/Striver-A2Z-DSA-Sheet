🔢 Single Number (LeetCode 136)
/*
Problem: Single Number
Difficulty: Easy
Platform: LeetCode (136) / Striver A2Z DSA Sheet

Description:
Given a non-empty array of integers where every element
appears twice except for one, find that single one.

Constraint:
- Linear time complexity
- Constant extra space
*/

🐢 APPROACH 1: Sorting Approach
💡 Idea

If the array is sorted, duplicate elements will appear next to each other.
The single element will break this pattern.

/*
Approach 1: Sorting

Steps:
1. Sort the array
2. Traverse the array in pairs
3. If a mismatch is found, return the element

Time Complexity: O(n log n)
Space Complexity: O(1) (in-place sorting)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }

        // If all pairs matched, last element is unique
        return nums[n - 1];
    }
};


📌 Drawback: Sorting increases time complexity.

🛠 APPROACH 2: Hash Map (Frequency Count)
💡 Idea

Count how many times each number appears.
The one with frequency 1 is the answer.

/*
Approach 2: Hash Map

Steps:
1. Store frequency of each element
2. Find the element with frequency 1

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;  // Should not happen for valid input
    }
};


📌 Drawback: Uses extra memory.

⚡ APPROACH 3: Optimal — XOR Method ⭐
💡 Idea

XOR cancels out duplicate numbers.

/*
Approach 3: XOR (Optimal)

Key Properties:
- a ^ a = 0
- a ^ 0 = a
- XOR is commutative and associative

Steps:
1. XOR all elements
2. Duplicate numbers cancel out
3. Remaining value is the single number

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};


📌 Best solution — meets all problem constraints.