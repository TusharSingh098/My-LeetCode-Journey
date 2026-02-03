class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        if len(list1) < len(list2):
            list1, list2 = list2, list1

        lookup = {res: i for i, res in enumerate(list2)}
        result = []
        minimum = float('inf')

        for i1, res in enumerate(list1):
            if i1 > minimum: 
                break

            if (res in lookup):
                idx_sum = i1 + lookup[res]
                if (idx_sum == minimum):
                    result.append(res)
                elif (idx_sum < minimum):
                    minimum = idx_sum
                    result.clear()
                    result = [res]
        return result

