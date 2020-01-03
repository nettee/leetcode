class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> aux(nums.size(), 0);
        return mergesort(nums, aux, 0, nums.size());
    }
    
    int mergesort(vector<int>& a, vector<int>& aux, int start, int end) {
        if (start >= end - 1) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int left = mergesort(a, aux, start, mid);
        int right = mergesort(a, aux, mid, end);
        int inner = merge(a, aux, start, mid, end);
        return left + right + inner;
    }
    
    int merge(vector<int>& a, vector<int>& aux, int start, int mid, int end) {
        int sum = 0;
        int count = 0;
        {
            int i = start;
            int j = mid;
            while (i < mid) {
                if (j < end && (long) a[i] > 2 * (long) a[j]) {
                    j++;
                    count++;
                } else {
                    sum += count;
                    i++;
                }
            }
        }
        
        int i = start;
        int j = mid;
        int k = start;
        while (i < mid || j < end) {
            if (i == mid) {
                aux[k++] = a[j++];
            } else if (j == end) {
                aux[k++] = a[i++];
            } else if (a[i] <= a[j]) {
                aux[k++] = a[i++];
            } else {
                aux[k++] = a[j++];
            }
        }
        
        for (int l = start; l < end; l++) {
            a[l] = aux[l];
        }
        
        return sum;
    }
};
