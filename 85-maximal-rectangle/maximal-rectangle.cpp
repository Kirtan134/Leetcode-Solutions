class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int pse[n], nse[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(nse[i]-pse[i]-1)*heights[i]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
            }
            int area = largestRectangleArea(h);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};