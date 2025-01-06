Name : Elise Pitre

## Overview
q1:
    Converts a fully parenthesized arithmetic expression with binary operators (+, −, *, /) into a binary expression tree from a command-line input.

    Input: A single-character string with floating numbers (Y.YY format) and variables (x1, x2, ...).

    The menu offers the user the following options:
    1. Preorder
    2. Inorder
    3. Postorder
    4. Calculate
    5. Exit

    Example test case:
        Expression '(((x1+5.12)*(x2-7.68))/x3)'
        Preorder Output: / * + x1 5.12 - x2 7.68 x3 
        Inorder Output: ((((x1)+(5.12))*((x2)-(7.68)))/(x3))
        Postorder Output: x1 5.12 + x2 7.68 - * x3 /

q2:
    Reads 200 two-digit integers from f.dat, stores them in a 20x10 array, and treats each row as an object.

    Process:
    First 3 integers: Key
    Remaining 7: Information
    Creates a max-heap (array-based) using downheap algorithm.
    Output: Heap displayed as a 20x10 array.

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
