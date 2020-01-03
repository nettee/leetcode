class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        int N = A.size();
        
        vector<pair<int, int>> BB;
        for (int i = 0; i < N; i++) {
            BB.push_back(make_pair(B[i], i));
        }
        
        sort(BB.begin(), BB.end());
        
        vector<int> mapping(N, 0);
        for (int i = 0; i < N; i++) {
            mapping[i] = BB[i].second;
        }
        
        sort(A.begin(), A.end());
        vector<int> AA;
        
        int i = 0;
        int j = 0;
        vector<int> notused;
        while (i < N && j < N) {
            if (A[i] <= BB[j].first) {
                notused.push_back(A[i++]);
            } else {
                AA.push_back(A[i++]);
                j++;
            }
        }
        for (int n : notused) {
            AA.push_back(n);
        }      
        
        vector<int> res(N, 0);
        for (int i = 0; i < N; i++) {
            res[mapping[i]] = AA[i];
        }
        
        return res;
    }
};
