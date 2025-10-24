# Interview Questions

A modern C++20 application demonstrating solutions to common technical interview problems with clean architecture and comprehensive testing.

## About

This project is developed for **educational purposes** to explore and practice:
- Latest C++20 features and modern C++ programming techniques
- Software design patterns and clean code principles
- Professional development tools and workflows

As a learning project, some parts may be intentionally over-engineered to demonstrate various features and practices that wouldn't necessarily be required for simpler solutions. The goal is knowledge acquisition and skill development rather than minimal implementation.

### Current Problems

- **Two Tourists**: Find the maximum distance two tourists can travel together along an elevation path, where they can move forward only when elevations are decreasing or equal.
- **Max Sum**: Find the maximum sum of two non-adjacent two-digit numbers that can be formed from a string of digits.

## Requirements

### Compiler and Build Tools

- **C++ Compiler**: clang++ >= 17.0.0 (with C++20 modules support)
- **Build System**: CMake >= 3.28
- **Build Tool**: Ninja

### Platform

- Tested on macOS
- Should work on Linux with appropriate compiler versions
- Windows support may require additional configuration

## Build

### Configure and Build

To build the project, run the following commands in the project's root directory:

```bash
# Configure the project (Debug or Release)
cmake -G Ninja -S . -B build -DCMAKE_BUILD_TYPE=Debug

# Build the project
cmake --build build
```

For a release build, use `-DCMAKE_BUILD_TYPE=Release` instead.

### Build Options

- `BUILD_TESTS`: Build test suite (default: ON)

To disable tests:
```bash
cmake -G Ninja -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=OFF
```

### Run

To launch the application, run from the project's root directory:

```bash
# For Debug build
./build/bin/Debug/interview_questions

# For Release build
./build/bin/Release/interview_questions
```

### Testing

To run the test suite:

```bash
# Run all tests
cd build
ctest

# Or run test executables directly
./build/bin/Debug/unit_tests
./build/bin/Debug/integration_tests
```

## Project Structure

```
interview_questions/
├── src/                    # Source code
│   ├── generators/         # Problem data generators
│   ├── solvers/            # Problem solving algorithms
│   ├── mediators/          # Coordination layer
│   ├── problems/           # Problem repository
│   ├── exceptions/         # Custom exceptions
│   └── utils/              # Utility functions
├── tests/                  # Test suite
│   ├── unit/               # Unit tests
│   ├── integration/        # Integration tests
│   ├── mocks/              # Mock objects
│   └── fixtures/           # Test fixtures
├── resources/              # Resource files
└── build/                  # Build output (generated)
```

## Contributing

Feel free to add new interview problems by:
1. Creating a generator implementing `IGenerator<ArgsType>`
2. Creating a solver implementing `ISolver<ArgsType, ReturnType>`
3. Adding the problem to `ProblemName` enum
4. Registering it in `MediatorFactory`

## License

MIT License

Copyright (c) 2025 rudnt

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---

Created by rudnt
