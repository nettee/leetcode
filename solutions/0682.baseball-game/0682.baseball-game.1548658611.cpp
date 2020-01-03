class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        vector<int> st;
        for (string op : ops) {
            if (op == "C") {
                sum -= st.back();
                st.pop_back();
            } else if (op == "D") {
                int score = st.back() * 2;
                sum += score;
                st.push_back(score);
            } else if (op == "+") {
                int score = st[st.size()-1] + st[st.size()-2];
                sum += score;
                st.push_back(score);
            } else {
                int score = stoi(op);
                sum += score;
                st.push_back(score);
            }
        }
        return sum;
    }
};
