function processData(input) {
    //Enter your code here
    var arr = input, max = 0;
    arr.sort();
    var elem = arr[arr.length -1];
    for (var i = arr.length -2, elem = arr[arr.length -1]; i >= 0; i--){
        if (arr[i] != elem){
            console.log(arr[i]);
            break;
        }
    }

}

console.log()


// var arr = [1,2,3,4,5];
// processData([1,2,3,4,5]);
