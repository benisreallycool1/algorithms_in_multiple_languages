def swap(a,b):
    temp = b
    b = a
    a = temp
def heapify(hT,i,n):
    largest = i
    l = 2*i + 1
    r = 2*i + 2
    if l < n and hT[l]> hT[largest]:
        largest = l
    if r < n and hT[r] > hT[largest]:
        largest = r
    if largest != i:
        swap(hT[i], hT[largest])
        heapify(hT,n,largest)
def insert(hT, newNum):
    size = len(hT)
    if size == 0:
        hT.append(newNum)
    else:
        hT.append(newNum)
        i = size/2 -1
        while i >=0:
            heapify(hT,size,i)
            i-=1
def deleteNode(hT, num):
    size = len(hT)
    i=0
    while i <size:
        if num == hT[i]:
            break
        i+=1
    swap(hT[i],hT[size-1])
    hT.remove(size-1)
    j = size/2 - 1
    while j >=0:
        heapify(hT,size,j)
        j-=1
def printArray(hT):
    i = 0
    while i <len(hT):
        print(hT[i],end=' ')
        i+=1


if __name__ == "__main__":
    heapTree = []
    insert(heapTree, 3)
    insert(heapTree, 4)
    insert(heapTree, 9)
    insert(heapTree, 5)
    insert(heapTree, 2)
    printArray(heapTree)
    print(" ")
    print("new: ")
    deleteNode(heapTree,4)
    printArray(heapTree)