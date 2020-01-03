class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        vector<vector<int>> into(N, vector<int>());
        queue<int> q;
        vector<bool> reached(N, false);
        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                q.push(i);
                reached[i] = true;
            } else {
                int left = i - arr[i];
                int right = i + arr[i];
                if (left >= 0) {
                    into[left].push_back(i);
                }
                if (right < N) {
                    into[right].push_back(i);
                }
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int s : into[node]) {
                if (!reached[s]) {
                    q.push(s);
                    reached[s] = true;
                }
            }
        }
        return reached[start];
    }
};
