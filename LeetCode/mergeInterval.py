# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) < 1:
            return intervals
        
        mergeIntervals = []
        sortedIntervals = sorted(intervals, key=lambda x: x.start)
        start = sortedIntervals[0].start
        end = sortedIntervals[0].end
        for interval in sortedIntervals:
            #overlapping intervals, update end
            if (interval.start <= end):
                end = max(end, interval.end)
            #not overlapping so reset start and end values
            else:
                mergeIntervals.append([start, end])
                start = interval.start
                end = interval.end
        
        mergeIntervals.append([start, end])
        return mergeIntervals
