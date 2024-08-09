class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(auto it: points){
            pq.push({it[0]*it[0]+ it[1]*it[1], it[0],it[1]});
        }
        while(k--){
            vector<int> el = pq.top(); pq.pop();
            ans.push_back({el[1],el[2]});
        }
        return ans;
    }
};