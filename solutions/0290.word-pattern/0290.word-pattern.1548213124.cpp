class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str);
        if (pattern.length() != words.size()) {
            return false;
        }
        int N = pattern.length();
        unordered_map<char, string> m;
        for (int i = 0; i < N; i++) {
            if (m.find(pattern[i]) != m.end()) {
                if (m[pattern[i]] != words[i]) {
                    return false;
                }            
            } else {
                m[pattern[i]] = words[i];
            }
        }
        unordered_set<string> s;
        for (auto e : m) {
            s.insert(e.second);
        }
        return s.size() == m.size();
    }
    
    vector<string> split(string str) {
        vector<string> res;
        int N = str.length();
        int i = 0;
        while (i < N) {
            while (i < N && str[i] == ' ') {
                i++;
            }
            int j = i;
            while (j < N && str[j] != ' ') {
                j++;
            }
            res.push_back(string(str, i, j - i));
            i = j;
        }
        return res;
    }
};
