class CustomStack {
public:
    int maxSize;
    stack<int> st;
    int size;
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        size = 0; 
    }
    
    void push(int x) {
        if (size >= maxSize) return; // Fix: Prevent exceeding maxSize
        st.push(x);
        size++;
    }
    
    int pop() {
        if (st.empty()) return -1;
        int val = st.top();
        st.pop();
        size--;  
        return val;  
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        int count = 0; 
        while (!temp.empty() && count < k) {
            st.push(temp.top() + val);
            temp.pop();
            count++;
        }
        
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 **/