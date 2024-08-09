class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        priority_queue<int> pq(temp.begin(),temp.end());
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};