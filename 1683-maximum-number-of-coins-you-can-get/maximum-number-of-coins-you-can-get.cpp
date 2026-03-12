class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        
        int cnt = 0;
        for(int i = 0; i < piles.size()/3; i++){
            cnt += piles[n-2];
            n -=2;
        }

        return cnt;
    }
};