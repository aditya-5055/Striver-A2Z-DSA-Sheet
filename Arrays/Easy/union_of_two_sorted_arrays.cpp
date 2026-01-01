// optimal

/*
Problem: Union of Two Sorted Arrays
Difficulty: Easy
Platform: Striver A2Z DSA Sheet

Description:
Given two sorted arrays, return their union containing
only distinct elements in ascending order.

Examples:
Input:  nums1 = [1,2,3,4,5], nums2 = [1,2,7]
Output: [1,2,3,4,5,7]

Approach (Optimal):
Use two pointers to traverse both arrays.
Add smaller element to result while avoiding duplicates.

Time Complexity: O(n + m)
Space Complexity: O(1) (excluding output array)
*/

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> result;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
            } else {
                if (result.empty() || result.back() != nums2[j]) {
                    result.push_back(nums2[j]);
                }
                j++;
            }
        }

        // Remaining elements
        while (i < n) {
            if (result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
        }

        while (j < m) {
            if (result.back() != nums2[j]) {
                result.push_back(nums2[j]);
            }
            j++;
        }

        return result;
    }
};


// brout

class Solution
{
public:
  vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
  {
    set<int> x;
    for (int i = 0; i < nums1.size(); i++)
    {
      x.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
      x.insert(nums2[i]);
    }
    vector<int> v;
    //    vector<int> v(x.begin(), x.end());
    for (auto ch : x)
    {
      v.push_back(x);
    }
    return v;
  }
};

