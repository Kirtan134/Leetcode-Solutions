#define ll long long 
class Solution {
private:
    vector<int> nse(vector<int>& arr, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> psee(vector<int>& arr, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> nge(vector<int>& arr, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> pgee(vector<int>& arr, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        ll smallest = 0, largest = 0;
        vector<int> nseArr = nse(arr,n);
        vector<int> pseeArr = psee(arr,n);
        for(int i=0;i<n;i++){
            smallest = (smallest + ((ll)arr[i] * ((nseArr[i]-i) * (i-pseeArr[i])))) ;
        }
        vector<int> ngeArr = nge(arr,n);
        vector<int> pgeeArr = pgee(arr,n);
        for(int i=0;i<n;i++){
            largest = (largest + ((ll)arr[i] * ((ngeArr[i]-i) * (i-pgeeArr[i]))));
        }
        return largest-smallest;
    }
};