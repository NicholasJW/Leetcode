class Solution {
    
    
    public boolean wordBreak(String s, List<String> wordDict){
        boolean[][] dp = new boolean[s.length()][s.length()];
        // System.out.println(s.substring(0, s.length()));
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<s.length(); j++){
                dp[i][j] = false;
            }
        }
        
        for(int j=0; j<s.length(); j++){
            for(int i=j; i>=0; i--){
                if(wordDict.contains(s.substring(i,j+1))){
                    dp[i][j] = true;
                }else{
                    for(int k=i; k<=j; k++){
                        if(dp[i][k] && dp[k+1][j]){
                            dp[i][j] = true;
                            break;
                        }
                    }   
                }
            }
        }
        
//         for(int i=0; i<s.length(); i++){
//             for(int j=0; j<s.length(); j++){
//                 System.out.print(dp[i][j] + "   ");
//             }
//             System.out.print('\n');
//         }
        
        return dp[0][s.length()-1];
    }
}