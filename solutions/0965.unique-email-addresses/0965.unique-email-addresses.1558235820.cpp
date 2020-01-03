class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string& email : emails) {
            s.insert(canonicalize(email));
        }
        return s.size();
    }
    
    string canonicalize(string email) {
        int k = email.find('@');
        string local = email.substr(0, k);
        string domain = email.substr(k+1);
        int j = local.find('+');
        if (j != string::npos) {
            local.erase(local.begin() + j, local.end());
        }
        int i;
        while ((i = local.find('.')) != string::npos) {
            local.erase(local.begin() + i);
        }
        string res = local + "@" + domain;
        cout << res << endl;
        return res;
    }
};
