// Multiply Matrices

// } Driver Code Ends


/*Complete the function below*/
void multiply(int A[][100], int B[][100], int C[][100], int N)
{
    
    //add code here.
     int i=0;
     int j=0;
     
     for(i=0;i<N;i++){
         for(j=0;j<N;j++){
             int temp=0;
             for(int k=0;k<N;k++){
                 temp=temp + (A[i][k] * B[k][j]);
             }
             C[i][j]=temp;
         }
     }
}