class Solution {
public:
    bool isPalindrome(int x) {
        int rev =0;
        int num = x;
        while (x >0){
            int dig = x % 10;
            if (rev > INT_MAX /10 || rev < INT_MIN/10){
                return false;
            }

            rev = rev*10 +dig;
            x = x/10;
        }
        if (rev==num){
            return true;
        }else{
            return false;
        }
        return false;
        
    }
};
