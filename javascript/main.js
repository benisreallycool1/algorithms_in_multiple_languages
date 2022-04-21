function create_stack(){
    let stack = [];
    return stack;
}

function check_empty(stack) {
    return stack.length == 0;
}

function push(stack,item) {
    stack.push(item)
    console.log("Pushed item: " + item)
}

function pop(stack) {
    if (check_empty(stack)){
        return "stack is empty"
    }
    return stack.pop();
}

function main() {
    let stack = create_stack()
    push(stack, 1)
    push(stack,2)
    push(stack,3)
    push(stack,4)
    console.log("popped item: " + pop(stack))
    console.log("stack: " + stack)
}
main()