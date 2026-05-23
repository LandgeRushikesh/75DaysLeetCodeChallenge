class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
         priority_queue<int> pq;

        // put all stones into max heap
        for (int stone : stones) {
            pq.push(stone);
        }

        // keep smashing top two stones
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            // if both are not equal, push remaining weight
            if (y != x) {
                pq.push(y - x);
            }
        }

        // if heap becomes empty return 0
        return pq.empty() ? 0 : pq.top();
    }
};