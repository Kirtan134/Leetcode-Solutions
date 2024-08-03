class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> car;
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        double time;
        stack<double> st;
        for(int i=n-1;i>=0;i--){
            time = ((double)(target-car[i].first)/car[i].second);
            while(st.empty() || st.top()<time) st.push(time);
            cout<<time<<endl;
        }
        return st.size();
    }
};