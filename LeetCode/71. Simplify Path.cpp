class Solution {
public:
    string simplifyPath(string path) 
    {
        int n = path.length();
        stack<string> st;
        stringstream ss(path);
        string s;
        while(getline(ss,s,'/'))
        {
            if(s == "" || s == ".")
                continue;
            else if(s == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s);
            }
        }
        string res = "";
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        if(res.empty())
            return "/";
        else
            return res;
    }
};
