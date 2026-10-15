class Solution: 
    def isPalindrome(self, s: str) -> bool:
        res = ""
        for c in s:
            if c >= 'A' and c <= 'z' or c >= '0' and c <= '9':
                res += c.lower()
        print(res)
        for i in range(len(res)//2):
            if res[i] != res[len(res) - 1 - i] :
                return False
        return True
