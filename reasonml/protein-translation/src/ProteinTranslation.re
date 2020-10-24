let rnaToProtein = (rna: string): string =>
  switch rna {
  | "AUG" => "Methionine"
  | "UUU" | "UUC" => "Phenylalanine"
  | "UUA" | "UUG" => "Leucine"
  | "UCU" | "UCC" | "UCA" | "UCG" => "Serine"
  | "UAU" | "UAC" => "Tyrosine"
  | "UGU" | "UGC" => "Cysteine"
  | "UGG" => "Tryptophan"
  | "UAA" | "UAG" | "UGA" => "STOP"
  | otherwise => otherwise
  }

let rec rnasStringToList = (rnas: string): list(string) => {
  let head = Js.String2.slice(rnas, ~from=0, ~to_=3)
  let tail = Js.String2.sliceToEnd(rnas, ~from=3)

  switch rnas {
  | "" => []
  | _ => [head, ...rnasStringToList(tail)]
  }
}

let rec rnasToProteins = (rnas: list(string)): list(string) =>
  switch rnas {
  | [] => []
  | [rna, ...tail] =>
    if (rnaToProtein(rna) === "STOP") {
      []
    } else {
      [rnaToProtein(rna), ...rnasToProteins(tail)]
    }
  }

let proteins = protein =>
  protein
  |> rnasStringToList 
  |> rnasToProteins