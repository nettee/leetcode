class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int qn = queries.size();
        int wn = words.size();
        vector<int> wordfs;
        for (string& w : words) {
            wordfs.push_back(f(w));
        }
        
        sort(wordfs.begin(), wordfs.end());
        
        vector<int> res;
        for (string& q : queries) {
            int fq = f(q);
            res.push_back(place(fq, wordfs));
        }
        
        return res;
    }
    
    int place(int fq, vector<int>& wordfs) {
        return wordfs.end() - upper_bound(wordfs.begin(), wordfs.end(), fq);
    }
    
    int f(string& s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> counter(26, 0);
        for (char c : s) {
            counter[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0) {
                return counter[i];
            }
        }
        return 0;
    }
};
