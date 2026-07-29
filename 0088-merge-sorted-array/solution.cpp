class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int idx = n+m-1 ;
        int i= m-1 , j= n-1;
        while(i>=0 && j>=0){
            if (a[i] < b[j])
            {
                a[idx--]= b[j--];
            }else {
                a[idx --]= a[i--];
            }
        }
        while (j>=0){
            (a[idx--] = b[j--]); //a[idx]= b[j]; idx -- , j--
        }
        
    }
};
