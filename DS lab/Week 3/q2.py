import numpy as np

r = int(input("Enter the no. of rows: ")) 
c = int(input("Enter the no. of columns: ")) 
matrix = []

print("Enter the elements:") 
for i in range(r):
    a =[] 
    for j in range(c):
         a.append(int(input())) 
    matrix.append(a) 

print("Matrix:")
for i in range(r): 
    for j in range(c): 
        print(matrix[i][j], end = " ") 
    print() 

print("Sum of all columns: ", np.sum(matrix, axis=0))
print("Sum of all rows: ", np.sum(matrix, axis=1))