class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue() { }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int a = output.top(); output.pop();
            return a;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int a = output.top(); output.pop();
            return a;
        }
    }
    
    int peek() {
        if(!output.empty()) return output.top();
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */