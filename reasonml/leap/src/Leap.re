let isLeapYear = year => {
  let byFour = year mod 4 == 0
  let byAHundred = year mod 100 == 0
  let byFourHundred = year mod 400 == 0

  byFourHundred || byFour && !byAHundred
}
