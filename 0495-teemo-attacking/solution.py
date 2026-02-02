class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries:
            return 0
            
        total = duration
        length = len(timeSeries) - 1
        for i in range(length):
            gap = timeSeries[i+1] - timeSeries[i]
            if gap < duration:
                total += gap
            else:
                total += duration
                
        return total
