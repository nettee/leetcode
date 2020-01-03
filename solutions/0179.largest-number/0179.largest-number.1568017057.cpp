class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int n : nums) {
            strs.push_back(to_string(n));
        }
        
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            string s1 = a + b;
            string s2 = b + a;
            return s1 > s2;
        });
        
        if (strs[0] == "0") {
            // all "0"s
            return "0";
        }
        
        string res;
        for (string& s : strs) {
            res += s;
        }
        return res;
    }
};
