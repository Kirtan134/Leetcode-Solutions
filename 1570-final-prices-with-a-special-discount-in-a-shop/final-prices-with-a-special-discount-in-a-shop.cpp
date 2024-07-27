class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>arr[i]) st.pop();
            nse[i] = arr[i] - (st.empty() ? 0 : st.top());
            st.push(arr[i]);
        }
        return nse;
    }
};