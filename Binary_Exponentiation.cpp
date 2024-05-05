class Solution {
    fun sumOfPower(nums: IntArray, k: Int): Int {
        
        
        val n=nums.size
        val M=1000000007
        
        val a = nums.toTypedArray()
        
        
        val dp=Array(n+1){ Array(n+1){ LongArray(k+1)}}
        
        
        for(i in 0..n){
            for(j in 0..n){
                for(sum in 0..k){
                    
                    if(j==0 && sum==0){
                        dp[i][j][sum]=1;
                        continue;
                    }
                    
                    if(i==0 || j==0 || sum==0){
                        dp[i][j][sum]=0;
                        continue;
                    }
                    
                    dp[i][j][sum]=dp[i-1][j][sum]
                    
                    if(sum-a[i-1]>=0)
                    dp[i][j][sum]+=dp[i-1][j-1][sum-a[i-1]]
                    
                    dp[i][j][sum]=dp[i][j][sum]%M
                }
            }
        }
        
        var ans:Long = 0
        
        fun P( a:Long, b:Long):Long{
            var res:Long = 1
            var aa =a 
            var bb =b
            
            while(bb > 0){
                if(bb and 1 == 1L)
                res = res*aa%M
                aa=aa*aa%M
                bb = bb shr 1
            }
            
            return res
        }
        
        for(i in 0..n){
         val cnt = dp[n][i][k]
            val cur=cnt*P(2,(n-i).toLong())%M
            ans+=cur
            ans%=M
            
        }
        
        return ans.toInt()
    }
}