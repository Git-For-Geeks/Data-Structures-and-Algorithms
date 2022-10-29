class Solution:
    def reformat(self, s: str) -> str:
        a, b = [], [] # We created two lists to seperate letters and digits.
        for c in s: # Taking characters from string and comparing whether it is a digit or a letter
            if c.isdigit():
                a.append(c) # if digit we append it in a
            else:
                b.append(c) # if letter we append it in b
        if len(a) < len(b): # if the length of b is greater than a we switch the lists
            a, b = b, a
        if len(a) >= len(b) + 2: # if the length of a is greater than b when added with 2 then the operation is not possible
            return ''
        r = '' #creating an empty string to store the required output
        for i in range(len(s)): #In this for loop we append one digit and one letter one after the another to get the required output
            if i % 2 == 0:
                r += a[i // 2]
            else:
                r += b[i // 2]
        return r