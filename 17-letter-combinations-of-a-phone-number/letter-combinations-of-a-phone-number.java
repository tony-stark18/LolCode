class Solution {
    public void soln(String digits,HashMap<Character,String> hs,List<String> ans,String s,int n){
        int i = s.length();
        if(i>n) return;
        if(i==n){
            if(i!=0)
                ans.add(s);
            return;
        }
        String str = hs.get(digits.charAt(i));
        for(int itr=0;itr<str.length();itr++){
            soln(digits,hs,ans,s+str.charAt(itr),n);
        }
    }
    public List<String> letterCombinations(String digits) {
        HashMap<Character,String> hs = new HashMap<>();
        hs.put('2',"abc");
        hs.put('3',"def");
        hs.put('4',"ghi");
        hs.put('5',"jkl");
        hs.put('6',"mno");
        hs.put('7',"pqrs");
        hs.put('8',"tuv");
        hs.put('9',"wxyz");
        List<String> ls = new ArrayList<>();
        soln(digits,hs,ls,"",digits.length());
        return ls;
    }
}