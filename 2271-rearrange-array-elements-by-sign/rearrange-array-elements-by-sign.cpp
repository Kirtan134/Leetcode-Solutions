class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> vp,vn;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                vp.push_back(nums[i]);
            }
            else{
                vn.push_back(nums[i]);
            }
        }
        bool b = true;
        int j=0, k=0;
        for(int i=0;i<n;i++){
            if(b){
                ans.push_back(vp[j]);
                j++;
            }
            else{
                ans.push_back(vn[k]);
                k++;
            }
            b=!b;
        }
        return ans;
    }
};