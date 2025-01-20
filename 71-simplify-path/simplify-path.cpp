class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "", ans = "";
        path+="/";

        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(curr==".."){
                    if(!st.empty()) st.pop();
                }
                else if(curr!="" && curr!="."){
                    st.push(curr);
                }
                curr="";
            }
            else curr+=path[i];
        }

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.size()==0) return "/";
        return ans;
    }
};