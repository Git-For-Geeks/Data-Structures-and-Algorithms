class Solution:
    def breakPalindrome(self, palindrome: str) -> str: #LeetCode provides us with a class and a function which would be called in the main code.
        if len(palindrome) == 1:
            return "" #We are returning "" as the given output if the length of the Palindrome is only one.
        else:
            count = 0 #Initializing a variable count to check whether the letters are same.
            palinlst = [*palindrome] #Created a list containing the elements of the passed Palindrome.
            i = 0
            while i < (len(palinlst)//2): #Created i for the count then keeping less than half the length of palindrome because first half of the palindrome is equivalent to the second half.
                if palinlst[i] == 'a': #As we need to destroy the palindrome property by replacing only one letter which should lexicographically smallest.
                    count += 1 #Getting the number of a's 
                    i += 1
                else: #As soon as we get a letter other than 'a' change it to 'a' as we need the change to be lexicographically smallest.
                    palinlst[i] = 'a' #We change the letter to 'a'.
                    i = i + (len(palinlst)) #Break the else by incrementing the i as high as possible.

            if count == (len(palinlst)//2): #Checking whether the Palindrome consists of same letter.
                palinlst[(len(palinlst)-1)] = 'b' #If yes we change the last letter to b because after 'a', 'b' is lexicographically smallest.
                x = ''.join(palinlst)
                return x
            else:
                y = ''.join(palinlst) #If not we return the palindrome as it is.
                return y