class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        if(!minHeap.empty() && maxHeap.top()>minHeap.top()){
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }
        if(maxHeap.size()>minHeap.size() + 1){
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()){
            return (double)maxHeap.top();
        }
        else if(maxHeap.size()<minHeap.size()){
            return (double)minHeap.top();
        }
        double a = maxHeap.top();
        double b = minHeap.top();
        return (double)(a+b)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */