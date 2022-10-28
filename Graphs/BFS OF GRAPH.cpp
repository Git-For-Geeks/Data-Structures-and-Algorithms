class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[])
    {
        // Decalre the vector for final ans
        vector<int> bfs;

        // Make the visited array
        vector<int> visited(v, 0);

        // Make the queue for processing
        queue<int> q;

        // Mark the first node as visited
        visited[0] = 1;

        // Push the node
        q.push(0);

        // Iterate till the q is not empty
        while (!q.empty())
        {
            // Extract the front node
            int node = q.front();

            // Pop the node
            q.pop();

            // Push the node into the bfs vector
            bfs.push_back(node);

            // Explore it's adjacent node
            for (auto nbrs : adj[node])
            {
                if (!visited[nbrs])
                {
                    // Mark the current nbr as visited
                    visited[nbrs] = 1;

                    // Push the nbrs
                    q.push(nbrs);
                }
            }
        }

        // Retrun the bfs as the final ans
        return bfs;
    }
};