def fill(img: List[List[int]], i: int, j: int, og_clr: int, clr: int) -> None:
    if  (0 <= i < len(img)) and (0 <= j < len(img[0])) and (img[i][j] == og_clr):
        img[i][j] = clr
        fill(img, i - 1, j, og_clr, clr)
        fill(img, i + 1, j, og_clr, clr)
        fill(img, i, j - 1, og_clr, clr)
        fill(img, i, j + 1, og_clr, clr)

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        og_clr = image[sr][sc]
        if (og_clr == color):
            return image

        fill(image, sr, sc, og_clr, color)
        return image


