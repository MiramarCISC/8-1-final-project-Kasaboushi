# Thomas Qassar Final Project: The Poke-Manager

## Description
   This program is designed to store a file containing information of pokemon and perform various operations regarding said list, such as sorting and printing by various parameters and tracking collections. It implements a linked list to create a list of team members and write it out to a file, and it can also write out the current status of a collection to external files.
## Compile Instructions
The makefile is included with everything necessary for compilation. As long as you have a C++ compiler installed, simply type ```make run``` into your terminal.
## Run Instructions
```./main``` will work, and so will ```make run```. Type into the terminal to execute.
## Test Instructions
Type ```make test``` to automatically run the tests.
## Course Topics Integrated and Tested

1. Week 1 Program Basics
   - Code location:  project.cpp, gradeMessage(),percentCaught()
   - Test location: test_project.cpp
   - Accessed through Show Completion options.

2. Week 2 Decisions and Loops
   - Code location: project.cpp, isValidChoice(), findPokemon()
   - Test location: test_project.cpp
   - Accessed through nearly any choice.

3. Week 3 Functions and Program Design
   - Code location: project.cpp, percentCaught()
   - Test location: test_project.cpp
   - Accessed through Show Completion option.

4. Week 4 Arrays, Searching, and Sorting
   - Code location:  project.cpp, findPokemon()
   - Test location: test_project.cpp
   - Can be accessed through Sort/Filter or Toggle Caught.

5. Week 5 Strings and Structures
   - Code location: project.hpp, test_project.cpp (Pokemon structures and data inside)
   - Test location: test_project.cpp
   - Can be accessed through any function involving Pokemon management, so just about every function.

6. Week 6 Pointers, Dynamic Memory, and Linked Lists
   - Code location: project.cpp, createTeamMember(), deleteAllMembers()
   - Test location: test_project.cpp
   - Can be accessed through Open Teambuilder

7. Week 7 File I/O and Integration
   - Code location: project.cpp, savePokemonToFile(), writeTeamOut(), writeReport()
   - Test location: test_project.cpp
   - Can be accessed through "Write to File" from the menu or under Open Teambuilder, Save Team.
