🔹 PROBLEM: Max Consecutive Ones
/*
Problem: Max Consecutive Ones
Difficulty: Easy
Platform: LeetCode (485) / Striver A2Z DSA Sheet

Description:
Given a binary array nums, return the maximum number of
consecutive 1's in the array.
*/

🐢 APPROACH 1: Brute Force (Store streaks + sort)
💡 Idea

Count all streaks of consecutive 1s, store them, sort, and return the maximum.

/*
Approach 1: Brute Force (Extra Vector + Sorting)

Steps:
1. Traverse array and count consecutive 1s
2. Store each streak length in a vector
3. Sort the vector
4. Return the maximum value

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> streaks;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                streaks.push_back(count);
                count = 0;
            }
        }

        // In case array ends with 1
        streaks.push_back(count);

        sort(streaks.begin(), streaks.end());
        return streaks.back();
    }
};


📌 Drawback: Extra space + sorting overhead.

🛠 APPROACH 2: Better (Track previous maximum)
💡 Idea

Track current streak and compare it with previous maximum.

/*
Approach 2: Better (Using Variables)

Steps:
1. Count current streak of 1s
2. When 0 appears, update max and reset count
3. Check again at the end

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int prevMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                if (count > prevMax) {
                    prevMax = count;
                }
                count = 0;
            }
        }

        // For last streak
        if (count > prevMax) {
            prevMax = count;
        }

        return prevMax;
    }
};


📌 Better, but logic is slightly more complex.

✅ APPROACH 3: Optimal (Clean & Best)
💡 Idea

Maintain a running count and update maximum immediately.

/*
Approach 3: Optimal (Single Pass)

Steps:
1. Traverse the array
2. Increase count when 1 is found
3. Reset count when 0 is found
4. Update maximum on the go

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 0;
            }
        }

        return maxi;
    }
};


📌 Best approach for interviews & GitHub