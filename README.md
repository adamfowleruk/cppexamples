# cppexamples

This repository holds a set of working and full C++ examples.

I was frustrated with the lack of complete answers on StackOverflow.com and other
C++ and C best practice websites. So I decided to code my own solutions.

**WARNING:** This repo contains both Patterns and Anti-Patterns for C++14.

## Current solutions

- Using unique_ptr to avoid hanging pointers. Using them within a container class.
 - Solution: [testpointerwrapper.cpp](release/src/tesstpointerwrapper.cpp)
 - Anti Pattern - String Holder: [teststringholder.cpp](release/src/teststringholder.cpp)
 - Anti Pattern - String Reference: [teststringreference.cpp](release/src/teststringreference.cpp)

## How to build

First clone the repo.

Do the following from a console:-
```sh
cd cppexamples
./clean.sh
./gen-eclipse.sh
```

- Now open Eclipse and go to File -> Import, and point to the cppexamples/bin folder. Click OK to finish the import.
- Open 'targets' and right-click the testpointerwrapper target, select Build...
- Choose 'Build' in the dialog and click ok
- Under Binaries, right click the testpointerwrapper binary, and choose Run As-> Local C++ application
- Choose /mi and click ok
- You should see successful output
- Now try for the 'anti pattern' examples, and compare the output
- Read the solution source file for details on how to correctly use the pattern

Enjoy!

