class Solution {
private: 
 
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> p; 
        for(auto& it:mp) { 
            p.push_back(it); 
        } 
        sort(p.begin(), p.end(), [](auto& a, auto& b) { 
            if (a.second == b.second) return a.first>b.first; 
            return a.second<b.second; 
        }); 
        vector<int> ans;
        for (auto& it : p) {
            ans.insert(ans.end(), it.second, it.first); 
        }
        return ans;
    }
};