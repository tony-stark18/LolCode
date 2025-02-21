class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        int x1 = rect1[0];
        int y1 = rect1[1];
        int x2 = rect1[2];
        int y2 = rect1[3];
        int xx1 = rect2[0];
        int yy1 = rect2[1];
        int xx2 = rect2[2];
        int yy2 = rect2[3];
        if(xx1>x1){
            if(yy1>y1){
                return xx1<x2 && yy1<y2;
            }
            if(y1>yy1){
                return xx1<x2 && y1<yy2;
            }
            return xx1<x2;
        }
        if(x1>xx1){
            if(yy1>y1){
                return xx2>x1 && yy1<y2;
            }
            if(y1>yy1){
                return xx2>x1 && y1<yy2;
            }
            return xx2>x1;
        }
        else{
            if(yy1>y1){
                return yy1<y2;
            }
            if(y1>yy1){
                return y1<yy2;
            }
        }
        return false;
    }
};