class Solution {
    public int maxConsecutiveCharK(char arr[],int k,int ch){
        int left = 0;
        int right = 0;
        int ans = Integer.MIN_VALUE;
        int t = 0;
        while(right<arr.length){
            if(arr[right]!=ch) t++;
            if(t>k){
                while(left<=right && arr[left]==ch){
                    left++;
                }
                left++;
                t--;
            }
            ans = Math.max(ans,right-left+1);
            right++;
        }
        return ans;
    }
    public int maxConsecutiveAnswers(String answerKey, int k) {
        char arr[] = answerKey.toCharArray();
        return Math.max(maxConsecutiveCharK(arr,k,'T'),maxConsecutiveCharK(arr,k,'F'));
    }
}