
process.stdin.resume();
process.stdin.setEncoding("ascii");

var input = "";

process.stdin.on("data", function (line) {
    input += line;
});

process.stdin.on("end", function () {
     vowelsAndConsonants(input);
});

// complete the function
function vowelsAndConsonants(s) {
    vowel = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0};
    v = [];
    c = [];
    for (var i in s){
        if (s[i] in vowel)
            v.push(s[i]);
        else c.push(s[i]);
    }
    for (var i in v)
        console.log(v[i])
    for (var i in c)
        console.log(c[i])
}
