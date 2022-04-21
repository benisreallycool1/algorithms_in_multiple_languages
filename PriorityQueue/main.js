
const swap = (a,b) => {
    temp = b
    b = a
    a = temp
    
}

const heapify = (arr,n,i) => {
    largest = i
    l = 2 * i + 1
    r = 2*i + 2
    if (l < n && arr[i] < arr[l]) {
        largest = l
    }
    if ( r < n && arr[largest < arr[r]]) {
        largest = r
    }
    if (largest !=i){
        swap(arr[i],arr[largest])     
    }
}

const insert = (array, newNum) => {
    coolsize = array.length
    if (coolsize == 0) {
        array.push(newNum)
    } else {
        array.push(newNum)
        for (i = coolsize/2 -1; i>=0; i--){
            heapify(array,coolsize,i)
        }
    }
}

const deleteNode = (array,num) => {
    coolsize = array.length
    for (i = 0; i<=coolsize; i++) {
        if ( num == array[i]){
            break
        }
    }
    swap(array[i],array[coolsize-1])
    array.splice(coolsize-1)
    for (i = coolsize/2 -1; i>=0; i--){
        heapify(array,i)
    }
}

const printArray = (array) => {
    for (i =0; i<array.length; i++){
        console.log(array[i])
    }
}

const main = () => {
    heapTree = []
    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);
    printArray(heapTree);
    deleteNode(heapTree, 4);
    console.log("new: ")
    printArray(heapTree)
}
main()