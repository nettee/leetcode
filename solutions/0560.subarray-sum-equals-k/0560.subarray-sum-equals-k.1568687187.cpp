class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> presum;
        presum[0] = 1;
        
        int count = 0;
        int sum = 0;
        for (int n : nums) {
            sum += n;
            if (presum.find(sum - k) != presum.end()) {
                count += presum[sum - k];
            }
            presum[sum]++;
        }
        
        return count;
    }
};
