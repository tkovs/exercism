open Jest;
open Expect;
open Anagram;

describe("Anagram", () => {
  describe("removeLetter", () => {
    test("with no ocurrences", () => {
      expect(removeLetter("tkovs", "u")) |> toEqual("tkovs")
    })
    test("with 1 ocurrence on begin", () => {
      expect(removeLetter("tkovs", "t")) |> toEqual("kovs")
    })
    test("with 1 ocurrence on middle", () => {
      expect(removeLetter("tkovs", "o")) |> toEqual("tkvs")
    })
    test("with 1 ocurrence on end", () => {
      expect(removeLetter("tkovs", "s")) |> toEqual("tkov")
    })
    test("with 2 ocurrences", () => {
      expect(removeLetter("joao", "o")) |> toEqual("jao")
    })
  })
  describe("isAnagram", () => {
    test("no match", () => {
      expect(isAnagram("stream", "bubble")) |> toEqual(false)
    })
    test("detects anagram", () => {
      expect(isAnagram("stream", "master")) |> toEqual(true)
    })
    test("word is not anagram of itself", () => {
      expect(isAnagram("stream", "stream")) |> toEqual(false)
    })
  })
  describe("anagrams", () => {
    test("no matches", () =>
      expect(anagrams("diaper", ["hello", "world", "zombies", "pants"])) |> toEqual([])
    )
    test("detects two anagrams", () =>
      expect(anagrams("master", ["stream", "pigeon", "maters"])) |> toEqual(["stream", "maters"])
    )
    test("does not detect anagram subsets", () =>
      expect(anagrams("good", ["dog", "goody"]))  |> toEqual([])
    )
    test("detects anagram", () =>
      expect(anagrams("listen", ["enlists", "google", "inlets", "banana"]))  |> toEqual(["inlets"])
    )
    test("detects three anagrams", () =>
      expect(anagrams("allergy", ["gallery", "ballerina", "regally", "clergy", "largely", "leading"]))  |> toEqual(["gallery", "regally", "largely"])
    )
    test("detects multiple anagrams with different case", () =>
      expect(anagrams("nose", ["Eons", "ONES"]))  |> toEqual(["Eons", "ONES"])
    )
    test("does not detect non-anagrams with identical checksum", () =>
      expect(anagrams("mass", ["last"]))  |> toEqual([])
    )
    test("detects anagrams case-insensitively", () =>
      expect(anagrams("Orchestra", ["cashregister", "Carthorse", "radishes"]))  |> toEqual(["Carthorse"])
    )
    test("detects anagrams using case-insensitive subject", () =>
      expect(anagrams("Orchestra", ["cashregister", "carthorse", "radishes"])) |> toEqual(["carthorse"])
    )
    test("detects anagrams using case-insensitive possible matches", () =>
      expect(anagrams("orchestra", ["cashregister", "Carthorse", "radishes"])) |> toEqual(["Carthorse"])
    )
    test("does not detect a anagram if the original word is repeated", () =>
      expect(anagrams("go", ["go Go GO"])) |> toEqual([])
    )
    test("anagrams must use all letters exactly once", () =>
      expect(anagrams("tapper", ["patter"])) |> toEqual([])
    )
    test("words are not anagrams of themselves (case-insensitive)", () =>
      expect(anagrams("BANANA", ["BANANA", "Banana", "banana"])) |> toEqual([])
    )
    test("words other than themselves can be anagrams", () =>
      expect(anagrams("LISTEN", ["Listen", "Silent", "LISTEN"])) |> toEqual(["Silent"])
    )
  })
})


