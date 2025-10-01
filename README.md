# Interview questions

## Requirements

- clang++ >= 17.0.0
- cmake >= 3.28
- Ninja 

## Build

To build the project run in the project's root directory:

```
$ cmake -G Ninja -S . -B build -DCMAKE_BUILD_TYPE=[debug/release]
$ cmake --build build
```

## Run

To launch the app run in the project's root directory:

```
$ ./build/bin/[debug/release]/interview_questions
```
