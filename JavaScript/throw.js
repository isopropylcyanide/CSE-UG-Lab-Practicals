function processData(my_height) {
    try{
        if (my_height === NaN)
            throw new Error("notANumberError");
        if (my_height > 10)
            throw new Error("hugeHeightError");
        if (my_height < 4)
            throw new Error("tinyHeightError");
        console.log(my_height);
    }
    catch (err){
        console.log(err.message);
    }
}


process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
