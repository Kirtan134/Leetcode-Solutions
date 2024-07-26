#define ll long long
class MinStack {
private:
    stack<ll> st;
    ll mini = INT_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            mini = val; 
            st.push((ll)val);
        }
        else{
            if(val<mini){
                st.push((2*((ll)val))-mini);
                mini = val;
            }
            else{
                st.push((ll)val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        ll el = st.top(); st.pop();
        if(el<mini) mini= 2*mini - el;
    }
    
    int top() {
        if(st.empty()) return -1;
        ll el = st.top();
        if(el<mini) return mini;
        return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */