//tc->O(n)
//sc->O(1)
  
class Solution {
public:
    int maxArea(vector<int>& height) {
         int n = height.size();
         int maxArea = INT_MIN;

         int i =0;
         int j = n-1 ;
         while(i<j){
            int len = j-i ;
            int wid = min(height[i],height[j]);
            maxArea=max(maxArea , len*wid);
            
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
         }
         return maxArea;
    }
};
