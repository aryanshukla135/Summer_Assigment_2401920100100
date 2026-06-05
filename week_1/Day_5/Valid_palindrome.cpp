//tc->O(N)
//sc->O(1)
class Solution {
private:
    bool isvalid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') ){
            return true;
        }else{
            return false ;
        }
    }

    char inlower(char ch){
        int val = ch-'A';
        char low = val+'a';
        return low;
    }

    bool pallindrome(string s){
        int n = s.length();
        int i =0; 
        int j = n-1 ;

        while(i<j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true ;
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string str ="";

        for(int i =0 ; i< n ; i++){
             char ch = s[i];
             if(ch==' '){
                continue ;
             }
             if(isvalid(ch)){
                if(ch>='a' && ch<='z'){
                    str+=ch;
                }else{
                    char low =inlower(ch);
                    str+=low;
                }
             }
        }
       
        return pallindrome(str);
    }
};
