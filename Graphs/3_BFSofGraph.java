//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                // adj.get(v).add(u);
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.bfsOfGraph(V, adj);
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        int s=0;
        //v is to mark vertices as not visited
        boolean v[] = new boolean [V];
        v[s] = true;
         ArrayList <Integer> sol = new ArrayList<>();
         //Creating queue for BFS
         LinkedList <Integer> q = new LinkedList<Integer>();
         q.add(s);
         
         while(q.size() != 0){
             //popping front element from q and adding it to sol list
             s= q.poll();
             sol.add(s);
             
             //tranversing componets connected to first element
             Iterator<Integer> i = adj.get(s).listIterator();
             while(i.hasNext()){
                 int n = i.next();
                 //If not visited vertices, mark them as visited
                 if(!v[n]){
                     v[n] = true;
                     q.add(n);
                 }
             }
             
         }
         //return final sol list
         return sol;
    }
}
