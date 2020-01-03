class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (string word : words) {
            if (kr(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    bool kr(const string& word) {
        if (word.empty()) {
            return false;
        }
        int row = getRow(word[0]);
        for (char c : word) {
            if (getRow(c) != row) {
                return false;
            }
        }
        return true;
    }
    
    int getRow(char c) {
        if ('a' <= c && c <= 'z') {
            return getRow0(c);
        } else if ('A' <= c && c <= 'Z') {
            return getRow0('a' + (c - 'A'));
        } else {
            return 0;
        }
    }
    
    int getRow0(char c) {
        switch (c) {
            case 'q':
            case 'w':
            case 'e':
            case 'r':
            case 't':
            case 'y':
            case 'u':
            case 'i':
            case 'o':
            case 'p':
                return 1;
            case 'a':
            case 's':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
                return 2;
            case 'z':
            case 'x':
            case 'c':
            case 'v':
            case 'b':
            case 'n':
            case 'm':
                return 3;
            default:
                return 0;
        }
    }
};
