#include <stdio.h>
#include <stdlib.h> // * We'll need this to access to the 'system()' function.
#include <ctype.h> // * Good practice, we'll need this in case the user enters an invalid character.

// ** COLORS FOR THE TERMINAL.
#define COLOUR_RED "\x1b[31m"
#define COLOUR_GREEN "\x1b[32m"
#define COLOUR_YELLOW "\x1b[33m"
#define COLOUR_BLUE "\x1b[34m"
#define COLOUR_CYAN "\x1b[36m"
#define COLOUR_RESET "\x1b[0m"

// ** WE'LL DEFINE A CONSTANT TO ESTABLISH THE MAX NUMBER OF OPTIONS.
#define MAX_OPTS 5

// ** TO STORE THE DIRECTION OF EACH FUNCTION, WE'LL DEFINE A POINTER TO A FUNCTION TO HAVE BETTER ACCESS TO THEM.
typedef void (*functionExecution)();

// ** WE DEFINE FUNCTIONS TO SHOW THE MENU, CLEAN THE BUFFER AND MANAGEMENT OF ERRORS.
void showMenu();
void cleanBuffer();
void invalidOption();

// ** WE DECLARE THE FUNCTIONS TO CALL OUR JAVA PROGRAMS.
void execute2ndOption();
void execute3rdOption();
void execute4thOption();
void execute5thOption();

// ** WE'LL DECLARE AN ARRAY FROM POINTERS TO FUNCTIONS.
functionExecution menuOptions[] = {
    invalidOption, // * Position [0].
    showMenu, // * Position [1].
    execute2ndOption, // * Position [2].
    execute3rdOption, // * Position [3].
    execute4thOption, // * Position [4].
    execute5thOption, // * Position [5].
};

// ** MAIN FUNCTION.
int main () {
    int option;

    // * We declare a 'while-loop' to show the menu.
    do {
        showMenu();
        printf("Choose an option (0 to leave the system): ");

        if (scanf("%d", &option) != 1) { // * In case the user enters a different data type.
            printf("\nERROR! Only integers are allowed.\n");
            cleanBuffer();
            option = -1;
        } else {
            cleanBuffer();
        }

        if (option == 0) { // * If the input is '0'.
            printf("\nClosing system... Thank you for using the program :)\n");
        } else if (option >= 1 && option <= MAX_OPTS) { // * If the option is available in the menu.
            printf("\n▀▄▀▄▀▄ INITIALIZING EXERCISE ▄▀▄▀▄▀\n");
            menuOptions[option]();
            printf("\n▀▄▀▄▀▄ EXERCISE FINISHED ▄▀▄▀▄▀\n");
        } else if (option != -1) { // * If the number is not in the range of options.
            invalidOption();
        }

        if (option != 0) { // * Pauses the program until the users presses 'ENTER'.
            printf("\nPress 'ENTER' to go back to the menu.\n");
        }
    } while (option != 0); // * Repeats the loop if the option is not equal to '0'.

    return 0;
}

// ** FUNCTIONS TO EXECUTE THE JAVA PROGRAM.
void execute2ndOption() {
    printf("[SYSTEM]:::: Executing Java Program - Fibonacci_Sequence.java\n");
    system("java -cp \"../../SantiagoProjects Java/Exercises/While\" Fibonacci_Sequence");
}

void execute3rdOption() {
    printf("[SYSTEM]:::: Executing Java Program - Numbers_Summation.java\n");
    system("java -cp \"../../SantiagoProjects Java/Exercises/While\" Numbers_Summation");
}

void execute4thOption() {
    printf("[SYSTEM]:::: Executing Java Program - Fractions_Summation.java\n");
    system("java -cp \"../../SantiagoProjects Java/Exercises/While\" Fractions_Summation");
}

void execute5thOption() {
    printf("[SYSTEM]:::: Executing Java Program - Print_Numbers.java\n");
    system("java -cp \"../../SantiagoProjects Java/Exercises/While\" Print_Numbers");
}

// ** DISPLAY FUNCTIONS
void showMenu() {
    printf("\n%s▌║█║▌│║▌│║▌║▌█║ PROJECT MENU ▌│║▌║▌│║║▌█║▌║█%s\n", COLOUR_RED, COLOUR_RESET);
    printf("%s1. Show menu.%s\n", COLOUR_GREEN, COLOUR_RESET);
    printf("%s2. Find Fibonacci Sequence.%s\n", COLOUR_GREEN, COLOUR_RESET);
    printf("%s3. Numbers series summation.%s\n", COLOUR_GREEN, COLOUR_RESET);
    printf("%s4. Fractions series summation.%s\n", COLOUR_GREEN, COLOUR_RESET);
    printf("%s5. While cycle for printing numbers pattern.%s\n", COLOUR_GREEN, COLOUR_RESET);
    printf("%s0. Leave the system.%s\n", COLOUR_CYAN, COLOUR_RESET);
}

// ** WE USE THIS FUNCTION TO DELETE THE '\n' TO NOT INTERFERE IN THE PROGRAM.
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ** FUNCTION IN CASE THE INPUT IS NOT CORRECT.
void invalidOption() {
    printf("%sInput isn't valid. Please enter a number between 0 and %d.%s\n", COLOUR_YELLOW, MAX_OPTS, COLOUR_RESET);
}