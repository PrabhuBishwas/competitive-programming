/* You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
*/

int countWays(int s[], int m, int n, int** output){
    if(n==0){
       return 1;
   }
    if(n<0){
        return 0;
    }
    if(m == 0){
        return 0;
    }
    if(output[n][m] > -1){
        return output[n][m];
    }
    
    int first = countWays(s, m, n-s[0], output);
    int second = countWays(s+1, m-1, n, output);
    output[n][m] = first + second;
    
    return first+second;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
    int** output = new int*[value+1];
   for(int i=0; i<=value; i++){
       output[i] = new int[numDenominations+1];
       for(int j=0; j<=numDenominations; j++ ){
           output[i][j] = -1;
       }
   }
    int ans = countWays(denominations, numDenominations, value, output);
    return ans;

}
