class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        for(int i:chalk){
            sum+=i;
        }
        if(sum==k) return 0;
        if(sum>k){
            for(int i=0;i<chalk.size();i++){
                k-=chalk[i];
                if(k<0) return i;
            }
        }
        else{
            int rem = k%sum;
            for(int i=0;i<chalk.size();i++){
                rem-=chalk[i];
                if(rem<0) return i;
            }
        }
        return -1;
    }
};