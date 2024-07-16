class Solution {
public:
    // int soln(int area){
    //     if(area==0) return 1;
    //     if(area<0) return 0;
    //     int domino = soln(area-2)+soln(area-4);
    //     int tromino = soln(area-6);
    //     return domino+tromino;
    // }
    int numTilings(int n) {
        long mod = 1000000007;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        if(n==4) return 11;
        vector<long long> arr(n);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 5;
        arr[3] = 11;
        for(int i=4;i<n;i++){
            arr[i] = (arr[i-1]+arr[i-2]*2+arr[i-3]+arr[i-4])%mod;
        }
        return arr[n-1];
    }
};