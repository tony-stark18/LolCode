class Solution {
    public int soln(int[] nums2,int i){
        for(int itr=i;itr<nums2.length;itr++){
            if(nums2[itr]>nums2[i]) return nums2[itr];
        }
        return -1;
    }
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] ans = new int[nums1.length];
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                if(nums2[j]==nums1[i]){
                    ans[i]=soln(nums2,j);
                    break;
                }
            }
        }
        return ans;
    }
}