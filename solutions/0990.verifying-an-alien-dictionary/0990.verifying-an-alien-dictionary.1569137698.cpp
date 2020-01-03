class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int N = 26;
        vector<int> mapping(N, 0);
        for (int i = 0; i < N; i++) {
            mapping[order[i] - 'a'] = i;
        }
        
        string last = "";
        for (string& word : words) {
            string current = word;
            for (char& c : current) {
                c = 'a' + mapping[c-'a'];
            }
            if (last != "") {
                if (last > current) {
                    return false;
                }
            }
            last = current;
        }
        return true;
    }
};
