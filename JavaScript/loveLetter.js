function processData(input) {
    var parse_fun = function (s) { return parseInt(s, 10); };

    var lines = input.split('\n');
    var T = parse_fun(lines.shift());

    for (var t = 0; t < T; t++) {
        var s = lines[t].trim();
        var res = 0;
        for (var i = 0; i < s.length / 2; i++) {
            res += Math.abs(s.charCodeAt(i) - s.charCodeAt(s.length - 1 - i));
        }
        console.log(res);
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
