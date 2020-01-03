class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sa.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (sb.empty()) {
            while (!sa.empty()) {
                sb.push_back(sa.back());
                sa.pop_back();
            }
        }
        int e = sb.back();
        sb.pop_back();
        return e;
    }
    
    /** Get the front element. */
    int peek() {
        if (sb.empty()) {
            while (!sa.empty()) {
                sb.push_back(sa.back());
                sa.pop_back();
            }
        }
        return sb.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sa.empty() && sb.empty();
    }
    
private:
    deque<int> sa;
    deque<int> sb;
    
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
