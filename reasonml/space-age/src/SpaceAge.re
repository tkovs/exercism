type planet =
  | Mercury
  | Venus
  | Earth
  | Mars
  | Jupiter
  | Saturn
  | Neptune
  | Uranus

let earthYearInSeconds = 31557600.0

let yearInSeconds = planet =>
  switch planet {
  | Mercury => earthYearInSeconds *. 0.2408467
  | Venus => earthYearInSeconds *. 0.61519726
  | Earth => earthYearInSeconds
  | Mars => earthYearInSeconds *. 1.8808158
  | Jupiter => earthYearInSeconds *. 11.862615
  | Saturn => earthYearInSeconds *. 29.447498
  | Neptune => earthYearInSeconds *. 164.79132
  | Uranus => earthYearInSeconds *. 84.016846
  }

let ageOn = (planet, seconds) =>
  seconds /. yearInSeconds(planet)
