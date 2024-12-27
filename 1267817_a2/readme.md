# CIS2520-F24-A2

## Student Information 
Name : Elise Pitre

Student Number : 1267817

## Assignment Overview
q1:
    Takes as input a fully parenthesized, arithmetic expression of binary operators +, −, *, /, and converts the expression into a binary expression
    tree. The program takes input from the command line. The entire expression must be in a character string without any space in it.
    An input string only includes floating numbers in the format of Y.YY, that is, one digit to the left of the decimal point and two digits to the right of the decimal point, and variables of the form of x1, x2, x3, ...

    The menu offers the user the following options:
    1. Preorder (print expression in pre order)
    2. Inorder (print expression in order)
    3. Postorder (print expression in post order)
    4. Calculate (prompts user to value of variables, if any, and calculates the value of the expression)
    5. Exit (ends the program)

    Example test case:
        Expression '(((x1+5.12)*(x2-7.68))/x3)'
        Preorder Output: / * + x1 5.12 - x2 7.68 x3 
        Inorder Output: ((((x1)+(5.12))*((x2)-(7.68)))/(x3))
        Postorder Output: x1 5.12 + x2 7.68 - * x3 /

q2:
    Reads 200 2-digit integers from a text file “f.dat” and stores the integers in an array of 20 rows and 10 columns.
    The program treats each row of the array as an object, with the sum of the first three integers being the key, and 
    the other seven integers being the information content. The program then creates a MAX-HEAP with a node containing 
    an object. An array representation of the heap is used, and the parental node downheap algorithm in the array 
    representation in applied. The program finally displays the heap as a 20 ×10 array, a row for an object.

    Example test case:
        f.dat:
        25 00 54 25 19 25 81 21 02 78
        19 09 89 77 80 75 91 34 61 24
        36 42 65 18 81 93 72 34 59 37
        10 56 17 24 47 02 35 45 19 51
        26 28 10 23 03 32 65 61 28 95
        66 63 94 42 77 64 56 80 63 14
        77 07 34 93 04 19 10 44 76 19
        86 18 40 47 13 94 98 22 79 94
        68 37 41 12 06 85 51 85 60 56
        03 98 29 05 60 15 98 86 04 61
        77 51 28 24 77 02 36 64 32 05
        30 73 12 75 14 85 72 60 91 42
        83 46 03 67 90 48 04 74 41 52
        62 30 46 71 41 38 80 60 99 05
        19 48 83 98 11 30 41 72 09 31
        31 44 21 79 68 97 32 13 62 80
        61 69 82 25 62 12 83 35 56 19
        62 74 67 19 41 35 38 16 09 80
        47 44 85 30 84 53 28 42 07 65
        99 30 00 91 26 09 91 70 21 14
        
        Sample output
        66 63 94 42 77 64 56 80 63 14
        61 69 82 25 62 12 83 35 56 19
        19 48 83 98 11 30 41 72 09 31
        62 74 67 19 41 35 38 16 09 80
        77 51 28 24 77 02 36 64 32 05
        36 42 65 18 81 93 72 34 59 37
        62 30 46 71 41 38 80 60 99 05
        86 18 40 47 13 94 98 22 79 94
        47 44 85 30 84 53 28 42 07 65
        03 98 29 05 60 15 98 86 04 61
        26 28 10 23 03 32 65 61 28 95
        30 73 12 75 14 85 72 60 91 42
        83 46 03 67 90 48 04 74 41 52
        25 00 54 25 19 25 81 21 02 78
        77 07 34 93 04 19 10 44 76 19
        31 44 21 79 68 97 32 13 62 80
        10 56 17 24 47 02 35 45 19 51
        68 37 41 12 06 85 51 85 60 56
        19 09 89 77 80 75 91 34 61 24
        99 30 00 91 26 09 91 70 21 14

## Resources 
- CIS2520 courselink slides
- CIS2520 lab content

## Implementation
The assignment is complete.
