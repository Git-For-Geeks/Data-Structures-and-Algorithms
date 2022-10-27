def binary_search(lst, low, high, x):
	if high >= low:

		mid = (high + low) // 2
		if lst[mid] == x:
			return mid
		elif lst[mid] > x:
			return binary_search(lst, low, mid - 1, x)
		else:
			return binary_search(lst, mid + 1, high, x)

	else:
		return -1
lst = [ 2,8,9,10 ]
x = 10

result = binary_search(lst, 0, len(lst)-1, x)

if result != -1:
	print("Element is present at index", str(result))
else:
	print("Element is not present in array")
