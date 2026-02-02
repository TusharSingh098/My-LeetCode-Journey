class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if (num <= 0) or (num % 10 != 6) and (num % 100 != 28):
            return False

        sum = 1
        for i in range(2, int(num ** 0.5) + 1):
            if (num % i == 0):
                sum += i
                if (i * i != num):
                    sum += num / i
        return sum == num
