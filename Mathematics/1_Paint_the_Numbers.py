n = int(input()) 
a = set(map(int,input().split(' '))) #Taking input as given but we are making it a set so that we can eliminate all the duplicate values
x = 0 #Initializing a variable to keep the count of paints we need

while 0 < len(a): #We want our while loop to run till there are elements present in the set a
    j = min(list(a)) #we are converting a to list to get min
    for ele in list(a): #for to access all the elements present in the list of a
        if ele%j == 0: #we are checking whether the element is divisble by the min of list a
            a.remove(ele) #If yes we remove the element  from a
    x += 1 #after eliminating all the divisible elements we increase the count of paint for every while loop
print(x) #We print the count of paints