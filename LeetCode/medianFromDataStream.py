#O(logN) to insert element, O(1) to find median
from heapq import *
class MedianFinder(object):
    
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.heaps = [], []
        #small is for smaller numbers and is max heap
        #large is for larger numbers and is min heap
        #python is default min heap, so we negate numbers to make a max heap

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        small, large = self.heaps
        heappush(large, num)
        #convert to negative number in order to be a max heap
        heappush(small, -heappop(large))
        if len(large) < len(small):
            #convert negative back to positive number and push to large/min heap
            heappush(large, -heappop(small))     

    def findMedian(self):
        """
        :rtype: float
        """
        small, large = self.heaps
        if len(large) > len(small):
            return float(large[0])
        else:
            #subtract to find average because small will be negative number
            return (large[0]-small[0])/2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()