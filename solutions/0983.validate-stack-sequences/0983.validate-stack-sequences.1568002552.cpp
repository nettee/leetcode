class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) {
            return false;
        }
        
        int N = pushed.size();
        int i = 0;
        stack<int> s;
        for (int e : popped) {
            while (i < N && (s.empty() || s.top() != e)) {
                s.push(pushed[i++]);
            }
            if (s.empty() || s.top() != e) {
                return false;
            }
            s.pop();
        }
        return true;
    }
};
