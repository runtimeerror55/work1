function pairSum(input, size, x, index) {
    let i = index;
    let j = size - 1;
    let count = 0
    while (i < j) {
        if (input[i] + input[j] == x) {
            let i1 = i, j1 = j
            while (input[i] == input[i1] && i1 <= j) {
                i1++
            }
            while (input[j] == input[j1] && j1 >= i) {
                j1--
            }
            if (input[i] == input[j]) {
                count += (i1 - i) * (i1 - i - 1) / 2
            }
            else {
                count += (i1 - i) * (j - j1)
            }
            i = i1
            j = j1
        }
        else if (input[i] + input[j] < x) {
            i++
        }
        else {
            j--
        }
    }
    return count
}

function tripletSum(input, size, x) {
    input.sort(function (a, b) { return a - b })
    let count = 0
    for (let i = 0; i < size - 2; i++) {
        count += pairSum(input, size, x - input[i], i + 1)
    }
    return count
}


const readline = require("readline-sync")
let t = Number(readline.question())
while (t--) {
    let size = Number(readline.question());
    let input = readline.question().split(" ").map(x => parseInt(x))
    let x = Number(readline.question())
    let answer = tripletSum(input, size, x)
    console.log(answer)
}