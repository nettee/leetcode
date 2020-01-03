class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int N = numCourses;
        vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
        
        vector<int> in_edges(N, 0);
        for (auto edge : prerequisites) {
            int from = edge.second;
            int to = edge.first;
            graph[from].push_back(make_pair(from, to));
            in_edges[to]++;
        }
        
        deque<int> free_courses; // Set of courses with no prerequisite
        for (int i = 0; i < N; i++) {
            if (in_edges[i] == 0) {
                free_courses.push_back(i);
            }
        }

        vector<int> res;
        while (!free_courses.empty()) {
            int c = free_courses.front();
            free_courses.pop_front();
            res.push_back(c);
            for (auto edge : graph[c]) {
                int to = edge.second;
                in_edges[to]--;
                if (in_edges[to] == 0) {
                    free_courses.push_back(to);
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
