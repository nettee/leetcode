class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> counter;
        for (char c : p) {
            counter[c]++;
        }
        
        vector<int> res;
        for (int i = 0; i < (int) (s.length() - p.length() + 1); i++) {
            if (matches(s, i, p.length(), counter)) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool matches(string& s, int i, int n, unordered_map<char, int>& counter) {
        unordered_map<char, int> cnt(counter.begin(), counter.end());
        for (int j = 0; j < n; j++) {
            char c = s[i+j];
            cnt[c]--;
        }
        for (auto e : cnt) {
            if (e.second != 0) {
                return false;
            }
        }
        return true;
    }
};
