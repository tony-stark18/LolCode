class Solution {
    public void sort(int arr[]){
        int max = Arrays.stream(arr).max().orElse(Integer.MIN_VALUE);
        int min = Arrays.stream(arr).min().orElse(Integer.MAX_VALUE);

        int range = max - min + 1;
        int[] count = new int[range];

        for (int num : arr) {
            count[num - min]++;
        }
        int index = 0;
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                arr[index++] = i + min;
                count[i]--;
            }
        }
    }
    public int minMovesToSeat(int[] seats, int[] students) {
        sort(seats);
        sort(students);
        int res = 0;
        for(int i=0;i<seats.length;i++){
            res+=Math.abs(seats[i]-students[i]);
        }
        return res;
    }
}