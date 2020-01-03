class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (int d : A) {
            if (s.find(d) == s.end()) {
                s.insert(d);
            } else {
                return d;
            }
        }
        return 0;
    }
};
