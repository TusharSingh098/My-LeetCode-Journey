class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        height, width = len(image), len(image[0])
        for i in range(height):
            for j in range(width // 2):
                image[i][j], image[i][width - j - 1] = image[i][width - j - 1], image[i][j]
                if image[i][j]:
                    image[i][j] = 0
                else:
                    image[i][j] = 1

        for i in range(height):
            for j in range(width // 2, width):
                if image[i][j]:
                    image[i][j] = 0
                else:
                    image[i][j] = 1
        return image

