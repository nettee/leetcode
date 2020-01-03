class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size();
        if (allNines(digits)) {
            vector<int> res(N+1, 0);
            res[0] = 1;
            return res;
        }
        
        vector<int> res(N, 0);
        int carry = 1;
        for (int k = N-1; k >= 0; k--) {
            int s = digits[k] + carry;
            res[k] = s % 10;
            carry = s / 10;
        }
        return res;
    }
    
    bool allNines(vector<int>& digits) {
        for (int d : digits) {
            if (d != 9) {
                return false;
            }
        }
        return true;
    }
};
