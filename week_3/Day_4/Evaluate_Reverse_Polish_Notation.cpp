class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         int n = tokens.size();
         stack<string>st ;
         for(int i =0 ; i< n ; i++){
            string ch = tokens[i];
            if(ch !="*" && ch !="/" && ch !="+" && ch !="-"){
                st.push(ch);
            }else{
                if(ch=="+"){
                  int a = stoi(st.top());
                  st.pop();
                  int b = stoi(st.top());
                  st.pop();

                  int result = b+a ;
                  st.push(to_string(result));

                }else if(ch=="-"){
                  int a = stoi(st.top());
                  st.pop();
                  int b = stoi(st.top());
                  st.pop();

                  int result = b-a ;
                  st.push(to_string(result));

                }else if(ch=="*"){
                  int a = stoi(st.top());
                  st.pop();
                  int b = stoi(st.top());
                  st.pop();

                  int result = b*a ;
                  st.push(to_string(result));

                }else{
                  int a = stoi(st.top());
                  st.pop();
                  int b = stoi(st.top());
                  st.pop();

                  int result = b/a ;
                  st.push(to_string(result));
                }
            }
         }
         return stoi(st.top());
    }
};
