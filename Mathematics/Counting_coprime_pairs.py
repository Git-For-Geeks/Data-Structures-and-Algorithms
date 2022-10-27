
def gcd(a, b):
	
	if (a == 0 or b == 0):
		return False
	

	if (a == b):
		return a

	
	if (a > b):
		return gcd(a-b, b)
		
	return gcd(a, b-a)

def coprime(a, b) :
	return (gcd(a, b) == 1)


def numOfPairs(arr, n) :
	count = 0
	
	for i in range(0, n-1) :
		for j in range(i+1, n) :
	
			if (coprime(arr[i], arr[j])) :
				count = count + 1
	
	return count


arr = [1, 10, 3, 9, 8, 3, 9]
n = len(arr)

print(numOfPairs(arr, n))

