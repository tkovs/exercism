# Resistor Color

Resistors have color coded bands, where each color maps to a number. The first 2 bands of a resistor have a simple encoding scheme: each color maps to a single number.

These colors are encoded as follows:

- Black: 0
- Brown: 1
- Red: 2
- Orange: 3
- Yellow: 4
- Green: 5
- Blue: 6
- Violet: 7
- Grey: 8
- White: 9

Mnemonics map the colors to the numbers, that, when stored as an array, happen to map to their index in the array: Better Be Right Or Your Great Big Values Go Wrong.

More information on the color encoding of resistors can be found in the [Electronic color code Wikipedia article](https://en.wikipedia.org/wiki/Electronic_color_code)
## Source

Maud de Vries, Erik Schierboom [https://github.com/exercism/problem-specifications/issues/1458](https://github.com/exercism/problem-specifications/issues/1458)

## Building and testing
You will need the node package manager (npm) installed - download from [here](https://www.npmjs.com/get-npm)
There is one time setup for each exercise, which may take a few minutes:
```
npm install
```

Open two shells, and in the first, start the build process.
```
npm start
```

In the second, start the tests running.
```
npm test
```

As you edit the code, the two processes will continually rebuild and rerun the tests.