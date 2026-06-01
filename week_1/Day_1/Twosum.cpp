//tc-O(nlog(n))
//sc-O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();
         unordered_map<int,vector<int>> m ;
         for(int i =0 ;i<n ; i++){
            m[nums[i]].push_back(i);
         }
         sort(nums.begin(),nums.end());
         int i =0;
         int j =n-1;
         while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==target){
                vector<int> idx1 =m[nums[i]];
                vector<int> idx2 =m[nums[j]];
                if(idx1==idx2){
                    return {idx1[0],idx1[1]};
                }
                return {idx1[0],idx2[0]};
            }else if(sum>target){
                j--;
            }else{
                i++;
            }
         }
         return {};
    }
};
