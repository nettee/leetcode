class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        int sum = 0;
        int i = 0;
        while (i < N) {
            while (i < N && flowerbed[i] != 0) {
                i++;
            }
            int j = i;
            while (j < N && flowerbed[j] == 0) {
                j++;
            }
            if (i == 0 && j == N) {
                sum += (j - i + 1) / 2;
            } else if (i == 0 || j == N) {
                sum += (j - i) / 2;
            } else {
                sum += (j - i - 1) / 2;
            }
            i = j + 1;
        }
        return sum >= n;
    }
};
