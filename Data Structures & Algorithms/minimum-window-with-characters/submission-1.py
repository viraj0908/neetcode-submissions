class Solution:
    def is_valid(self,mp1,mp2) :
        for i,f in mp2.items():
            if mp1[i] < f:
                return False
        return True
    def minWindow(self, s: str, t: str) -> str:
        mp2 = defaultdict(int)
        for c in t:
            mp2[c]+=1
        mp1 = defaultdict(int)
        i , j , l , r = 0,0,0,len(s)
        while j < len(s):
            mp1[s[j]] += 1
            while self.is_valid(mp1,mp2) :
                if j - i + 1 <= r - l + 1:
                    r = j
                    l = i
                mp1[s[i]] -= 1
                i+=1
            j+=1
        if r == len(s):
            return ""
        else :
            return s[l : r+1]