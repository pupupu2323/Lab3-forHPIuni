Piecewise Function Calculator
This repository contains a C++ console application that calculates a piecewise mathematical function for a given range of x values.

The project is based on the programming laboratory assignments. I also use this repository to practise Git and GitHub and to organize my work with the Waterfall model.
What the program does
The user enters four parameters:
Parameter	Description
n	Integer parameter used in the formulas (7 <= n < 100)
a	Left border of the interval
b	Right border of the interval (a <= b)
step	Step used to calculate the values (step >= 0)


The program calculates and prints y for each x in the interval [a, b].

The function has two branches:
- x < 3 — first part of the function.
- x >= 3 — second part of the function.
If step is 0, the borders must be equal (a == b), so the program calculates only one point. Use a dot for decimal numbers, for example 1.5.
Main features
- Input parameters from the keyboard.
- Read parameters from data.txt.
- Check input values and basic parameter conditions.
- Calculate both branches of the piecewise function.
- Display results in the console.
- Main menu and a short user guide.
How to use
When the program starts, it shows the main menu:
1. Start calculation with keyboard input.
2. Start calculation with file input.
3. Exit.
4. Show the main menu.
5. Show help.
For file input, data.txt must contain four values in this order: n, a, b, step. Values can be separated by spaces or new lines.

Example data.txt content:
7 1 5 0.5
The repository includes data.txt as an input file. Add your own values before selecting file input.

Repository structure
Lab3-forHPIuni/
├── .gitattributes
├── .gitignore
├── README.md
└── labb2-melnik/
    ├── labb2-melnik.cpp
    └── data.txt
Laboratory work
The repository is used throughout several university laboratory assignments. The work includes:
- Analysis and design: activity diagram, use case diagram, and application wireframe.
- C++ implementation: console menu, keyboard and file input, input validation, and function calculation.
- Testing: checking the function branches, input data, and file input.
- GitHub workflow: Waterfall milestones, Issues, branches, commits, and merging changes into main.
The next planned steps are to prepare the SRS document, improve the C++ code using functions and exception handling, and add unit tests.
Tools
- C++
- Visual Studio
- Git and GitHub
