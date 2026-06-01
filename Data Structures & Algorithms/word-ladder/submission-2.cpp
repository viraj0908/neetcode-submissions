class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict={wordList.begin(),wordList.end()};
        if(!dict.count(endWord)) return 0;
        if(beginWord==endWord) return 1;
        map<string,int> visited;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int distance=q.front().second;
            q.pop();
            if(word==endWord) return distance;
            visited[word]=1;
            // ans+=distance;
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(char j='a';j<='z';j++){
                    if(j==ch) continue;
                    word[i]=j;
                    if(dict.count(word) && !visited.count(word)) q.push({word,distance+1});
                    word[i]=ch;
                }
            }
        }
        return 0;
    }
};
