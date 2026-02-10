class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        min1x, max1x = rec1[0], rec1[2]
        min1y, max1y = rec1[1], rec1[3]

        min2x, max2x = rec2[0], rec2[2]
        min2y, max2y = rec2[1], rec2[3]

        if (min1x == max1x or min1y == max1y) or (min2x == max2x or min2y == max2y):
            return False

        return not (max1x <= min2x or
            min1x >= max2x or
            max1y <= min2y or
            min1y >= max2y)
