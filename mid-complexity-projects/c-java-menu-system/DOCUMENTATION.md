# C & Java Menu System - Technical Documentation

## Table of Contents

1. [Overview](#overview)
2. [Key Concepts](#key-concepts)
3. [Functions](#functions)
4. [Color Constants](#color-constants)

---

## Overview

This program implements an interactive menu system written in C that allows users to execute different Java programs. It demonstrates key C concepts like function pointers, arrays, input validation, and system calls.

---

## Key Concepts

### Function Pointers

A function pointer is a variable that stores the memory address of a function. In this program, we use function pointers to create a flexible menu system.

```c
typedef void (*functionExecution)();
```

This creates a type `functionExecution` that points to any function returning `void`.

### Array of Function Pointers

The `menuOptions` array stores pointers to different functions, allowing us to call them dynamically based on user input.

```c
functionExecution menuOptions[] = {
    invalidOption,      // Position [0]
    showMenu,          // Position [1]
    execute2ndOption,  // Position [2]
    // ...
};
```

---

## Functions

### main()

The entry point of the program. Manages the main loop, user input, and program flow.

**Logic:**
- Displays the menu in a loop
- Reads user input (validates that it's an integer)
- Executes the corresponding function based on user choice
- Continues until user selects option 0

---

### showMenu()

The function that will display the menu with all available options in the terminal.

**Output:**
```
▌║█║▌│║▌│║▌║▌█║ PROJECT MENU ▌│║▌║▌│║║▌█║▌║█
1. Show menu.
2. Find Fibonacci Sequence.
3. Numbers series summation.
4. Fractions series summation.
5. While cycle for printing numbers pattern.
0. Leave the system
```

---

### cleanBuffer()

The purpose of this functions is that it clears the input buffer by removing any leftover characters (like newline `\n`). This prevents input errors in subsequent reads.

**Why it's needed:** After `scanf()` reads input, the newline character stays in the buffer. This function removes it.

---

### invalidOption()

It will display an error message in case the user enters an invalid option (outside the range 0-5).

**Output:** 
```
Input isn't valid. Please enter a number between 0 and 5.
```

---

### execute2ndOption() / execute3rdOption() / execute4thOption() / execute5thOption()

Each functions serves to execute a specific Java program by using the `system()` function to run Java commands in the terminal.

**Example (execute2ndOption):**
```c
system("java -cp \"../../SantiagoProjects Java/Exercises/While\" Fibonacci_Sequence");
```

This runs the Java class `Fibonacci_Sequence` from the specified classpath.

---

## Color Constants

The program uses ANSI escape codes to add colors to terminal output.

| Constant | Color | Code |
|----------|-------|------|
| `COLOUR_RED` | Red | `\x1b[31m` |
| `COLOUR_GREEN` | Green | `\x1b[32m` |
| `COLOUR_YELLOW` | Yellow | `\x1b[33m` |
| `COLOUR_BLUE` | Blue | `\x1b[34m` |
| `COLOUR_CYAN` | Cyan | `\x1b[36m` |
| `COLOUR_RESET` | Reset | `\x1b[0m` |

**Usage:**
```c
printf("%sThis text is green%s\n", COLOUR_GREEN, COLOUR_RESET);
```

---

## Program Flow

```
PROGRAM INITIALIZES
  ↓
SHOWS MENU
  ↓
READS USER INPUT
  ↓
THE USER ENTERED A VALID INPUT? → NO → SHOWS ERROR → CLEANS BUFFER → SHOWS MENU
  ↓ YES
USER SELECTED OPTION 0? → YES → THE PROGRAM FINALIZES
  ↓ NO
EXECUTES THE FUNCTION BASED ON WHICH OPTION THE USER ENTERED
  ↓
JAVA PROGRAM STARS
  ↓
JAVA PROGRAM ASKS FOR AN INPUT
  ↓
JAVA PROGRAM SHOWS THE OUTPUT
  ↓
THE USER WANT TO REPEAT THE EXERCISE? → YES → ASKS FOR ANOTHER INPUT → JAVA PROGRAM REPEATS 
  ↓ NO
SHOWS MENU (it will display repeatedly until the option is equal to 0)
```
