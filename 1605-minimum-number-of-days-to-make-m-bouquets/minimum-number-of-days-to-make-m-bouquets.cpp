class Solution {
private:
    int count(vector<int>& bloomDay, int mid, int k){
        int c=0, ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                c++;
            }
            else{
                if(c>=k){
                    ans+=c/k;
                }
                c=0;
            }
        }
        ans+=c/k;
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = (low+high)/2;
            int ans = count(bloomDay,mid,k);
            if(ans<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};