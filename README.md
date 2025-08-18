# 🖥️ Compiler Design Lab

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](./docs/CONTRIBUTING.md)
[![Languages](https://img.shields.io/badge/languages-C%2B%2B%7CJava%7CKotlin%7CPython%7CJavaScript-blue)](README.md)

A comprehensive collection of compiler design implementations, assignments, and projects covering lexical analysis, syntax analysis, semantic analysis, code generation, and optimization techniques across multiple programming languages.

## 📋 Table of Contents

- [Overview](#overview)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Assignments](#assignments)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [Resources](#resources)
- [License](#license)

## 🔍 Overview

This repository contains practical implementations of various compiler design concepts and techniques. Each assignment demonstrates different aspects of compiler construction, from basic lexical analysis to advanced optimization techniques. The implementations are provided in multiple programming languages to showcase language-specific approaches and paradigms.

### Key Features

- 🔤 **Lexical Analysis**: Tokenization, regular expressions, finite automata
- 📝 **Syntax Analysis**: Parsing algorithms, grammar design, AST construction
- 🧠 **Semantic Analysis**: Type checking, symbol tables, scope management
- 🎯 **Code Generation**: Intermediate code, target code generation
- ⚡ **Optimization**: Code optimization techniques and algorithms
- 🔄 **Multi-language Support**: Implementations in C++, Java, Kotlin, Python, and JavaScript

## 🛠️ Technologies Used

| Language                                                                                                                     | Version     | Use Case                                                               |
| ---------------------------------------------------------------------------------------------------------------------------- | ----------- | ---------------------------------------------------------------------- |
| ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)                      | C++17+      | System-level compiler implementations, performance-critical components |
| ![Java](https://img.shields.io/badge/java-%23ED8B00.svg?style=for-the-badge&logo=openjdk&logoColor=white)                    | Java 11+    | Object-oriented compiler design, enterprise-level implementations      |
| ![Kotlin](https://img.shields.io/badge/kotlin-%237F52FF.svg?style=for-the-badge&logo=kotlin&logoColor=white)                 | Kotlin 1.8+ | Modern JVM-based compiler tools, DSL implementations                   |
| ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)                       | Python 3.8+ | Rapid prototyping, educational implementations                         |
| ![JavaScript](https://img.shields.io/badge/javascript-%23323330.svg?style=for-the-badge&logo=javascript&logoColor=%23F7DF1E) | ES6+        | Web-based compiler tools, transpilers                                  |

## 📁 Project Structure

```
CompilerDesign/
├── cpp/
│   └── Assainment/
│       └── 01/
│           ├── 001_Remove_space_and_comment_in_one_line.cpp
│           ├── input.c
│           └── output.txt
├── java/
│   └── assignments/
├── kotlin/
│   └── assignments/
├── python/
│   └── assignments/
├── javascript/
│   └── assignments/
├── docs/
│   └── CONTRIBUTING.md
├── tests/
├── .gitignore
├── README.md
└── LICENSE
```

## 📚 Assignments

### Phase 1: Lexical Analysis

- **Assignment 01**: Comment and Whitespace Removal
  - Remove single-line (`//`) and multi-line (`/* */`) comments
  - Normalize whitespace and formatting
  - **Languages**: C++, Java, Python
  - **Status**: ✅ Completed (C++)

### Phase 2: Syntax Analysis (Coming Soon)

- **Assignment 02**: Tokenizer Implementation
- **Assignment 03**: Recursive Descent Parser
- **Assignment 04**: LR Parser Generator

### Phase 3: Semantic Analysis (Coming Soon)

- **Assignment 05**: Symbol Table Management
- **Assignment 06**: Type Checking System
- **Assignment 07**: Scope Resolution

### Phase 4: Code Generation (Coming Soon)

- **Assignment 08**: Intermediate Code Generation
- **Assignment 09**: Target Code Generation
- **Assignment 10**: Register Allocation

### Phase 5: Optimization (Coming Soon)

- **Assignment 11**: Dead Code Elimination
- **Assignment 12**: Loop Optimization
- **Assignment 13**: Peephole Optimization

## 🚀 Getting Started

### Quick Start

1. **Clone the repository**

   ```bash
   git clone https://github.com/yourusername/CompilerDesign.git
   cd CompilerDesign
   ```

2. **Choose your language** and navigate to the appropriate directory:

   - `cpp/` for C++ implementations
   - `java/` for Java implementations
   - `python/` for Python implementations
   - `kotlin/` for Kotlin implementations
   - `javascript/` for JavaScript implementations

3. **Run an assignment** (example with C++):
   ```bash
   cd cpp/Assainment/01
   g++ -o comment_remover 001_Remove_space_and_comment_in_one_line.cpp
   ./comment_remover
   ```

### Prerequisites

- Git
- At least one of: C++ compiler, Java JDK, Python 3.8+, Kotlin compiler, Node.js

## 🎯 Usage

### Running C++ Assignments

```bash
# Navigate to the assignment directory
cd cpp/Assainment/01

# Compile the program
g++ -o comment_remover 001_Remove_space_and_comment_in_one_line.cpp

# Run the program
./comment_remover
```

### Running Java Assignments

```bash
# Navigate to Java assignment directory
cd java/assignments/01

# Compile
javac Assignment01.java

# Run
java Assignment01
```

### Running Python Assignments

```bash
# Navigate to Python assignment directory
cd python/assignments/01

# Run directly
python assignment01.py
```

### Running Kotlin Assignments

```bash
# Navigate to Kotlin assignment directory
cd kotlin/assignments/01

# Compile
kotlinc assignment01.kt -include-runtime -d assignment01.jar

# Run
java -jar assignment01.jar
```

### Running JavaScript Assignments

```bash
# Navigate to JavaScript assignment directory
cd javascript/assignments/01

# Run with Node.js
node assignment01.js
```

## 💡 Examples

### Example 1: Comment Removal (C++)

**Input (`input.c`):**

```c
#include <stdio.h>
int main(void)
{
    // Single Line Comment
    printf("Hello");
    /* Multi
    Line
    Comment
    */
    printf("World");
    
    return 0;
}
```

**Output:**

```c
#include <stdio.h> int main(void) { printf("Hello"); printf("World"); return 0; }
```

### Example 2: Lexical Analysis

**Input:**

```c
int x = 42;
```

**Expected Tokens:**

```
[KEYWORD:int] [IDENTIFIER:x] [OPERATOR:=] [NUMBER:42] [DELIMITER:;]
```

## 🤝 Contributing

We welcome contributions! Please see our [Contributing Guidelines](./docs/CONTRIBUTING.md) for details.

### Quick Contribution Guide

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/new-assignment`
3. **Make your changes** with proper documentation
4. **Test your code** thoroughly
5. **Submit a pull request** with clear description

### What You Can Contribute

- 🆕 New compiler design assignments
- 🐛 Bug fixes and improvements
- 📚 Documentation and examples
- 🧪 Test cases
- 🌐 Multi-language implementations

### Areas for Contribution

- Lexical analyzers
- Parsers and syntax analyzers
- Semantic analyzers
- Code generators
- Optimization algorithms
- Error handling systems

## 📖 Resources

### 📚 Books

- **"Compilers: Principles, Techniques, and Tools"** by Aho, Sethi, and Ullman (Dragon Book)
- **"Modern Compiler Implementation"** by Andrew Appel
- **"Engineering a Compiler"** by Cooper and Torczon

### 🌐 Online Courses

- [Stanford CS143: Compilers](https://web.stanford.edu/class/cs143/)
- [MIT 6.035: Computer Language Engineering](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-035-computer-language-engineering-sma-5502-fall-2005/)
- [Coursera: Compilers](https://www.coursera.org/learn/compilers)

### 🛠️ Tools

- **[Compiler Explorer](https://godbolt.org/)** - Online compiler and disassembler
- **ANTLR** - Parser generator for multiple languages
- **Flex/Bison** - Lexer and parser generators for C/C++
- **LLVM** - Modern compiler infrastructure

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

⭐ **Star this repository if you find it helpful!**

**Happy Coding! 🚀**
