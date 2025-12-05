## :jigsaw: CARROLL SOLVER | WORD TRANSFORMATION SOLVER

### :open_book: OVERVIEW
Date: March 2023\
Developer(s): Ashneet Rathore\
Instructor: Michael Shindler

Carroll Solver is a program that solves word ladders, a game invented by Lewis Carroll in which a start word is transformed to a target word by changing one letter at a time, with each step forming a valid word. For example, to get from *"ate"* to *"oat"*, one possible sequence of words is *ate → ape → apt → opt → oat*. Word ladders remain popular today in early education and puzzle culture, as seen in digital offerings such as LinkedIn Games, which released the word ladder game *CrossClimb* in 2024. 

The program finds the shortest sequence of valid words transforming a start word into a target word. Users can input a start word and a target word of the same length from the dictionary, and the program outputs the resulting sequence.

### :gear: HOW IT WORKS
Written in **C++**, the program loads a dictionary of words from a file and represents each word as a node in a **search space**. It explores one-letter transformations to reach the target word. It uses a **custom priority-queue** to implement an informed, **A\* (A-star) style search**, prioritizing words based on steps taken and estimated letters remaining to the target. This algorithm is more efficient than the standard BFS (Breadth-First Search) or DFS (Depth-First Search), as it focuses on searching the most promising paths first. The dictionary and discovered words are stored in unordered sets for fast lookups, and a tree-based map tracks each word's predecessor to reconstruct the transformation path.

### :open_file_folder: PROJECT FILE STRUCTURE
```bash
CarrollSolver/
│── app/
    │── main.cpp              # Takes user input and runs solver
│   │── convert.cpp           # Implements search algorithm and constructs paths
│   │── convert.hpp           # Declares public functions for word ladder operations
│   │── MyPriorityQueue.hpp   # Implements binary min-heap priority queue
│   └── runtimeexcept.hpp     # Defines custom exception class
│── words.txt                 # Stores dictionary of valid words
│── README.md                 # Project documentation
│── .gitignore                # Specifies files and folders that shouldn't be included in the repo
```

### :rocket: CONFIGURATION
**1. Clone the repository**
```bash
git clone https://github.com/ashneetrathore/CarrollSolver.git
cd CarrollSolver
```
**2. Run the program with the following commands**
```bash
g++ -std=c++17 app/main.cpp app/convert.cpp -o app.exe
./app.exe
```

### :wrench: TRY IT OUT
Here are some example start and target words you can input:
- `ate` → `eat`
- `putters` → `hampers`
- `banking` → `brewing`
- `boosted` → `classes`
- `changes` → `glasses`
- `changes` → `smashed`