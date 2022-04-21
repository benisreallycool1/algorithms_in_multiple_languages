MAX = 5

class Deque {
    constructor(arr,front,rear,size) {
        this.arr = []
        this.front = front;
        this.rear = rear;
        this.size = size;
        front =-1;
        rear = 0;
    };
    isFull() {
        return ((this.front == 0 && this.rear == this.size -1) || this.front ==this.rear+1)
    }
    isEmpty() {
        return (this.front ==-1)
    }
    insertfront(key) {
        if (this.isFull()){
            console.log("Overflow")
            return
        }
        if (this.front == -1) {
            this.front = 0;
            this.rear = 0;
        } else if (this.front ==0) {
            this.front  = this.size -1;
        } else {
            this.front = this.front -1;
        }
        this.arr[this.front] = key;
    }
    insertrear(key) {
        if (this.isFull()) {
            console.log("Overflow")
            return
        }
        if (this.front == -1) {
            front =0;
            rear = 0;
        } else if (this.rear ==this.size-1) {
            this.rear = 0;
        } else {
            this.rear = this.rear +1;
        }
        this.arr[this.rear] =key
        console.log(this.arr)
    }
    deletefront() {
        if (this.isEmpty()) {
            console.log("Queue empty")
            return
        }
        if (this.front == this.rear) {
            this.front = -1;
            this.rear = -1;
        } else if (this.front = this.size -1) {
            this.front = 0
        } else {
            this.front = this.front +1
        }
    }
    deleterear() {
        if (this.isEmpty()) {
            console.log("Queue empty")
            return
        } if (this.front == this.rear) {
            this.front = -1;
            this.rear = -1;
        } else if (this.rear ==0) {
            this.rear = this.size - 1;
        } else {
            this.rear = this.rear -1;
        }
    }
    getfront() {
        if (this.isEmpty()) {
            console.log("Queue is empty")
            return (-1)
        }
        return this.arr[this.front]
    }
    getrear() {
        if (this.isEmpty()) {
            console.log("Queue is empty")
            return (-1)
        } 
        return this.arr[this.rear]
    }
    printarray() {
        console.log(this.arr)
    }
}

const main = () => {
    let dq = new Deque();
    dq.insertrear(5);
    dq.insertrear(6);
    dq.printarray();
    dq.deletefront();
    dq.printarray();
}
main()