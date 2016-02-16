function processData(input) {
    //Enter your code here
    var inp = input.split('\n');
    var first = inp[0].split(' ').map(Number);
    var arr = inp[1].split(' ').map(Number);
    var n = first[0],
        k = first[1];

    arr.sort(function(a, b) {
        return a - b;
    });

    var sum = 0,
        count = 0;
    for (var a in arr) {
        if (sum + arr[a] > k)
            break;
        else {
            sum += arr[a];
            count += 1;
        }
    }
    console.log(count);
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function(input) {
    _input += input;
});

process.stdin.on("end", function() {
    processData(_input);
});
