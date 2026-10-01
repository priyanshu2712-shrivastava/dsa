class Solution {
private:
    bool isClose(char c,char t){
        if(c=='[' && t==']') return true;
        else if(c=='(' && t==')') return true;
        else if(c=='{' && t=='}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack <char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                
                    if((!st.empty())&&isClose(st.top(),s[i])){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};