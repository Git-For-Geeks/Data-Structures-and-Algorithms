#program to sort the matrix diagonally
def sortDiagonal(arr, M, N):
	for i in range(M):
		sm = arr[i][i]
		pos = i
		for j in range(i + 1 , N):
			if (sm > arr[j][j]):
				sm = arr[j][j]
				pos = j

		arr[i][i], arr[pos][pos] = arr[pos][pos] , arr[i][i]
	for i in range(M):
		for j in range(N):
			print(arr[i][j],end=" ")
		print()

arr = [[4, 2],[3, 1]]
sortDiagonal(arr, 2, 2)

