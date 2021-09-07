# Implementation of Linked List
class Node:
    def __init__(self, value, next):
        self.value = value
        self.next = next
    
    def printList(self):
        # print("Current value of node: ", self.value)
        nextNode = self
        while (nextNode != None):
            print("Current value of node: " , nextNode.value)
            nextNode = nextNode.next
    
    def push_back(self, node):
        curr = self
        while (curr.next != None):
            curr = curr.next
        curr.next = node

# Implementation of Tree
class TreeNode: 
    def __init__(self, value, left, right):
        self.value = value
        self.left = left
        self.right = right
    
    def BFS(self):
        queue = []
        queue.append(self)
        while (len(queue) > 0):
            x = queue[0]
            queue.pop(0)
            print(x.value)
            if (x.left):
                queue.append(x.left)
            if (x.right):
                queue.append(x.right)


# Implementing powerSet of Set
def powerSet(arr):
    entire = []
    maxNum = 1 << len(arr);
    for i in range(0, maxNum):
        subset = convertIntToSubset(arr, i)
        entire.append(subset)
    return entire

def convertIntToSubset(arr, bits):
    index = 0
    subset = []
    while (bits > 0):
        if (bits & 1 == 1):
            subset.append(arr[index])
        index += 1
        bits >>= 1
    return subset

#Practice Inheritance
class Person:
    def __init__(self, fname, lname):
        self.fname = fname
        self.lname = lname
    
    def printName(self):
        print(f'{self.fname}, {self.lname}')

class Student(Person):
    def __init__(self, fname, lname, year):
        super().__init__(fname, lname)
        self.year = year
    
    def printName(self):
        super().printName()

def sortedMerge(a, b, countA, countB):
    indexMerged = countA + countB - 1
    indexA = countA - 1
    indexB = countB - 1
    while (indexB >= 0):
        if (indexA >= 0 and b[indexB] < a[indexA]):
            a[indexMerged] = a[indexA]
            indexA -= 1
        elif (b[indexB] > a[indexA]):
            a[indexMerged] = b[indexB]
            indexB -= 1
        indexMerged -=1

def swap(s, i, j):
    temp = s[i]


def permutationOfString(s, i, n):
    if (i == n -1):
        print(s)
    for j in range(i, n):
        s = list(s)
        s[i], s[j] = s[j], s[i]
        s = ''.join(s)
        permutationOfString(s, i + 1, n)
        s = list(s)
        s[i], s[j] = s[j], s[i]
        s = ''.join(s)

# FUNCTION CALLs

a = [2,4,6,8,10,0,0,0]
b = [3,5,7]

sortedMerge(a,b, 5,3)

s = "12345"
permutationOfString(s, 0, len(s))
print(a)

# a = Node(8, None)
# b = Node(7, None)
# c = Node(6, None)
# d = Node(5, None)
# e = Node(4, None)
# f = Node(3, None)

# a.push_back(b)
# a.printList()

# a = TreeNode(1, None, None)
# b = TreeNode(2, None, None)
# c = TreeNode(3, None, None)
# d = TreeNode(4, None, None)
# e = TreeNode(5, None, None)

# a.left = b
# a.right = c
# b.left = d
# c.right = e

# a.BFS()

# arr = [1,2,3,4,5]
# arr = powerSet(arr)
# for i in arr:
#     print(i)

bob = Person('Bob', 'Grant')
bob.printName()

junho = Student('Junho', 'Park', 2025)
junho.printName()


import requests
import pandas as pd

pokemon = 'pokemon/charizard'
# api_url = f'https://pokeapi.co/api/v2/{pokemon}'
# response = requests.get(api_url).json()
# print(response['moves'][0]['move']['name'])

# category = ''
# api_url = f'https://api.chucknorris.io/jokes/random?category={category}'
api_url = f'https://api.chucknorris.io/jokes/categories'
response = requests.get(api_url).json()


chuck_columns = ['categories', 'created_at', 'icon_url', 'id', 'updated_at', 'url', 'value']
df = pd.DataFrame(columns = chuck_columns)
for i in response:
    api_url = f'https://api.chucknorris.io/jokes/random?category={i}'
    response = requests.get(api_url).json()
    df = df.append(pd.Series([
         ",".join(response['categories']),
         response['created_at'],
         response['icon_url'],
         response['id'],
         response['updated_at'],
         response['url'],
         response['value']],
        index = chuck_columns), 
        ignore_index = True
    )

print(df)