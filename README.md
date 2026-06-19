# FAST-NU Style Entry Test Simulator (C++)

A console mock of the FAST-NUCES entry test, built with **OOP + basic
procedural C++ only** — no STL containers (`vector`, `map`, etc.) and no
sorting/searching algorithms. Everything is plain fixed-size arrays and
linear loops, in the same style as the Ride Management System project.

## Test Rules

- A bank of **50 MCQs** (Math, English, Analytical/IQ) is hardcoded in the program.
- Every attempt randomly picks **20 distinct MCQs** from that bank — a
  different set (almost) every time.
- For every question you get a 3-option action menu:
  1. **Choose an Option** – pick A/B/C/D
  2. **Skip Question** – move on, come back to it later
  3. **End Test** – stop immediately and jump straight to your result
- After all 20 are gone through, the program **lists which ones you skipped**
  and lets you go back and answer them.
- Scoring: **+1** for a correct answer, **−0.25** for a wrong answer,
  **0** for a question left skipped.
- At the end you get your total score, percentage, and a category-wise
  breakdown (Math / English / Analytical), and can choose to retake the
  test with a fresh random set.

## OOP Concepts Used

| Concept | Where |
|---|---|
| Encapsulation | `Question` fields are private; accessed only via getters / `isCorrect()` / `display()` |
| Composition | `NUEntryTest` *has* an array of `Question` objects (the bank and the selected 20) |
| Enums for control flow | `QuestionOutcome { ANSWERED, SKIPPED, ENDED_TEST }` keeps the menu logic readable |
| Single Responsibility | `Question` only knows about one MCQ; `NUEntryTest` owns selection, flow, and scoring |

## No-DSA Design Notes

- The 50→20 random pick uses a plain `bool used[50]` array and a `while`
  loop that keeps rolling `rand() % 50` until 20 unused indices are found —
  no shuffle algorithm, no container.
- Finding skipped questions, tallying scores, and category breakdowns are
  all single `for` loops with simple counters — no sorting or searching.
- RNG is seeded once per program run using `chrono::high_resolution_clock`
  (finer-grained than `time(0)`, so two test attempts started in the same
  second still get genuinely different question sets).

## Project Structure

```
NUEntryTest/
├── Question.h / Question.cpp           # Single MCQ: text, 4 options, correct answer, category
├── NUEntryTest.h / NUEntryTest.cpp      # Controller: 50-question bank, random pick, menus, scoring
├── main.cpp                            # Entry point + retake loop
├── Makefile
└── README.md
```

## Build & Run

```bash
make        # compiles to ./nu_test
make run    # builds (if needed) and runs
make clean  # removes the binary
```

Or manually:
```bash
g++ -std=c++17 -o nu_test main.cpp Question.cpp NUEntryTest.cpp
./nu_test
```

## Sample Flow

```
Q1. [Math] 12 + 15 = ?
   A) 25   B) 27   C) 28   D) 26

1. Choose an Option   2. Skip Question   3. End Test
Enter choice (1-3): 2          <- skipped, moves to Q2

...(after all 20)...

You skipped 3 question(s): Q3, Q9, Q17
Would you like to go back and attempt them now? (y/n): y
--- Revisiting Skipped Question ---
...

TEST RESULT
Correct Answers   : 11  (+1 each)
Wrong Answers     : 7   (-0.25 each)
Skipped Questions : 2   (0 each)
Final Score       : 9.25 / 20
```

## Possible Extensions

- Add a countdown timer per question or for the whole test
- Load the question bank from a file instead of hardcoding it
- Track multiple candidates' results and rank them
- Add more sections (e.g. Physics for engineering-program tests)
