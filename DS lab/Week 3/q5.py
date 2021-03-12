import numpy as np

X = np.array([[12,7,3],
    [4 ,5,6],
    [7 ,8,9]])

Y = np.array([[5,8,1],
    [6,7,3],
    [4,5,9]])

print("Matrix 1:")
print(X)
print("Matrix 2:")
print(Y)

result = [[X[i][j] + Y[i][j]  for j in range(len(X[0]))] for i in range(len(X))]
print("Sum:")
print(np.array(result))