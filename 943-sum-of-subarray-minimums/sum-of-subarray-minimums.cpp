#define ll long long
class Solution {
private:
    vector<int> nse(vector<int>& arr, int n){
        vector<int> nse(n);
        stack <int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> psee(vector<int>& arr, int n){
        vector<int> psee(n);
        stack <int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        ll total=0, mod=1e9+7;
        vector<int> nseArr = nse(arr,n);
        vector<int> pseeArr = psee(arr,n);
        for(int i=0;i<n;i++){
            int pseeIdx = nseArr[i];
            int nseIdx = pseeArr[i];
            total = (total + ((arr[i])*(((ll)(i-pseeIdx))%mod * ((ll)(nseIdx-i))%mod))%mod)%mod;
        }
        return total;
    }
};