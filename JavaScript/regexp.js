
process.stdin.resume();
process.stdin.setEncoding("ascii");

var input = "";

process.stdin.on("data", function (line) {
    input += line;
});

process.stdin.on("end", function () {
    console.log(re.test(input));
});

// declare var re here
 var re = new RegExp("([aeiou]).*\\1");
