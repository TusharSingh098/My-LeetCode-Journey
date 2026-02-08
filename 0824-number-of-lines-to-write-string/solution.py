class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        n_lines = 1
        width = 0
        for i in s:
            width += widths[ord(i) -97]
            if (width > 100):
                n_lines += 1
                width = widths[ord(i) -97]
        return [n_lines, width]
            
