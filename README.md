# Data Structures And Algorithms

A comprehensive collection of data structures and algorithms implementations in C and C++. This repository contains practical implementations with detailed documentation, test cases, and examples for learning and reference purposes.

## 📚 Table of Contents

- [Overview](#overview)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage Examples](#usage-examples)
- [Complexity Analysis](#complexity-analysis)
- [Contributing](#contributing)
- [License](#license)

## 🌟 Overview

This repository serves as a learning resource and reference implementation for fundamental data structures and algorithms. Each implementation includes:

- **Clean, well-documented code**
- **Comprehensive test cases**
- **Time and space complexity analysis**
- **Practical usage examples**
- **Multiple implementation approaches where applicable**

## 🏗️ Data Structures

### Arrays
- **Location**: `Array/`, `Array.xcodeproj/`
- **Features**:
  - Static and dynamic array implementations
  - Array operations: insert, delete, search, append
  - Binary search (recursive and iterative)
  - Array manipulation: shift, rotate, reverse
  - Set operations: union, intersection, difference
  - Duplicate detection and removal
  - Missing element finding algorithms
  - Pair finding for given sum

### Linked Lists
- **Location**: `Linkedlist/`, `linkedlists/`
- **Implementations**:
  - **Singly Linked List**: Basic operations, search, insertion, deletion
  - **Doubly Linked List**: Bidirectional traversal
  - **Circular Linked List**: Circular structure implementation
- **Features**:
  - Recursive and iterative traversals
  - List reversal algorithms
  - Duplicate removal
  - List merging and concatenation
  - Loop detection
  - Middle node finding

### Stacks
- **Location**: `Stacks/`, `Stack_w_Array/`, `Stack_w_linkedlist/`
- **Implementations**:
  - **Array-based Stack**: Fixed size with overflow handling
  - **Linked List-based Stack**: Dynamic size
  - **Character Stack**: Specialized for character operations
- **Operations**: Push, Pop, Peek, isEmpty, Display

### Queues
- **Location**: `Queues/`, `Queue_w_array/`, `Queue_w_linkedlist/`, `Queue_w_stack/`
- **Implementations**:
  - **Array-based Queue**: Linear and circular implementations
  - **Linked List-based Queue**: Dynamic size
  - **Stack-based Queue**: Implementation using two stacks
- **Features**:
  - Standard queue operations (enqueue, dequeue)
  - Circular queue to optimize space usage
  - Queue implementation with stacks for educational purposes

### Trees
- **Location**: `BinarySearchTree/`, `Trees-practice/`
- **Implementations**:
  - **Binary Search Tree**: Insertion, search, traversals
  - **General Tree**: Basic tree operations with queue-based level order
- **Features**:
  - Tree traversals: Pre-order, In-order, Post-order (recursive and iterative)
  - Level-order traversal using queues
  - Tree construction and manipulation

### Graphs
- **Location**: `Graphs/`, `Graphs-Practice/`
- **Implementations**:
  - **Adjacency List**: Dynamic graph representation
  - **Adjacency Matrix**: Fixed-size graph representation
- **Features**:
  - Graph traversals: Depth-First Search (DFS), Breadth-First Search (BFS)
  - Graph construction and manipulation
  - Visited node tracking

## 🧮 Algorithms

### Sorting Algorithms
- **Location**: `Sorting Algorithms/`
- **Implementations**:
  - **Merge Sort**: Recursive and iterative implementations
  - **Time Complexity**: O(n log n)
  - **Space Complexity**: O(n)
- **Features**:
  - Detailed algorithm explanation with examples
  - Step-by-step visualization comments
  - Both stable implementations

### Searching Algorithms
- **Linear Search**: O(n) with optimization techniques
- **Binary Search**: O(log n) recursive and iterative
- **Set membership**: Optimized for sorted and unsorted data

### Recursion
- **Location**: `Recursion/`
- **Types**:
  - **Tail Recursion**: Optimizable recursive calls
  - **Head Recursion**: Non-tail recursive implementations
- **Applications**: Mathematical computations, tree traversals

### String Operations
- **Location**: `Strings/`
- **Features**: String manipulation and processing algorithms

## 📂 Project Structure

```
Data_Structures_And_Algorithm/
├── Array/                     # Array implementations and operations
├── BinarySearchTree/          # BST implementation in C++
├── Graphs/                    # Graph data structure and algorithms
├── Graphs-Practice/           # Additional graph practice problems
├── Linkedlist/                # Various linked list implementations
├── linkedlists/               # Additional linked list projects
├── Queue_w_array/             # Array-based queue implementations
├── Queue_w_linkedlist/        # Linked list-based queue
├── Queue_w_stack/             # Queue implementation using stacks
├── Queues/                    # General queue implementations
├── Recursion/                 # Recursion examples and types
├── Review/                    # Code review and practice
├── Sorting Algorithms/        # Sorting algorithm implementations
├── Stack_w_Array/             # Array-based stack
├── Stack_w_linkedlist/        # Linked list-based stack
├── Stacks/                    # General stack implementations
├── Strings/                   # String processing algorithms
├── Trees-practice/            # Tree implementations and practice
└── README.md                  # This file
```

## 🚀 Getting Started

### Prerequisites
- **C Compiler**: GCC or Clang
- **C++ Compiler**: G++ or Clang++
- **IDE**: Xcode (for .xcodeproj files) or any text editor
- **Operating System**: macOS, Linux, or Windows

### Compilation

#### For C files:
```bash
gcc -o program_name source_file.c
./program_name
```

#### For C++ files:
```bash
g++ -o program_name source_file.cpp
./program_name
```

#### For Xcode projects:
Open the `.xcodeproj` file in Xcode and build/run the project.

### Running Examples

Each directory contains main files with test cases. For example:

```bash
# Array operations
cd Array/Array/
gcc -o array_demo main.c
./array_demo

# Binary Search Tree
cd BinarySearchTree/
g++ -o bst_demo binarySearchTree_main.cpp BinarySearchTree.cpp
./bst_demo

# Graph algorithms
cd Graphs-Practice/Graphs-Practice/
gcc -o graph_demo main.c
./graph_demo
```

## 💡 Usage Examples

### Array Operations
```c
// Create and manipulate arrays
struct dynamicArray arr = createDynamicStruct();
dynamicArray_append(&arr, 10);
dynamicArray_insertAtIndex(&arr, 0, 5);
int index = dynamicArray_linearSearch(&arr, 10);
```

### Binary Search Tree
```cpp
// BST operations
BinarySearchTree bst;
bst.insert(50);
bst.insert(30);
bst.insert(70);
bool found = bst.searchTree(30);
bst.in_order(); // Print in sorted order
```

### Graph Traversal
```c
// DFS traversal
int visited[8] = {0};
DFS(1); // Start DFS from vertex 1

// BFS traversal
BFS(1); // Start BFS from vertex 1
```

## ⚡ Complexity Analysis

### Time Complexities

| Data Structure | Operation | Average Case | Worst Case |
|----------------|-----------|--------------|------------|
| Array | Access | O(1) | O(1) |
| Array | Search | O(n) | O(n) |
| Array | Insertion | O(n) | O(n) |
| Array | Deletion | O(n) | O(n) |
| Linked List | Access | O(n) | O(n) |
| Linked List | Search | O(n) | O(n) |
| Linked List | Insertion | O(1) | O(1) |
| Linked List | Deletion | O(1) | O(1) |
| Stack | Push/Pop | O(1) | O(1) |
| Queue | Enqueue/Dequeue | O(1) | O(1) |
| BST | Search/Insert/Delete | O(log n) | O(n) |

### Algorithm Complexities

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |
| Merge Sort | O(n log n) | O(n) |
| DFS/BFS | O(V + E) | O(V) |

## 🎯 Key Features

### Educational Focus
- **Detailed Comments**: Every implementation includes comprehensive explanations
- **Multiple Approaches**: Different implementation strategies for the same concept
- **Test Cases**: Extensive testing with various scenarios
- **Performance Analysis**: Time and space complexity discussions

### Advanced Topics
- **Optimization Techniques**: Improved search algorithms with transposition
- **Edge Case Handling**: Comprehensive coverage of boundary conditions
- **Alternative Implementations**: Multiple ways to solve the same problem
- **Real-World Applications**: Practical use cases and examples

## 🛠️ Development Environment

This project was developed and tested on:
- **macOS**: Primary development environment
- **Xcode**: IDE with project files included
- **GCC/Clang**: Command-line compilation
- **Language Standards**: C99/C11 and C++11/C++14


## 📄 License

This project is open source and available under the [MIT License](LICENSE).