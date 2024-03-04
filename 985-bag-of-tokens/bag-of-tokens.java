class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int score = 0;
        int maxScore = 0;
        int left = 0;
        int n = tokens.length;
        int right = n-1;
        Arrays.sort(tokens);
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
}