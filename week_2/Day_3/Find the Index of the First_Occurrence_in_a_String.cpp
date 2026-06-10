class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int ans =-1 ;

        int i =0;
        int j =0;
    
        while(i<n && j<m){
           
            if(haystack[i+j]==needle[j]){
                j++;
                if(j==m){
                    ans = i ;
                    break;
                }
            }else{
                j=0;
                i++;
            }
        }
        return ans ;
    }
};
