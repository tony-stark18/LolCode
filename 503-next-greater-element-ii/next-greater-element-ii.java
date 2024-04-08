class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> hs = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<2*n-1;i++){
            while(!st.isEmpty() && nums[st.peek()]<nums[i%n]){
                if(!hs.containsKey(st.peek())){
                    hs.put(st.peek(),nums[i%n]);
                }
                st.pop();
            }
            st.push(i%n);
        }
        int ans[] = new int[n];
        Arrays.fill(ans,-1);
        for(int i=0;i<n;i++){
            if(hs.containsKey(i)) ans[i]=hs.get(i);
        }
        return ans;
    }
}