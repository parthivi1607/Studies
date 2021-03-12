# Q1
print("Q1:")
x = int(input("Enter length of rectangle: "))
y = int(input("Enter breadth of rectangle: "))
print("Area of rectangle = ", (x*y))
print()

# Q2
print("Q2:")
print("Before swapping: x = %d, y = %d" %(x,y))
t = x
x = y
y = t
print("After swapping: x = %d, y = %d" %(x,y))
print()

# Q3
print("Q3:")
x = int(input("Enter a no.: "))
if x%2 == 0:
	print("%d is even" %(x))
else:
	print("%d is odd" %(x))
print()

# Q4
print("Q4:")
x = int(input("Enter number 1: "))
y = int(input("Enter number 2: "))
z = int(input("Enter number 3: "))
max = 0
if x>y:
	if x>z:
		max = x
	else:
		max = z
else:
	if y>z:
		max = y
	else:
		max = z
print("Largest out of %d, %d, %d : %d" %(x,y,z,max))

# Q5
print("Q5:")
z = int(input("Enter counter number: "))
while z>0:
	print("Inside loop - counter = ",z)
	z = z-1
else:
	print("Outside loop")
print()

# Q6
print("Q6:")
start = int(input("Enter start range: "))
end = int(input("Enter ending range: "))
print("Prime numbers in range of %d and %d :" %(start,end))
for i in range(start, end+1):
	c = 0
	for j in range(2,i):
		if i%j==0:
			c = c+1
	if c==0:
		print(i)
print()

# Q7
print("Q7:")
list = ['abcd',786,2.23,'john',70.2]
print("List: ",list)
print("1st element: ",list[0])
print("2nd to 4th element: ", list[1:4])
print("Elements from 3rd posn: ", list[2:])
print("List * 2: ", list*2)
print("Concat: ", list + ['party'])
list.append('john')
print("List append: ", list)
del list[2]
print("Deleted 3rd element: ",list)
print("Length of list: ",len(list))
print("Count of 'john' in list: ", list.count('john'))
print("Last element of list popped: ", list.pop())
list.insert(3,'party')
print("Insert 'party' at index 3: ", list)
list.remove('party')
print("Remove 'party':", list)
list.reverse()
print("Reversed list: ",list)
print()

# Q8
print("Q8:")
tup = (1,3,5,7,9,2,4,6,8,10)
print("Tuple: ",tup)
hlen = int(len(tup)/2)
print("1st line: ", tup[:hlen])
print("2nd line: ", tup[hlen:])
print()

# Q9
print("Q9:")
data = (12, 7, 38, 56, 78)
print("Original tuple: ",data)
even = tuple(x for x in data if x % 2 == 0)
print("Tuple w only even nos.: ", even)
print()

# Q10
print("Q10:")
list1 = [11,-21,0,45,66,-93]
print("Negetive numbers in ", list1)
for i in list1:
	if i<0:
		print(i)
print()

# Q11
print("Q11:")
list1 = [-10, 21, -4, -45, -66, 93] 
i = 0
print("Negetive numbers in ", list1)
while i < len(list1): 
    if list1[i] < 0: 
        print(list1[i]) 
    i = i + 1
print()

# Q12
print("Q12:")
list1=[123,-456,789,-987,654,-321,-21345]
print("List: ",list1)
pos = neg = 0
for i in list1:
	if i>0:
		pos = pos+1
	elif i<0:
		neg = neg+1
print("No. of +ve nos.: ",pos)
print("No. of -ve nos.: ",neg)
print()

# Q13
print("Q13:")
print("List: ",list1)
for i in list1:
	if i%2==0:
		list1.remove(i)
print("List after removing even nos.: ", list1)