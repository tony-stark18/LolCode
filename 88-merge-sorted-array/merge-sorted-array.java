class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int temp[] = new int[m+n];
        int p1 = 0;
        int p2 = 0;
        int k =0;
        while(p1<m && p2<n){
            if(nums1[p1]<nums2[p2]){
                temp[k]=nums1[p1];
                p1++;
            }
            else{
                temp[k] = nums2[p2];
                p2++;
            }
            k++;
        }
        while(p1<m){
            temp[k++] = nums1[p1++];
        }
        while(p2<n){
            temp[k++] = nums2[p2++];
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=temp[i];
        }
    }
}