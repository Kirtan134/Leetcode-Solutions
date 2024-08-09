// TC: O(n * cooldown)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26);
        for(int i=0;i<tasks.size();i++){
            hash[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(hash[i]) pq.push(hash[i]);
        }
        int time = 0;
        queue<vector<int>> q;
        while(!q.empty() || !pq.empty()){
            time++;
            if(!pq.empty()){
                if(pq.top()-1) q.push({pq.top()-1, time+n});
                pq.pop();
            }
            if(!q.empty() && q.front()[1]==time){
                pq.push(q.front()[0]); q.pop();
            }
        }
        return time;
    }
};