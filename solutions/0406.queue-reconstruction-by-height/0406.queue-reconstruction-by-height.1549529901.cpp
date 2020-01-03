class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), []
                (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first > rhs.first
                || lhs.first == rhs.first && lhs.second < rhs.second;
        });
        vector<pair<int, int>> res;
        for (auto p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};
