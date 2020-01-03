class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26, 0);
        for (char c : tasks) {
            counter[c-'A']++;
        }
        int mfreq = 0;
        for (int count : counter) {
            mfreq = max(mfreq, count);
        }
        int modes = 0;
        for (int count : counter) {
            if (count == mfreq) {
                modes++;
            }
        }
        return max((int) tasks.size(), modes + (mfreq - 1) * (n + 1));
    }
};
