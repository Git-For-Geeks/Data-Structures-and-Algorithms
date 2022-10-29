class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        if amount == 0:
            return 1
        
        dp = {}
        coins.sort(reverse=True)
        
        def rec(remaining, ci):
            if ci >= len(coins):
                return 0
            
            if remaining in dp and ci in dp[remaining]:
                return dp[remaining][ci]
            
            if remaining == 0:
                return 1
            
            elif remaining < 0:
                return 0
            
            number_of_ways = rec(remaining - coins[ci], ci)

            for nci in range(ci+1, len(coins)):
                number_of_ways += rec(remaining - coins[nci], nci)
                
            if remaining in dp:
                dp[remaining][ci] = number_of_ways
            else:
                dp[remaining] = {ci: number_of_ways}
                
            return number_of_ways
        
        return rec(amount, 0)
