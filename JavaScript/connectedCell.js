function processData(input) {
    //Enter your code here
    var inputValues = input.split(/\s+/);

    var m = inputValues[0];
    var n = inputValues[1];

    var M = [];

    for (i = 2; i < inputValues.length; ++i) {
        var row = parseInt((i - 2) / parseInt(n));
        var col = (i - 2) % parseInt(n);
        if (col == 0)
            M.push([]);

       M[row].push(inputValues[i]);
    }
    var max = 0;
    var tempMax = 0;

    for (i = 0; i < M.length; ++i) {
        for (p = 0; p < M[i].length; ++p) {
            tempMax = buildFind(M, i, p, m, n);
            if (tempMax > max)
                max = tempMax;
        }
    }

    console.log(max);
}

function buildFind (M, row, col, rSize, cSize) {
    var findValues = function (currRow, currCol) {
        var count = 0;

        if (M[currRow][currCol] != '1') {
            return count;
        } else {
            count = 1;
            M[currRow][currCol] = '0';
        }
        if (currRow != 0 && currCol != cSize - 1)
            count += findValues(currRow - 1, currCol + 1);
        if (currRow != 0)
            count += findValues(currRow - 1, currCol);
        if (currCol != 0 && currRow != 0)
            count += findValues(currRow - 1, currCol - 1);
        if (currCol != 0)
            count += findValues(currRow, currCol - 1);
        if (currRow != rSize - 1 && currCol != 0)
           count += findValues(currRow + 1, currCol - 1);
        if (currRow != rSize - 1)
            count += findValues(currRow + 1, currCol);
        if (currRow != rSize - 1 && currCol != cSize - 1)
            count += findValues(currRow + 1, currCol + 1);
        if (currCol != cSize - 1)
            count += findValues(currRow, currCol + 1);

        return count;
    }

    return findValues(row, col);
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
