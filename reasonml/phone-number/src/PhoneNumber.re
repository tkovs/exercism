let phoneNumber = phone => {
  let filterNumbers = Js.String.replaceByRe([%re "/[^0-9]/g"], "");
  let matchPhoneNumber =
    Js.String.match([%re "/^1?((?:[2-9][0-9]{2}){2}[0-9]{4})$/"]);

  (phone |> filterNumbers |> matchPhoneNumber)->(Belt.Option.map(r => r[1]));
};
