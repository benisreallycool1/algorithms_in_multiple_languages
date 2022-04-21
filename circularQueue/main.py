size = 5

class Queue:
    def ___init__(self,items,front,rear):
            self.items=items[size]
            self.front =front 
            self.rear = rear
    def isFull(self):
        if self.front == 0 and self.rear == size -1:
            return True
        elif self.front == self.rear + 1:
            return True
        else:
            return False
    def isEmpty(self):
        if self.front == -1:
            return True
        else:
            return False
    def enQueue(self,element):
        if self.isFull():
            print("Queue is full")
        else:
            if self.front == -1:
                self.front = 0
            self.rear = (self.rear + 1) % size
            self.items[self.rear] = element
            print("Inserted: " + element)
    def deQueue(self):
        if self.isEmpty():
            print("Queue is empty")
            return (-1)
        else:
            element = self.items[self.front]
            if self.front == self.rear:
                self.front = -1
                self.rear = -1
            else:
                self.front = (self.front + 1) % size
            return element
    def display(self):
        if self.isEmpty():
            print("Nothing to see here ...  Empty queue.")
        else:
            print("Front: " + self.front)
            print("Items: ", end=" ")
            i = self.front
            while (i!=self.rear):
                print(self.items[i])
                i = (i + 1) % size
            print(self.items[i])
            print("Rear: " + self.rear)   
if __name__ == '__main__':
     q = Queue()
     q.enQueue(1)