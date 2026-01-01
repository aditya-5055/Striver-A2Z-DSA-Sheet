// approch 1
/*
Problem: Remove Duplicates from Sorted Array
Difficulty: Easy
Platform: LeetCode (26) / Striver A2Z DSA Sheet

Description:
Given a sorted array, remove the duplicates in-place such that
each unique element appears only once.
Return the number of unique elements (k).

The first k elements of the array should contain the unique elements
in sorted order.

Approach:
Two Pointer Technique
- Pointer i tracks the index of the last unique element
- Pointer j scans the array
- When nums[j] != nums[i], we move i forward and update nums[i]

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0; // index of last unique element

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1; // number of unique elements
    }
};


// approch 2
/*
Alternative Approach: Using Set (For Explanation Only)

Idea:
- Use a set to store unique elements from the array.
- Since set stores only unique elements and keeps them sorted,
  duplicates are automatically removed.
- Copy the elements back into the original array.

Why NOT optimal:
- Uses extra space O(n)
- Problem requires in-place modification
- Two-pointer approach is preferred

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;

        // Insert all elements into set (removes duplicates)
        for (auto x : nums) {
            s.insert(x);
        }

        // Copy unique elements back to nums
        int i = 0;
        for (auto val : s) {
            nums[i] = val;
            i++;
        }

        // Return count of unique elements
        return i;
    }
};
