class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++) {
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < N; i++) {
            int want = target - nums[i];
            if (m.count(want) > 0 && m[want] != i) {
                return vector<int>{i, m[want]};
            }
        }
        return vector<int>{-1, -1};
    }
};
