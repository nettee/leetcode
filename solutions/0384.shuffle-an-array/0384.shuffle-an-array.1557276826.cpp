class Solution {
public:
    Solution(vector<int>& nums) {
        a = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(a);
        int N = res.size();
        for (int i = 0; i < N; i++) {
            // Random in res[i..N)
            int j = i + rand() % (N - i);
            swap(res[i], res[j]);
        }
        return res;
    }

private:
    vector<int> a;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
