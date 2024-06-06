import java.util.*;

class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) return false;

        Arrays.sort(hand);
        Map<Integer, Integer> hs = new HashMap<>();
        for(int i:hand){
            hs.put(i,hs.getOrDefault(i,0)+1);
        }
        for(int i:hand){
            if(hs.get(i)==0) continue;
            for(int j=0;j<groupSize;j++){
                int curr = i+j;
                if(hs.getOrDefault(curr,0)==0) return false;
                hs.put(curr,hs.get(curr)-1);
            }
        }
        return true;

    }
}
