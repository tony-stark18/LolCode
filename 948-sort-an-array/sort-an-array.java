class Solution {
    public void mergeSort(int[] nums,int start,int end){
        if(start==end){
            return;
        }
        int mid = (start+end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    public void merge(int[] nums,int start,int mid,int end){
        int left = start;
        int right = mid+1;
        int arr[] = new int[end-start+1];
        int k = 0;
        while(left<=mid && right<=end){
            if(nums[left]<nums[right]){
                arr[k]=nums[left];
                left++;
            }
            else{
                arr[k] = nums[right];
                right++;
            }
            k++;
        }
        while(left<=mid){
            arr[k++]=nums[left];
            left++;
        }
        while(right<=end){
            arr[k++] = nums[right];
            right++;
        }
        for(int i=start;i<=end;i++){
            nums[i]=arr[i-start];
        }
    }
    public int[] sortArray(int[] nums) {
        // mergeSort(nums,0,nums.length-1);
        Arrays.sort(nums);
        return nums;
    }
}