/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.80%)
 * Total Accepted:    136.8K
 * Total Submissions: 305.3K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> stat1 = stat(nums1);
        unordered_map<int, int> stat2 = stat(nums2);
        unordered_map<int, int> stat3;
        for (const auto& e : stat1) {
            int num = e.first;
            if (stat2.find(num) != stat2.end()) {
                int count1 = e.second;
                int count2 = stat2[num];
                stat3[num] = min(count1, count2); 
            }
        }
        vector<int> res;
        for (const auto& e : stat3) {
            int num = e.first;
            int count = e.second;
            for (int i = 0; i < count; i++) {
                res.push_back(num);
            }
        }
        return res;
    }

private:
    unordered_map<int, int> stat(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto n : nums) {
            if (map.find(n) == map.end()) {
                map[n] = 0;
            }
            map[n]++;
        }
        return map;
    }
};

