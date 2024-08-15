class Solution {
public:
    int mySqrt(int x) {
        long long i=0;
        while(1){
            if(i*i<x && ((i+1)*(i+1))<=x){
                i++;
            }
            else break;
        }
        return i;
    }
};