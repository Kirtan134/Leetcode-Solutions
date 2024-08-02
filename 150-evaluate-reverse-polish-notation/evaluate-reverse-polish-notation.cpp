class Solution {
private:
    stack<int> st;
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int a,b,temp;
        for(int i=0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(tokens[i] == "+") temp=b+a;
                else if(tokens[i] == "-") temp=b-a;
                else if(tokens[i]=="*") temp=b*a;
                else if(tokens[i]=="/") temp=b/a;
                st.push(temp);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};