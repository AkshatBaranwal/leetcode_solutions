class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int cnt = 0;
    
    MedianFinder() {
        while(!maxHeap.empty())
            maxHeap.pop();
        
        while(!minHeap.empty())
            minHeap.pop();
        
        cnt = 0;
    }
    
    void balance()
    {
        if(minHeap.size()>maxHeap.size())
            maxHeap.push(minHeap.top()),
            minHeap.pop();
        
        if(maxHeap.size() == minHeap.size()+2)
            minHeap.push(maxHeap.top()),
            maxHeap.pop();
    }
    
    void addNum(int num) {
        if(maxHeap.empty())
            maxHeap.push(num);
        else
        {
            if(maxHeap.top()>=num)
                maxHeap.push(num);
            else
                minHeap.push(num);
            balance();
        }
        
        cnt++;
    }
    
    double findMedian() {
        if(cnt&1)
            return maxHeap.top();
        else
        {
            double ans = minHeap.top()+maxHeap.top();
            ans/=2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
