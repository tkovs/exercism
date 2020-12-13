let phoneNumber = number => {
    switch (number |> Js.String.match([%re "/\d+/g"])) {
        | Some (result) => {
            let cleaned = Js.Array.joinWith("", result)

            if (Js.String.length(cleaned) === 10) {
                if (Js.String.charAt(0, cleaned) === "0" || Js.String.charAt(0, cleaned) === "1"){
                    None
                } else if (Js.String.charAt(3, cleaned) === "0" || Js.String.charAt(3, cleaned) === "1"){
                    None
                } else {
                    Some(cleaned)
                }
            } else if (Js.String.length(cleaned) === 11 && Js.String.startsWith("1", cleaned)) {
                Some(Js.String.substringToEnd(~from=1, cleaned))
            } else {
                None
            }
        }
        | None => None
    }
}
