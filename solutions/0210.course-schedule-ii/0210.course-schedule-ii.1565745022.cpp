class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int N = numCourses;
        vector<vector<int>> adjlist(N, vector<int>());
        vector<int> indegree(N, 0);
        
        for (vector<int>& edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            adjlist[from].push_back(to);
            indegree[to]++;
        }
        
        for (int i = 0; i < N; i++) {
            cout << i << ":";
            for (int to : adjlist[i]) {
                cout << " " << to;
            }
            cout << endl;
        }
        
        deque<int> q; // queue of zero indegree nodes
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push_back(i);
            }
        }
        
        vector<int> res;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop_front();
            
            res.push_back(node);
            
            for (int to : adjlist[node]) {
                indegree[to]--;
                if (indegree[to] == 0) {
                    q.push_back(to);
                }
            }
        }
        
        if (res.size() == N) {
            return res;
        } else {
            return vector<int>();
        }
    }
};
