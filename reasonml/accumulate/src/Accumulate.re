let rec accumulate = (f, elements) =>
  switch elements {
  | [] => []
  | [head, ...tail] => [f(head), ...accumulate(f, tail)]
  }