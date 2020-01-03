/*
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (48.51%)
 * Total Accepted:    49.4K
 * Total Submissions: 101.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum = nums[0];
        for (int num : nums) {
            minnum = min(minnum, num);
        }

        int res = 0;
        for (int num : nums) {
            res += num - minnum;
        }
        return res;
    }
};

