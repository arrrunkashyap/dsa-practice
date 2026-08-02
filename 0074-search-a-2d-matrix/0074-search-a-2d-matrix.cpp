class Solution {
public:

    bool inrowsearch(vector<vector<int>>&mat , int target , int midR){
        int m = mat.size() , n = mat[0].size();

        int st = 0 , end = n-1;
        while(st<=end){
            int mid = st+ (end -st)/2;
            if (target == mat[midR][mid] ){
                return true ;
            }
            else if (target < mat[midR][mid] ){
                end = mid -1;
            }else {
                st =mid +1;
            }
        }

    return false ;
    }


    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size() , n = mat[0].size();

        int startR =0 ,endR= m-1;
        while(startR<=endR){
            int midR = startR+(endR-startR)/2;
            if (mat[midR][0] <= target && mat[midR][n-1] >= target ){
                // function
                return inrowsearch(mat , target , midR);
            }
            else if (target <= mat[midR][0]){
                endR = midR-1;
            }else{
                startR =midR+1;
            }
        }
    return false ;    
    }
};