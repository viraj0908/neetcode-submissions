class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = [0]*26
        i,j,maxf,ans = 0,0,0,0
        while j < len(s):
            mp[ord(s[j]) - ord('A')] += 1
            maxf = max(maxf,mp[ord(s[j]) - ord('A')])
            while (j - i + 1) - maxf > k :
                mp[ord(s[i]) - ord('A')] -= 1 
                maxf = 0
                for it in range(26):
                    maxf= max(maxf,mp[it])
                i+=1
            ans = max(ans,j-i+1)
            j+=1
        return ans
            