class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        stack <int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) nge[i]=-1;
            else nge[i]=st.top();
            st.push(nums2[i]);
        }
        // Now we got all NGE's of nums2 vector
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        for(int i=0;i<m;i++){
            ans.push_back(nge[mp[nums1[i]]]);
        }
        return ans;
    }
};