let rec removeLetter = (word: string, letter: string): string => {
  open Js.String2

  let head = charAt(word, 0)
  let tail = substringToEnd(word, ~from=1)

  if (head == letter) {
    tail
  } else {
    if (length(tail) == 0) {
      head
    } else {
      head ++ removeLetter(tail, letter)
    }
  }
}

let rec isAnagramAux = (word1, word2) => {
  open Js.String2

  let word1length = length(word1)
  let word2length = length(word2)

  if (word1length != word2length) {
    false
  } else if (word1length == 0) {
    true 
  } else {
    let head = charAt(word1, 0)
    let tail = substringToEnd(word1, ~from=1)
    isAnagramAux(tail, removeLetter(word2, head))
  }
}

let isAnagram = (word1, word2) => {
  open Js.String2

  let uppercaseWord1 = toUpperCase(word1)
  let uppercaseWord2 = toUpperCase(word2)
  uppercaseWord1 != uppercaseWord2 && isAnagramAux(uppercaseWord1, uppercaseWord2)
}

let anagrams = (word, candidates) =>
  List.filter(candidate => isAnagram(candidate, word), candidates)
