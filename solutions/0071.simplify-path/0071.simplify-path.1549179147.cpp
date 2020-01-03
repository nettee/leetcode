class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts = split(path);
        deque<string> st;
        for (int i = 1; i < parts.size(); i++) {
            string part = parts[i];
            if (part.empty()) {
                // do nothing
            } else if (part == ".") {
                // do nothing
            } else if (part == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(part);
            }
        }
        if (st.empty()) {
            return "/";
        } else {
            string res;

            for (string part : st) {
                res += '/';
                res += part;
            }
            return res;
        }
    }
    
    vector<string> split(string path) {
        int N = path.length();
        vector<string> res;
        int i = 0;
        while (i < N) {
            if (path[i] == '/') {
                res.push_back("");
                i++;
            } else {
                int j = i;
                while (j < N && path[j] != '/') {
                    j++;
                }
                res.push_back(string(path, i, j-i));
                i = j + 1;
            }
        }
        return res;
    }
};
