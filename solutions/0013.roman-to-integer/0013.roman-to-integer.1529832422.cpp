class Solution {
public:
    int romanToInt(string s) {
        int N = s.length();
        int i = 0;
        int sum = 0;
        while (i < N) {
            if (i == N - 1 
                    || number(s[i]) >= number(s[i+1])) {
                sum += number(s[i]);
                cout << s[i] << endl;
                i += 1;
            } else {
                sum += number(s[i+1]) - number(s[i]);
                cout << s[i] << s[i+1] << endl;
                i += 2;
            }
        }
        return sum;
    }
private:
    int number(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
};
