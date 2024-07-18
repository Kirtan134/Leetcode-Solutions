class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0, high=arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            int ms = arr[mid] - (mid+1);
            if(ms<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            } 
        }
            // What to return ? 
            // arr[high] + more
            // arr[high] + (k - missing)
            // arr[high] + (k - (arr[high] -(high+1)))
            // k + high + 1
            // k + low
            return k + low;
    }
};