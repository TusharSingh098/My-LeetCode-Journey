digits = "0123456789abcdef"
mapping = {i: digits[i] for i in range(16)}
rev_mapping = {digits[i]: i for i in range(16)}

def add_one_hex(hex_str):
    hex_list = list(hex_str)
    carry = 1
    
    for i in range(len(hex_list) - 1, -1, -1):
        current_val = rev_mapping[hex_list[i]]
        total = current_val + carry
        
        if total < 16:
            hex_list[i] = mapping[total]
            carry = 0
            break
        else:
            hex_list[i] = "0"
            carry = 1
            
    if carry == 1:
        return "1" + "".join(hex_list)
    
    return "".join(hex_list)

def decimal_to_hexa(n):
    if (n == 0):
        return "0"
    result = ""
    while (n > 0):
        result = mapping[n % 16] + result
        n //= 16
    return result

class Solution:
    def toHex(self, num: int) -> str:
        if (num >= 0):
            return decimal_to_hexa(num)
        else:
            result = decimal_to_hexa(-num).zfill(8)
            flip_result = ""
            for i in result:
                flip_result += mapping[15 - rev_mapping[i]]

            return add_one_hex(flip_result) 
