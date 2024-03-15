class Solution {
    public int[] productExceptSelf(int[] nums) {
        int sprod = 1;
        int nprod = -1;
        int count = 0;
        int n= nums.length;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                count++;
                nprod=sprod;
            }
            sprod*=nums[i];
        }
        int arr[] = new int[n];
        if(count>1) return arr;
        int pprod = 1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                arr[i]=pprod*nprod;
            }
            else{
                arr[i] = sprod/nums[i];
            }
            pprod*=nums[i];
        }
        return arr;
    }
}