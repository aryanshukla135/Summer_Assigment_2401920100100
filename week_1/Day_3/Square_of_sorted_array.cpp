//tc->O(n)
//sc->O(1)
 Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int n = nums.size();
         vector<int> ans(n);
         int i =0;
         int j = n-1 ;
         int idx = n-1 ;

         while(i<=j){
            int val1 = (nums[i]*nums[i]);
            int val2 = (nums[j]*nums[j]);

            if(val1>val2){
                ans[idx]=val1;
                i++;
                idx--;
            }else{
                ans[idx]=val2;
                j--;
                idx--;
            }

         }
         return ans ;
    }
};
