let size = 0;

let maxSize = 10;

class stack {
    constructor(items,top){
        this.items = items[maxSize];
        this.top = top
    }
}

let s = new stack();

function empty() {
    s.top = -1;
}

function isfull() {
    if (s.top == maxSize - 1){
        return 1;
    } else {
        return 0;
    }
}

function isempty() {
    if (s.top == -1){
        return 1;
    } else {
        return 0;
    }
}

function push(newItem) {
    if(isfull(s)){
        console.log("Stack is full, can't do anything");
    } else {
        s.top ++;
        s.items[s.top] = newItem;
    }
    size++;
}

function pop() {
    if(isempty(s)){
        console.log("Is empty, can't pop anything")
    } else {
        console.log("Item popped: " + s.items[s.top]);
        s.top --;

    } 
    size --;
}

function printStack() {
    console.log("stack: ")
    for (i=0; i<size; i++){
        print(s.items[i]);
    }
}

function main() {
    empty(s)

    push(s,1)
    push(s,2)

    printStack(s)

    pop(s)

    printStack(s)
}