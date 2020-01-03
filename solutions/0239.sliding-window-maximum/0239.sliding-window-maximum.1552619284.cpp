class MonoQueue {
public:
    void push(int val) {
        int count = 0;
        while (!vals.empty() && vals.back() < val) {
            count += dels.back() + 1;
            dels.pop_back();
            vals.pop_back();
        }
        vals.push_back(val);
        dels.push_back(count);
    }
    
    void pop() {
        if (dels.front() > 0) {
            --dels.front();
        } else {
            dels.pop_front();
            vals.pop_front();
        }
    }
    
    int max() {
        return vals.front();
    }
private:
    deque<int> vals;
    deque<int> dels;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) {
            return vector<int>();
        }
        vector<int> res;
        MonoQueue mq;
        int N = nums.size();
        if (k > N) {
            k = N;
        }
        for (int i = 0; i < k; i++) {
            mq.push(nums[i]);
        }
        res.push_back(mq.max());
        for (int i = k; i < N; i++) {
            mq.push(nums[i]);
            mq.pop();
            res.push_back(mq.max());
        }
        return res;
    }
};
