class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // simulate in the reversed way
        
        vector<int> target(deck.begin(), deck.end());
        sort(target.begin(), target.end());
        
        deque<int> working;
        while (!target.empty()) {
            int c = target.back();
            target.pop_back();
            
            working.push_front(c);
            
            if (target.empty()) {
                break;
            }
            
            working.push_front(working.back());
            working.pop_back();
        }
        
        return vector<int>(working.begin(), working.end());
    }
};
