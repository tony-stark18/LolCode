class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        return max(rect1[0], rect2[0]) < min(rect1[2], rect2[2]) &&
               max(rect1[1], rect2[1]) < min(rect1[3], rect2[3]);
    }
};
