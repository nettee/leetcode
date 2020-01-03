class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int N = candies.size();
        unordered_set<int> s(candies.begin(), candies.end());
        return min((int) s.size(), N/2);
    }
};
