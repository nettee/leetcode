class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s(candies.begin(), candies.end());
        return min(s.size(), candies.size() / 2);
    }
};
