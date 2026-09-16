# matrix_multiply()

## What it does
This multiplies two matrices together using the normal rule from maths class. If matrix A has size n by m, and matrix B has size m by p, the answer is a new matrix with size n by p.

## OOP Concepts Used
The Matrix class keeps rows, cols and the numbers (data) private. Other code has to use methods like getValue() and setValue() to reach them.

The constructor makes an empty matrix full of zeros, so matrix_multiply() can quickly build a new result matrix before filling it in.

matrix_multiply(const Matrix &other) takes another Matrix as input. Since other is also a Matrix, the code is allowed to look at other.data directly. In C++, an object can see the private parts of another object from the same class.

The function builds a brand new Matrix called result and gives it back at the end, instead of changing the original matrices.

## Algorithm
Check that the number of columns in A matches the number of rows in B. If they do not match, multiplying is not possible, so throw an error.

Make a new empty Matrix called result, with A's number of rows and B's number of columns.

Go through every row i of A and every column j of B.

For each pair, go through k, and add A[i][k] times B[k][j] into a running total called sum.

Put sum into result[i][j].

After all the loops are done, return result.

This uses three loops inside each other, so it takes longer on bigger matrices, but that is fine for this assignment.

## Possible Error Points
If A's columns do not match B's rows, the multiplication cannot be done. The code checks this first and throws an error.

Multiplying A by B is not the same as multiplying B by A. The order matters, and switching it can give a very different answer.

It is easy to make small mistakes in the loop limits, like using rows instead of rows - 1. Using i < rows the right way avoids going out of bounds.

Multiplying very large matrices can be slow, since the amount of work grows quickly as the matrices get bigger.
