class Solution {
public:

    int minimumDeletions(string s) {
        int b_count = 0;
        int dp = 0; // minimum deletion required to maintain balanced string
        for(int i=0;i<s.size();i++){
            // if we encounter a 'b' -> there is no conflict created and resolving is needed
            if(s[i]== 'b'){
                b_count++;
            }
            // if we encounter a 'a'
            else{
                // if there is no b , before this a -> no conflict

                // but if there are b's before this a (means b_count!=0)
                // we have to update the minimum deletions
                // cost for deleting this a is dp+1 and cost for deleting all previous b's is b_count(its not adding in dp because reset ho jayega sara)
                if(b_count!=0){
                    dp  = min (dp+1,b_count);
                }
            }
        }
        return dp;
    }
};