class Solution {
    public boolean checkRecord(String s) {
        int a=0;
        int l=1;
        int lm =0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='A'){
                a++;
            }
            
            if(i!=0 && s.charAt(i)=='L' && s.charAt(i-1)=='L'){
                l++;
                if(lm<l){
                    lm=l;
                }
            }
            else{
                l=1;
            }
            
        }
        System.out.println(lm);
        return a<2 && lm<3;
    }
}