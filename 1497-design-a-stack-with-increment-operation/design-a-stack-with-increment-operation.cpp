class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
    int maxSize;
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        st.resize(0);
        inc.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
        }
    }
    
    int pop() {
        int idx = st.size() - 1;
        if (idx < 0) return -1;
        
        if (idx > 0) {
            inc[idx - 1] += inc[idx]; 
        }
        int res = st.back() + inc[idx];
        inc[idx] = 0; 
        st.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int idx = min(k, (int)st.size()) - 1; 
        if (idx >= 0) {
            inc[idx] += val; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
