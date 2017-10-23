# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        start = newInterval.start
        end = newInterval.end
        left = 0
        right = 0
        result = []
        while right < len(intervals):
            currentStart = intervals[right].start
            currentEnd = intervals[right].end
            #new start time is less than right end time
            if start <= currentEnd:
                if end < currentStart:
                    #new Interval is within a current interval
                    break
                #get earliest Start
                start = min(start,currentStart)
                #get latest End
                end = max(end, currentEnd)
            #only increment if we move to next interval that is not in range of new interval
            else:
                left+=1
            right+=1
        return intervals[:left] + [Interval(start,end)] + intervals[right:]