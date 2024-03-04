class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int score = 0;
        int maxScore = 0;
        int left = 0;
        int n = tokens.length;
        int right = n-1;
        quicksort(tokens,0,n-1);
        while(left<=right){
            while(left<=right && power>=tokens[left]){
                score++;
                power-=tokens[left];
                left++;
            }
            if(score==0) return 0;
            maxScore = Math.max(score,maxScore);
            if(score>0){
                score--;
                power+=tokens[right];
                right--;
                maxScore = Math.max(score,maxScore);
            }
        }
        return maxScore;
    }
     private void quicksort(int[] arr, int left, int right) 
    {
        if (left < right) 
        {
            int pivotIndex = partition(arr, left, right);
            quicksort(arr, left, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, right);
        }
    }
    private int partition(int[] arr, int left, int right) 
    {
        int pivotValue = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) 
        {
            if (arr[j] < pivotValue) 
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
        return i + 1;
    }
}