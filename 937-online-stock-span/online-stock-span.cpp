// Time Complexity : O(2*n)
// Space Complexity: O(n)
// Using concept of PGE [Previous Greater Element]

class StockSpanner {
private:
    stack<pair<int,int>> st; 
    int idx;
public:
    StockSpanner() {
        while(!st.empty()) st.pop();
        idx=-1;
    }
    
    int next(int price) {
        idx++;
        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = idx - (st.empty() ? -1 : st.top().second); 
        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */