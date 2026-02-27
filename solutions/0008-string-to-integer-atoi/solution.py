class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()

        if not s:
            return 0

        sign = 1
        i = 0
        number = 0

        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
        
        while i<len(s) and s[i].isdigit():
            digit = int(s[i])
            number = number*10 + digit
            i += 1

        number = sign*number

        if number<-(2**31):
            number = -(2**31)
        elif number> 2**31 - 1:
            number = 2**31 - 1

        return number
