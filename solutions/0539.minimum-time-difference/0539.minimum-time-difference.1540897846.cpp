/*
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (46.58%)
 * Total Accepted:    21.8K
 * Total Submissions: 46.8K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (string& tp : timePoints) {
            mins.push_back(toMinutes(tp));
        }

        sort(mins.begin(), mins.end());

        int minmin = mins[0] + 24 * 60 - mins[mins.size()-1];
        for (int i = 1; i < mins.size(); i++) {
            minmin = min(minmin, mins[i] - mins[i-1]);
        }
        return minmin;
    }

private:
    int toMinutes(string& tp) {
        int h = stoi(tp.substr(0, 2));
        int m = stoi(tp.substr(3, 2));
        return h * 60 + m;
    }
};

