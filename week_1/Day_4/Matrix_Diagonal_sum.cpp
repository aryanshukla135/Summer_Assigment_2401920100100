//tc->O(n)
//sc->O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
         int n = mat.size();
         int sum = 0;

         for(int i =0 ; i< n ; i++){
        
            sum+=mat[i][i];
            int newi = i;
            int newj = n-i-1;

            if(newj != i){
                sum+=mat[newi][newj];
            }
         }
         return sum ;
    }
};
