#O(nlogn) solution for priority queue and mapping 
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        mapping = {}
        
        for char in s:
            if char not in mapping:
                mapping[char] = 1
            else:
                mapping[char] += 1
        
        h = []
        for number, frequency in mapping.items():
            #multiply by -1 to make it a max heap, default is min heap in python
            heapq.heappush(h, (frequency*-1, number))
        
        result = ""
        while len(h) > 0:
            current = heapq.heappop(h)
            frequency = current[0]*-1
            number = current[1]
            for i in range(0,frequency):
                result+=number
        return result
        