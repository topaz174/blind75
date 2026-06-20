/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        else if (minHeap.empty()) {
            minHeap.push(num);
            return;
        }

        if (num <= maxHeap.top()) {
            if (maxHeap.top() == minHeap.top()) {
                maxHeap.pop();
            }
            else {
                minHeap.push(maxHeap.top());
            }
            maxHeap.push(num);
        }
        else { 
            if (maxHeap.top() == minHeap.top()) {
                minHeap.pop();
            }
            else {
                maxHeap.push(minHeap.top());
            }
            minHeap.push(num);
        }

    }
    
    double findMedian() {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

