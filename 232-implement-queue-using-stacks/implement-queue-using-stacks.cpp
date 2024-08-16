class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return pop();
        }
    }

    int peek() {
        if (!s2.empty()) {
            int val = s2.top();
            return val;
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return peek();
        }
    }

    bool empty() { return s2.empty() && s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */