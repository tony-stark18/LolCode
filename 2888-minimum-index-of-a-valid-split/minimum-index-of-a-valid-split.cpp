class Solution {
public:
    int getMajority(vector<int> &nums,vector<int> &fromLeft,vector<int> &fromRight){
        int n = nums.size();
        int countL=0,countR = 0;
        int meL = -1;
        int meR = -1;
        for(int i=0;i<n;i++){
            if(countL==0){
                countL=1;
                meL = nums[i];
            } else{
                if(nums[i]==meL) countL++;
                else countL--;
            }
            fromLeft[i]=(countL>0)?meL:-1;
            if(countR==0){
                countR = 1;
                meR = nums[n-i-1];
            } else{
                if(nums[n-1-i]==meR) countR++;
                else countR--;
            }
            fromRight[n-i-1]=(countR>0)?meR:-1;
        }
        return meL;
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromLeft(n),fromRight(n);
        // unordered_map<int,int> map,map2;
        int me = getMajority(nums,fromLeft,fromRight);
        int count = 0,count2 = 0;
        for(int i=0;i<n;i++) count+=nums[i]==me;
        // cout<<me<<endl;
        for(int i=0;i<n-1;i++){
            count2+=nums[i]==me;
            if(fromLeft[i]==me && count2*2>i+1 && fromRight[i+1]==me && (count-count2)*2>n-i-1) return i;
            // cout<<i<<" "<<fromLeft[i]<<" "<<fromRight[i]<<", ";
        }
        return -1;
    }
};