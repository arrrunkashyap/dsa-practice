class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int diff = 0 , tar = 0 ;
        int i=0;
        for(int val : nums){
            diff = val ;
            tar = target- diff;
            int j=0;
            for(int el : nums ){
                if (i != j && tar == el){
                    return { i ,j };
                }
                j++;
            }
            i++;

        }
        return {};
        
    }
    
    
};