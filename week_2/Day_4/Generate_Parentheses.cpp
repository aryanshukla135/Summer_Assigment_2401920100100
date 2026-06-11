class Solution {

private:
    bool isvalid(string curr){
        int n = curr.length();
        stack<char>st;
        for(int i=0; i<n ; i++){
            char ch = curr[i];
            if(ch =='('){
                st.push(ch);
            }else{
                if(!st.empty()){
                    if(st.top()=='('){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true ;
    }
    void solve(int n , string curr ,vector<string> &ans ){
        if(curr.length()==2*n){
            if(isvalid(curr)){
                ans.push_back(curr);
            }
            return ;
        }
        curr.push_back('(');
        solve(n,curr,ans);
        curr.pop_back();
        curr.push_back(')');
        solve(n,curr,ans);
        curr.pop_back();

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr ;
        solve(n , curr, ans);
        return ans ;
    }
};
