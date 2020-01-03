class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> indegrees(N, 0);
        vector<vector<int>> adj(N, vector<int>());
        
        for (vector<int>& prer : prerequisites) {
            int from = prer[1];
            int to = prer[0];
            indegrees[to]++;
            adj[from].push_back(to);
        }
        
        deque<int> zds;
        for (int i = 0; i < N; i++) {
            if (indegrees[i] == 0) {
                zds.push_back(i);
            }
        }
        
        int finished = 0;
        while (!zds.empty()) {
            int node = zds.front();
            zds.pop_front();
            finished++;
            for (int i : adj[node]) {
                indegrees[i]--;
                if (indegrees[i] == 0) {
                    zds.push_back(i);
                }
            }
        }
        
        return finished == N;
    }
};
