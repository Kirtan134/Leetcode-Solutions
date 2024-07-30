class Solution {
public:
    // Sliding window hard problem
    // Deque --> O(n) TC & O(n) SC
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; // doubly queue 
        //Stores the index of sliding window and leftmost returns the max of that window (decreasing monotonic queue)
        int l=0,r=0;
        for(int r=0;r<n;r++){
            while(!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back(); // pops previous small
            }
            dq.push_back(r); 
            while(l>dq.front()) dq.pop_front();
            if(r+1>=k){
                ans.push_back(nums[dq.front()]);
                l++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(2*n)
// Space Complexity: O(k) + O(n-k)