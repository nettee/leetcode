class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        sumTo.push_back(sum);
        for (int n : nums) {
            sum += n;
            sumTo.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return sumTo[j+1] - sumTo[i];
    }
    
private:
    vector<int> sumTo;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
