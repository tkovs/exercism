let alphabet = [|
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
|]

let isPangram = sentence => {
    let clean = Js.String.toLowerCase(sentence)
    alphabet -> Belt.Array.every(char => (Js.String.indexOf(char, clean) !== -1))
}