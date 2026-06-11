class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> st ;
        stack<int> no ;
        int count =0 ;
        string s1 = "";
                 
        for(int i =0 ; i< n ; i++){
            char ch = s[i];

            if(ch>='0' && ch<='9'){
                 count = 10*count + (ch-'0');
            }else if(ch=='['){
                 st.push(s1);
                 no.push(count);
                 count =0;
                 s1 = "";
            }else if(ch==']'){
                 string s2 = st.top();
                 st.pop();
                 int num = no.top();
                 no.pop();
                 string str = "";
                 for(int i=0 ; i<num ; i++){
                     str+=s1;
                 }
                 s1 = s2+str;
            }else{
               s1+=ch;
            }
        }
        return s1 ;
    }
};
