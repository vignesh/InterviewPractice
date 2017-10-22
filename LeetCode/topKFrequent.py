class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        frequencyMapping = {}
        for num in nums:
            if num not in frequencyMapping:
                frequencyMapping[num] = 1
            else:
                frequencyMapping[num] += 1
                
        heap = []
        for number, frequency in frequencyMapping.items():
            #sorts by first variable automatically in thise case frequency
            #multiply frequency times -1 for max heap
            heapq.heappush(heap,[frequency*-1,number])  
        result = []
        while k > 0:
            item = heapq.heappop(heap)
            frequency = item[0]
            number = item[1]
            result.append(number)
            k-=1
        return result
        