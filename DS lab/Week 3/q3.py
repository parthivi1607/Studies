import numpy as np

mylist = [float(x) for x in input("Enter list elements: ").split()]
print("List: ",mylist)
arr = np.array(mylist)
print("Array: ",arr)

tup = tuple(int(x) for x in input("Enter tuple elements: ").split())
print("Tuple: ", tup)
arr = np.array(tup)
print("Array: ",arr)

arr = np.zeros((3,4))
print("3X4 zero matrix: ")
print(arr)

print("Sequence of integers from 0 to 20 with steps of 5:")
for i in range(0,21,5):
	print(i)

print("3X4 array reshaped to 2X2X3 array:")
arr = arr.reshape(2,2,3)
print(arr)

print()
matrix =[[12,34,28,16],
		[13,32,36,12],
		[15,32,32,14],
		[11,33,36,10]]
print("Matrix:")
for i in range(len(matrix)): 
    for j in range(len(matrix)): 
        print(matrix[i][j], end = " ") 
    print() 

print("Sum of all elements: ", np.sum(matrix))
print("Max element: ", np.max(matrix))
print("Min element: ", np.min(matrix))
print("Min of every row: ", np.min(matrix, axis=1))
print("Max of every row: ", np.max(matrix, axis=1))
print("Min of every column: ", np.min(matrix, axis=0))
print("Max of every column: ", np.max(matrix, axis=0))