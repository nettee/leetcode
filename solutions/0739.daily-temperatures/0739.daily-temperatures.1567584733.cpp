class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 参考 cn 站上的答案
        // https://leetcode-cn.com/problems/daily-temperatures/solution/liang-chong-fang-fa-zhan-he-tiao-yue-dui-bi-by-fra/
        int N = T.size();
        vector<int> res(N, 0);
        stack<int> s;
        for (int i = N - 1; i >= 0; i--) {
            while (!s.empty() && T[i] >= T[s.top()]) {
                s.pop();
            }
            if (s.empty()) {
                res[i] = 0;
            } else {
                res[i] = s.top() - i;
            }
            s.push(i);
        }
        return res;
    }
};
