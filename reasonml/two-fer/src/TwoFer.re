let twoFer = name =>
  switch name {
    | None => "One for you, one for me."
    | Some(n) => "One for " ++ n ++ ", one for me."
  }
