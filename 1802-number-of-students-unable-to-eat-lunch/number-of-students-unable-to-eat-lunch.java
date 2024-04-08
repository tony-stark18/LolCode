class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> q = new LinkedList<>();
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<students.length;i++){
            q.add(students[i]);
            st.push(sandwiches[sandwiches.length-1-i]);
        }
        int count = 0;
        while(!q.isEmpty() && count!=q.size()){
            if(q.peek()==st.peek()){
                q.remove();
                st.pop();
                count=0;
            }
            else{
                count++;
                q.add(q.remove());
            }
        }
        return q.size();
    }
}