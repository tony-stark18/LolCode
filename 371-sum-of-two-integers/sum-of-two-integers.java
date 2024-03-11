class Solution {
    public int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;  // Calculate the carry by performing AND operation
            a = a ^ b;         // Add a and b without considering the carry using XOR
            b = carry << 1;     // Left shift the carry to the next position
        }
        return a;
    }
}