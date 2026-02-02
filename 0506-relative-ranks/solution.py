class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        abs_scores = sorted(score, reverse=True)
        total = len(abs_scores)

        if (total == 1):
            return ["Gold Medal"]
        elif (total == 2) and (score[0] > score[1]):
            return ["Gold Medal", "Silver Medal"]
        elif (total == 2):
            return ["Silver Medal", "Gold Medal"]


        rankings = {}
        rankings[abs_scores[0]] = "Gold Medal"
        rankings[abs_scores[1]] = "Silver Medal"
        rankings[abs_scores[2]] = "Bronze Medal"

        
        for i in range(3, total):
            rankings[abs_scores[i]] = str(i + 1)
        
        standings = []
        for i in score:
            standings.append(rankings[i])
        return standings
