class Solution {
public:
    int mySqrt(int x) {
        long long low=0, high=x, mid, val;
        while(low<=high){
            mid = (low+high)/2;
            val = mid*mid;
            if(val<=x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};