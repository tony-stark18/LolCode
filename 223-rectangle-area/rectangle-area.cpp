class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ov_x1 = max(ax1,bx1);
        int ov_x2 = min(ax2,bx2);
        int ov_y1 = max(ay1,by1);
        int ov_y2 = min(ay2,by2);
        int ans = (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
        // int ov_area = 0;
        if(ov_x2>ov_x1 && ov_y2>ov_y1){
            ans-=((ov_x2-ov_x1)*(ov_y2-ov_y1));
        }
        return ans;
    }
};