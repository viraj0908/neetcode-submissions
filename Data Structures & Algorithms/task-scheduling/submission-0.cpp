class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        for(char ch : tasks){
            freq[ch - 'A']++;
        }

        priority_queue<int> heap;

        for(int x : freq){
            if(x > 0) heap.push(x);
        }

        queue<pair<int,int>> q;

        int time = 0;

        while(!heap.empty() || !q.empty()){

            time++;

            // release tasks whose cooldown ended
            if(!q.empty() && q.front().second == time){
                heap.push(q.front().first);
                q.pop();
            }

            if(!heap.empty()){

                int cnt = heap.top();
                heap.pop();

                cnt--;

                if(cnt > 0){
                    q.push({cnt, time + n + 1});
                }
            }
        }

        return time;
    }
};