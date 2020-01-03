class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        // subproblem:
        // ways(s, k): the number of ways to decode s[0..k)
        // numDecodings(s) = ways(s, s.length())
        //
        // ways(s, 0) = 1
        // ways(s, 1) = 1
        // ways(s, k) = ways(s, k-1) + ways(s, k-2) , if s[k-2, k) is valid
        //              ways(s, k-1)                , otherwise
        int N = s.length();
        int* ways = new int[N+1];
        ways[0] = 1;
        ways[1] = 1;
        for (int k = 2; k <= N; k++) {
            ways[k] = 0;
            if (valid(s[k-1])) {
                ways[k] += ways[k-1];
            }
            if (valid(s[k-2], s[k-1])) {
                ways[k] += ways[k-2];
            }
        }
        return ways[N];
    }
    
    bool valid(char single) {
        return single != '0';
    }
    
    bool valid(char hi, char lo) {
        return hi == '1'
            || hi == '2' && '0' <= lo && lo <= '6';
    }
};
