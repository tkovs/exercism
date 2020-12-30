let abbreviate = name =>
  (name |> Js.String.match([%re "/\\b\w/gmi"]))
  -> Belt.Option.getWithDefault([|""|])
  |> Array.fold_left((++), "")
  |> Js.String.toUpperCase