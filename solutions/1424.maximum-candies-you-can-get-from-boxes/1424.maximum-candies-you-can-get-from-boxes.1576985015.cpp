class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int totalCandies = 0;
        
        queue<int> bq;
        queue<int> bq2;
        for (int b : initialBoxes) {
            bq.push(b);
        }
        
        unordered_set<int> keyset;
        
        // When you can open a box:
        // case 1. it is open. status[i] == 1
        // case 2. it is closed, but you have a key
        
        bool hasNewOpen = false;
        do {
            hasNewOpen = false;
            while (!bq.empty()) {
                int box = bq.front(); bq.pop();
                // open this box
                if (status[box] == 1 || keyset.find(box) != keyset.end()) {
                    hasNewOpen = true;
                    // get candies
                    totalCandies += candies[box];
                    // get keys
                    for (int k : keys[box]) {
                        keyset.insert(k);
                    }
                    // get boxes
                    for (int b : containedBoxes[box]) {
                        bq.push(b);
                    }
                } else {
                    // no keys currently
                    bq2.push(box);
                }
            }
            swap(bq, bq2);
        } while (hasNewOpen);
        
        return totalCandies;
    }
};
