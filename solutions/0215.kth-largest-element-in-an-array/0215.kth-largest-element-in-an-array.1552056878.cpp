class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Make heap of size k
        vector<int> heap(nums.begin(), nums.begin() + k);
        make_heap(heap.begin(), heap.end(), greater<int>());
        
        // Push elements, keep heap size as k
        for (int i = k; i < nums.size(); i++) {
            heap.push_back(nums[i]);
            push_heap(heap.begin(), heap.end(), greater<int>());
            pop_heap(heap.begin(), heap.end(), greater<int>());
            heap.pop_back();
        }
        
        return heap.front();
    }
};
