type dna =
  | A
  | C
  | G
  | T

type rna =
  | A
  | C
  | G
  | U

let toRnaNucleotides = (dna: dna) =>
  switch dna {
  | G => C
  | C => G
  | T => A
  | A => U
  }

let toRna = dna => List.map(toRnaNucleotides, dna)
