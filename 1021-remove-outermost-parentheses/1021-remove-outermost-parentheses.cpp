class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> str;
        string ansFinal;
        string ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(str.empty()&&ch=='(') str.push(ch);
            else if(!str.empty()&&ch=='('){
                str.push(ch);
                ans+=s[i];
            }
            else{
               if(str.top()=='('){
                str.pop();
                if(!str.empty()){
                    ans+=s[i];
               } 
               else{
                ansFinal=ansFinal+ans;
                    ans="";
               }  
            }
        }

    }
    return ansFinal;
    }
};