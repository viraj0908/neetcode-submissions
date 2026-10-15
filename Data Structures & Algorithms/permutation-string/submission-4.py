class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1 = [0]*26
        for c in s1:
            mp1[ord(c) - ord('a')] += 1
        mp2 = [0]*26
        i,j= 0 ,0
        while j < len(s2):
            mp2[ord(s2[j]) - ord('a')] += 1
            while i <= j and mp2[ord(s2[j]) - ord('a')] > mp1[ord(s2[j]) - ord('a')] :
                mp2[ord(s2[i]) - ord('a')] -= 1
                i+=1
            if (j - i + 1)  == len(s1) :
                return True
            j+=1
        return False


