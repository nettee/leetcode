class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string current;
        vector<string> res;
        generate(n, n, 0, current, res);
        return res;
    }
    
    void generate(int left, int right, int depth, string& current, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(current);
        }
        if (left > 0) {
            current += '(';
            generate(left-1, right, depth+1, current, res);
            current.erase(current.end() - 1);
        }
        if (right > 0 && depth > 0) {
            current += ')';
            generate(left, right-1, depth-1, current, res);
            current.erase(current.end() - 1);
        }
    }
};
