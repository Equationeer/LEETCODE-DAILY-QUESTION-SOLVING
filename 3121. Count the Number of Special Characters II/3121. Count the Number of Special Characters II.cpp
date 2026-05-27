class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>upper(26,-1);
        vector<int>low(26,-1);
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(ch>='a'&& ch<='z')
            low[ch-'a'] = i;
            else{
             if(upper[ch - 'A'] == -1){ 
             upper[ch-'A'] = i;
             }
            }
        }
       
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(low[i] != -1 && upper[i] != -1) {
                if(low[i] < upper[i]) {
                    count++;
                }
            }
        }

        return count;
    }
};