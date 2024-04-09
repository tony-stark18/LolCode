import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Map<Integer, Integer> ticketCounts = new HashMap<>();
        Queue<Integer> q = new LinkedList<>();
        
        // Populate the ticketCounts map and the queue
        for (int i = 0; i < tickets.length; i++) {
            ticketCounts.put(i, tickets[i]);
            q.add(i);
        }
        
        int count = 0;
        while (!q.isEmpty()) {
            int t = q.remove();
            count++;
            ticketCounts.put(t, ticketCounts.get(t) - 1); // Decrement the count for the ticket
            
            if (ticketCounts.get(k) == 0) // Check if the desired ticket is available
                return count;
            
            if (ticketCounts.get(t) != 0) // Check if there are more tickets of this type
                q.add(t);
        }
        
        return count;
    }
}
