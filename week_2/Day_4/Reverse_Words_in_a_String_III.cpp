class Solution {
public:
    string reverseWords(string s) {
          int n = s.length();
          string ans= "";
          stack<char> st ;
          for(int i =0 ; i< n ; i++){
            char ch = s[i];
            if(ch !=' '){
                st.push(ch);
            }else{
                if(!st.empty()){
                   while(!st.empty()){
                      char ch = st.top();
                      st.pop();
                      ans.push_back(ch);
                   }
                   ans.push_back(' ');
                }
            }
          }
          while(!st.empty()){
             char ch = st.top();
             st.pop();
             ans.push_back(ch);
          }
          return ans ;
    }
};
