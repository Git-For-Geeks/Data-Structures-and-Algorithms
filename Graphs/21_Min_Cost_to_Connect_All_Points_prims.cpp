class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
    
        //creating heap to store minimum weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prio_queue; 
        vector<bool> arr(n);
        prio_queue.push({ 0, 0 });
        int m_cost = 0;
        int remaning = 0;
        while (remaning < n) {
            pair<int, int> top_element = prio_queue.top();
            prio_queue.pop();
            
            int weight = top_element.first;
            int current_node = top_element.second;
            if (arr[current_node]) {
                continue;
            }
            
            arr[current_node] = true;
            m_cost += weight;
            remaning++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!arr[nextNode]) {
                    int nextWeight = abs(points[current_node][0] - points[nextNode][0]) + 
                                     abs(points[current_node][1] - points[nextNode][1]);
                    
                    prio_queue.push({ nextWeight, nextNode });
                }
            }
        }
        
        return m_cost;
    }
};