class Solution {
private:
    stack<int> st;
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i] == "+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int temp = b+a;
                st.push(temp);
            }
            else if(tokens[i] == "-"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int temp = b-a;
                st.push(temp);
            }
            else if(tokens[i] == "*"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int temp = b*a;
                st.push(temp);
            }
            else if(tokens[i] == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int temp = b/a;
                st.push(temp);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};