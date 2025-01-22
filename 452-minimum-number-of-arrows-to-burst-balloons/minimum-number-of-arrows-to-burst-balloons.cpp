class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int ans = n;
        vector<int> curr, prev = points[0];
        for(int i=1;i<n;i++){
            curr = points[i];
            if(curr[0]<=prev[1]){
                ans--;
                prev={curr[0],min(curr[1],prev[1])};
            }
            else prev = curr;
        }
        return ans;
    }
};