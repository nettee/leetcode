class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return vector<int>();
        }
        
        // mono stack: min item top
        // item: (temperature, index)
        stack<pair<int, int>> st;
        
        int N = T.size();
        vector<int> res(N, 0);
        
        for (int i = N-1; i >= 0; i--) {
            int t = T[i];
            while (!st.empty() && st.top().first <= t) {
                st.pop();
            }
            
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top().second - i;
            }
            
            st.push(make_pair(t, i));
        }
        
        return res;        
    }
};
