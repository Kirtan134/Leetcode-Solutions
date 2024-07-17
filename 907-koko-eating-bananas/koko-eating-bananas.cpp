#define ll long long
class Solution {
private:
    ll calculateTotalHours(vector<int>& piles, int mid){
        ll ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=ceil((double)piles[i]/(double)mid);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());;
        while(low<=high){
            int mid = (low+high)/2;
            ll totalH = calculateTotalHours(piles,mid);
            if(totalH<=h) high = mid-1;
            else  low=mid+1;
        }
        return low;
    }
};