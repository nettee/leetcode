class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        N = 0;
    }
    
    void addNum(int num) {
        if (N % 2 == 0) {
            // insert it to left heap
            if (right_heap.empty() || right_heap.top() >= num) {
                left_heap.push(num);
            } else {
                left_heap.push(right_heap.top());
                right_heap.pop();
                right_heap.push(num);
            }
        } else {
            // insert it to right heap
            if (left_heap.empty() || left_heap.top() <= num) {
                right_heap.push(num);
            } else {
                right_heap.push(left_heap.top());
                left_heap.pop();
                left_heap.push(num);
            }
        }
        N++;
    }
    
    double findMedian() {
        if (N % 2 == 0) {
            return (left_heap.top() + right_heap.top()) / 2.0;
        } else {
            return left_heap.top();
        }
    }

private:
    int N;
    // Invariant:
    // 1. left_heap.size() - right_heap.size() == 0 or 1
    // 2. all elements in left heap are less than those in right heap
    priority_queue<int, vector<int>, less<int>> left_heap; // max heap
    priority_queue<int, vector<int>, greater<int>> right_heap; // min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
