class Solution {
    public int soln(int[] nums,int ind,int dp[]){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind]+soln(nums,ind-2,dp);
        int npick = 0+soln(nums,ind-1,dp);
        return dp[ind] = Math.max(pick,npick);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1) return nums[0];
        int dp[] = new int[n];
        int arr1[] = new int[n-1]; 
        int arr2[] = new int[n-1];
        int k=0;
        int l=0;
        for(int i=0;i<n;i++){
            if(i!=0){
                arr1[k++]=nums[i];
            }
            if(i!=n-1){
                arr2[l++] = nums[i];
            }
        } 
        Arrays.fill(dp,-1);
        int ans1 = soln(arr1,n-2,dp);
        Arrays.fill(dp,-1);
        int ans2 = soln(arr2,n-2,dp);
        return Math.max(ans1,ans2);

    }
}