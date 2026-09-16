# trace()

## What it does
The trace of a square matrix is the sum of the numbers on the main diagonal, going from top-left to bottom-right. For a 3x3 matrix that means adding data[0][0] + data[1][1] + data[2][2].

## OOP Concepts Used
I made a Matrix class. The numbers are stored in a private variable called data, so other code cannot change it directly. It has to use setValue() and getValue() instead. This is called encapsulation.

The constructor Matrix(int rows, int cols) makes a new matrix full of zeros in whatever size you ask for.

trace(), print() and getValue() are marked const because they only look at the matrix, they do not change it.

If the matrix is not square, trace() throws an error instead of just printing something. The main() function uses try and catch to handle that error safely.

## Algorithm
First check if rows and cols are equal. If they are not, throw an error, because trace only works on square matrices.

Set a variable called sum to 0.

Go through each row i, and add data[i][i] to sum each time. That is the diagonal.

Return sum at the end.

This only needs one loop through n numbers, so it is fast.

## Possible Error Points
Trace does not work on a matrix that is not square, like one with 2 rows and 4 columns. That is why we check rows != cols first.

If the matrix has 0 rows and 0 columns, the loop just does nothing and returns 0.

If main() did not use try and catch, an error would stop the whole program instead of showing a message.

If you build the matrix with the wrong size by mistake, the square check will fail even if you meant to make it square.
