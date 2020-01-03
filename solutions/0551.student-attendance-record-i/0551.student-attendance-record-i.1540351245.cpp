/*
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (44.99%)
 * Total Accepted:    41.1K
 * Total Submissions: 91.4K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).    
 * 
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 * 
 * Example 1:
 * 
 * Input: "PPALLP"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "PPALLL"
 * Output: False
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool checkRecord(string s) {
        int ac = 0; // A count
        int mlc = 0; // max L count
        int clc = 0; // current L count;
        bool cl = false; // continuous L
        for (char c : s) {
            if (c == 'A') {
                ac++;
            } 
            if (cl && c == 'L') {
                clc++;
            } else if (cl && c != 'L') {
                cl = false;
                if (clc > mlc) {
                    mlc = clc;
                }
                clc = 0;
            } else if (!cl && c == 'L') {
                cl = true;
                clc++;
            }
        }
        if (cl) {
            if (clc > mlc) {
                mlc = clc;
            }
        }
        return ac <= 1 && mlc <= 2;
    }
};

