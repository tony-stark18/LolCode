class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<tickets.length;i++){
            q.add(i);
        }
        int count = 0;
        while(!q.isEmpty()){
            int t = q.remove();
            count++;
            tickets[t]--;
            if(tickets[k]==0) return count;
            if(tickets[t]!=0){
                q.add(t);
            }
        }
        return count;
    }
}