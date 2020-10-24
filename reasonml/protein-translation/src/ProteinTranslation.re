let toProtein = (rna: string): string =>
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

let rec proteins = str =>
  switch (String.sub(str, 0, 3) |> toProtein) {
  | exception Invalid_argument(_) => []
  | "STOP" => []
  | protein => [protein, ...proteins(String.sub(str, 3, String.length(str) - 3))]
  }