class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        v1 , v2 = {},{}
        for i in range(len(s)):
            v1[s[i]] = 1 + v1.get(s[i],0)
            v2[t[i]] = 1 + v2.get(t[i],0)
        return v1 == v2
        