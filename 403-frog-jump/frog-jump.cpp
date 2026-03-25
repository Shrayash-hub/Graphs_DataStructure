class Solution {
public:
    bool canCross(vector<int>& stones) {
        // we need to save the all possible jump values at a stone -> as kisi
        // bhi stone pr alag alag jump values k sath a sktey h
        unordered_map<int, unordered_set<int>> mpp; // stone -> {jump sizes}

        // just for lookups existense
        for (auto& stone : stones) {
            mpp[stone];
        }

        // we can come at 0th stone , only with jump size 0
        mpp[0].insert(0);
        
        for (auto& stone : stones) {
            for (auto& k : mpp[stone]) {

                // lets try all the possible jump values k-1,k,k+1
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    // negative jump value(k=0 k liye a skti h) aur 0 jump value
                    // required nhi h
                    if (jump <= 0)
                        continue;
                    // after this jump -> we will reach to this stone
                    int nextStone = stone + jump;

                    // nextStone exist bhi toh krna chahiye stones array me
                    if (mpp.find(nextStone) != mpp.end()) {
                        // if exists ,  them us stone curr jump value se phoch rhey ye store krlo
                        mpp[nextStone].insert(jump);
                    }
                }
            }
        }

        // if at the end , we can reach last stone with any jump value -> return true
        if(mpp[stones.back()].empty()) return false;
        return true;
    }
};