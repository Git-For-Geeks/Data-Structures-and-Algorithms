n,k = map(int, input().split(' ')) #Taking the input of two integers
factorlst = [] #Creating a list to store the number of factors we need of n

for i in range(k-1): #Using for loop to get the desired number of factors
    for j in range(2,n): #Using nested for loop to get the factors of n
        if n%j == 0:
            n = n//j #Dividing n by the factor we get i.e. j to get the remaining factors through new n
            factorlst.append(j) #Appending the factors in our list
            break #We are breaking the if loop to keep only one factor we got in the list
            
if len(factorlst) == k-1: #Checking whether we have correct number i.e. k-1 of factors as we have n which is one of the factors
    print(*factorlst,n) #'*' allows us to print elements of a list seperately, along with the elements we print n
else:
    print('-1') #If the length is not the one we desired for then we print -1