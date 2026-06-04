//tc->O(r*c)
//sc->O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
       vector<vector<int>> ans(r, vector<int>(c));
       int total = m*n ;
        if(r*c != total ){
            return mat ;
        }
        int idx1 =0;
        int idx2 =0;

        for(int i =0 ;i<m ; i++){
            for(int j =0 ; j<n ; j++){
                 int val = mat[i][j];
                
                if(idx1<r && idx2<c){
                  ans[idx1][idx2]=val;
                }

                idx2++;

                if(idx2==c){
                    idx1++;
                    idx2=0;
                 }
                
                 
            }

        }
        
        return ans ;
    }
};
