#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    for (int value : values)
    {
        minHeap.push(value);
        
        if (minHeap.size() > (size_t)k)
        {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}

