class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // sort the deck as reveal order must be increasing
        sort(deck.begin(), deck.end());

        queue<int> q;
        // storing indices in queue
        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }

        vector<int> res(deck.size());
        int i = 0;

        while(!q.empty()) {
            // index where current smallest card should be placed
            int idx = q.front();
            q.pop();
            res[idx] = deck[i++];

            // simulate moving next card at the bottom
            if(!q.empty()) {
                int next = q.front();
                q.pop();
                q.push(next);
            }
        }

        return res;
    }
};