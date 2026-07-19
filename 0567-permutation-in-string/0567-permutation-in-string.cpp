class Solution {
public:
    bool isfreqsame(int freq1[], int freq2[]){
        for (int j=0 ; j<26;j++){
            if (freq1[j] != freq2[j]){
                return false;
            }
        }
        return true ;
    }             
    bool checkInclusion(string s1, string s2) {
        int freq[26];
        for (int i = 0; i< s1.length() ;i++){
            freq[s1[i] - 'a']++;
        }
        int windsize= s1.length();
        for(int i =0 ; i < s2.length() ; i++){
            int windidx =0, idx =i;
            int windfreq[26] ={0};
            while (windsize> windidx && idx <s2.length()){
                windfreq[s2[idx] -'a' ]++ ;
                windidx ++, idx ++;
            }
            if (isfreqsame(freq , windfreq)){
                return true;
            }
        }
        return false ;
    }
    
};