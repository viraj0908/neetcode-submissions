class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = set()
        i ,j = 0,0
        ans = 0
        while j < len(s):
            if s[j] in window:
                while s[j] in window:
                    window.remove(s[i])
                    i+=1
            window.add(s[j])
            ans = max(ans,j-i+1)
            j+=1
        return ans