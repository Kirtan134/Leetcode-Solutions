class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;
        for(auto it: points){
            triples.push_back({it[0]*it[0]+ it[1]*it[1], it[0],it[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> ans;
        while(k--){
            vector<int> el = pq.top(); pq.pop();
            ans.push_back({el[1],el[2]});
        }
        return ans;
    }
};