/*
 * [778] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (39.42%)
 * Total Accepted:    14.5K
 * Total Submissions: 36.7K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 * 
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "aab"
 * Output: "aba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "aaab"
 * Output: ""
 * 
 * 
 * Note:
 * 
 * 
 * S will consist of lowercase letters and have length in range [1, 500].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string reorganizeString(string S) {
        string t = sorted(S);
        int k = (t.length() + 1) / 2;
        if (t[0] == t[k]) {
            return "";
        } else {
            return reorganize(t);
        }
    }

private:
    string sorted(string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c-'a']++;
        }
        vector<pair<char,int>> rank;
        for (char c = 'a'; c <= 'z'; c++) {
            rank.push_back(make_pair(c, count[c-'a']));
        }
        sort(rank.begin(), rank.end(), [](const pair<char,int>& a, const pair<char,int>& b) -> bool {
                return a.second > b.second;
                });
        string res;
        for (auto r : rank) {
            res.append(r.second, r.first);
        }
        return res;
    }

    string reorganize(string& s) {
        string res;
        int mid = (s.length() + 1) / 2;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                res += s[i/2];
            } else {
                res += s[mid+i/2];
            }
        }
        return res;
    }
};

