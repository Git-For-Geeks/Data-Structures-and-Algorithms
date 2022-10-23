a=[] #Initializing a list to store the scores of the students.
t=1 #Initializing a rank variable which starts from 1 and ends at n.
for i in range(int(input())): #Using for loop to get the required number of inputs.
  b=sum(map(int,input().split())) #Summing all the scores to get only one total value to compare with Thomas
  a.append(b) #Appending the total score to the list
  if b>a[0]: #Comparing the score we got with first element of list as it belongs to Thomas (id: 1)
    t+=1 #If greater than Thomas then increasing the rank of Thomas
print(t) #Printing Thomas's Rank.