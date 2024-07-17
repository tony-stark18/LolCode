class MinStack {
public:
    stack<long long> st;
    long long min;
    
    MinStack() {
        min = LLONG_MAX; // Use long long max value to avoid overflow
    }
    
    void push(int val) {
        if (st.empty()) {
            min = val;
            st.push(val);
        } else {
            if (val >= min)
                st.push(val);
            else {
                st.push(2LL * val - min); // Use 2LL to promote to long long
                min = val; // Update min
            }
        }
    }
    
    void pop() {
        if (!st.empty()) {
            long long x = st.top();
            st.pop();
            if (x < min) {
                min = 2LL * min - x; // Use long long arithmetic
            }
        }
    }
    
    int top() { 
        long long x = st.top();
        if (x < min) return min; // Return the actual minimum value
        return x;
    }
    
    int getMin() { return min; }
};
