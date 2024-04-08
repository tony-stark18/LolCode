class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        for(int num:nums2){
            while(!st.isEmpty() && st.peek()<num){
                hs.put(st.pop(),num);
            }
            st.push(num);
        }
        int ans[] = new int[nums1.length];
        Arrays.fill(ans,-1);
        for(int i=0;i<nums1.length;i++){
            if(hs.containsKey(nums1[i])){
                ans[i]=hs.get(nums1[i]);
            }
        }
        return ans;
    }
}