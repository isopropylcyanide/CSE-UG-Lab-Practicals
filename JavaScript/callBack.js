myFilter = (my_array, callback) => my_array.filter(callback)

processData = (inputArray) =>  console.log(inputArray.filter(x => x%2 == 0));

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input.split(' ').map(num => Number(num)));
});
