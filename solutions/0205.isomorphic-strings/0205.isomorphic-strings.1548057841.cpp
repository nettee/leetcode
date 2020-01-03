class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int N = s.length();
        unordered_map<char, char> m;
        for (int i = 0; i < N; i++) {
            char a = s[i];
            char b = t[i];
            if (m.find(a) == m.end()) {
                m[a] = b;
            } else {
                if (m[a] != b) {
                    return false;
                }
            }
        }
        unordered_set<char> se;
        for (auto e : m) {
            se.insert(e.second);
        }
        return m.size() == se.size();
    }
};
