class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        rows, cols = len(img), len(img[0])
        
        for i in range(rows):
            for j in range(cols):
                total_sum, count = 0, 0
                # Scan 3x3 neighborhood
                for r in range(max(0, i-1), min(rows, i+2)):
                    for c in range(max(0, j-1), min(cols, j+2)):
                        # Mask with 0xFF to get original value (first 8 bits)
                        total_sum += img[r][c] & 0xFF
                        count += 1
                
                # Store smoothed value in next 8 bits (bits 8-15)
                img[i][j] |= (total_sum // count) << 8
        
        # Final pass: Shift right to set the new values as the primary ones
        for i in range(rows):
            for j in range(cols):
                img[i][j] >>= 8
                
        return img

