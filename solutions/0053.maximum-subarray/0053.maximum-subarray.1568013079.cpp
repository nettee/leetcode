class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // subproblem:
        // msa(a, k): max subarray ending with a[k]
        // msa(a) = max{ mas(a, k) } for k in [0..N)
        
        // msa(a, 0) = a[0]
        // msa(a, k) = max{ a[k], msa(a, k-1) + a[k] }
        //           = a[k] + max{ 0, msa(a, k-1) }
        
        int N = nums.size();
        
        int last = nums[0];
        int msa = last;
        for (int k = 1; k < N; k++) {
            last = nums[k] + max(0, last);
            msa = max(msa, last);
        }
        
        return msa;
    }
};
