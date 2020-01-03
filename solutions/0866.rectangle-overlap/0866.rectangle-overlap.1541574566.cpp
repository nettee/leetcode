/*
 * [866] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (44.37%)
 * Total Accepted:    13.1K
 * Total Submissions: 29.5K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are
 * the coordinates of its bottom-left corner, and (x2, y2) are the coordinates
 * of its top-right corner.
 * 
 * Two rectangles overlap if the area of their intersection is positive.  To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 * 
 * Given two (axis-aligned) rectangles, return whether they overlap.
 * 
 * Example 1:
 * 
 * 
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 * 
 * 
 * Notes:
 * 
 * 
 * Both rectangles rec1 and rec2 are lists of 4 integers.
 * All coordinates in rectangles will be between -10^9 and 10^9.
 * 
 * 
 */
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left1 = rec1[0];
        int bottom1 = rec1[1];
        int right1 = rec1[2];
        int top1 = rec1[3];
        int left2 = rec2[0];
        int bottom2 = rec2[1];
        int right2 = rec2[2];
        int top2 = rec2[3];
        bool xover = !(right2 <= left1) && !(left2 >= right1);
        bool yover = !(top2 <= bottom1) && !(bottom2 >= top1);
        return xover && yover;
    }
};

