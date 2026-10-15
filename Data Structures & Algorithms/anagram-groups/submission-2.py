class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for s in strs:
            count = [0]*26
            for i in range(len(s)):
                count[ord(s[i])-ord('a')]+=1
            key = tuple(count)
            if key in mp:
                mp[key].append(s)
            else :
                mp[key] = [s]
        ans = []
        for key,val in mp.items():
            ans.append(val)
        return ans