class Solution {
public:
    double getLength(vector<int>& p1,vector<int> &p2){
        return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) { 
        double l1 = getLength(p1,p2);
        double l2 = getLength(p1,p3);
        double l3 = getLength(p1,p4);
        double l4 = getLength(p2,p3);
        double l5 = getLength(p2,p4);
        double l6 = getLength(p3,p4);
        cout<<l1<<", "<<l2<<", "<<l3<<", "<<l4<<", "<<l5<<", "<<l6;
        double lens[6] = {l1,l2,l3,l4,l5,l6};
        sort(lens,lens+6);
        double epsilon = 1e-9;
        if(l1+l2+l3+l4+l5+l6==0) return false;
        if (abs(lens[0] - lens[1]) < epsilon && 
            abs(lens[0] - lens[2]) < epsilon && 
            abs(lens[0] - lens[3]) < epsilon && 
            abs(lens[4] - lens[5]) < epsilon && 
            abs(lens[0] * sqrt(2) - lens[4]) < epsilon) {
            return true;
        }

        return false;
        // cout<<1.41421*sqrt(2);
        return false;
    }
};