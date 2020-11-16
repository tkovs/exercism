let positions = (line, column) => [|
  (line - 1, column - 1),
  (line - 1, column),
  (line - 1, column + 1),
  (line, column - 1),
  (line, column),
  (line, column + 1),
  (line + 1, column - 1),
  (line + 1, column),
  (line + 1, column + 1),
|];

let sum = Array.fold_left((result, value) => result + value, 0);

let getBombs = (lines, line, column) => {
  let bombs =
    positions(line, column)
    |> Array.map(coord => {
         let (l, c) = coord;

         switch (Js.String2.charAt(lines[l], c)) {
         | "*" => 1
         | exception (Invalid_argument(_)) => 0
         | _ => 0
         };
       })
    |> sum;

  bombs === 0 ? " " : string_of_int(bombs);
};

let annotate = lines => {
  lines
  |> Array.mapi((l, line) => {
       Js.String2.split(line, "")
       |> Array.mapi((c, column) => {
            switch (column) {
            | " " => getBombs(lines, l, c)
            | otherwise => otherwise
            }
          })
       |> Js.String2.concatMany("")
     });
};
