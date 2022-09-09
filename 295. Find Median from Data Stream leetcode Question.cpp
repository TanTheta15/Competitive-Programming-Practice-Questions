/*    295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
*/

#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int> max_heap; //maxHeap
    priority_queue<int, vector<int>, greater<int>> min_heap; //minHeap
    
    void addNum(int num) {
            
        if(max_heap.empty() || max_heap.top() > num){
            max_heap.push(num);
        }else{
            min_heap.push(num);
        }
        
        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size() + 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
       if(max_heap.size() == min_heap.size()){
           return (max_heap.top() + min_heap.top()) / 2.0;
       }
        else{
            if(max_heap.size() > min_heap.size()){
                return max_heap.top();
            }else{
                return min_heap.top();
            }
        }
    }
};
