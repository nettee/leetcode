class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list2.size(); i++) {
            index[list2[i]] = i;
        }
        vector<string> res;
        int mini = list1.size() + list2.size();
        for (int i = 0; i < list1.size(); i++) {
            string word = list1[i];
            if (index.find(word) != index.end()) {
                if (i + index[word] < mini) {
                    res = vector<string>{word};
                    mini = i + index[word];
                } else if (i + index[word] == mini) {
                    res.push_back(word);
                }
            }
        }
        return res;
    }
};
