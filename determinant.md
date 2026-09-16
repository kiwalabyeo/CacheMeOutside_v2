# determinant()

## What it does
The determinant is one number worked out from a square matrix. It tells you things like whether the matrix can be reversed (inverted). This program works it out using a method called cofactor expansion, going along the first row.

## OOP Concepts Used
The Matrix class keeps size and data private, so other code has to use its methods to see them.

The constructor Matrix(int size) makes it easy to build a new square matrix. This is needed a lot here, because minor() makes a smaller Matrix every time it runs.

determinant() calls itself again and again on smaller matrices, made by minor(), until it reaches a matrix of size 1 or size 2. A function calling itself like this is called recursion.

minor() is a helper function with one simple job: build the smaller matrix left over after removing one row and one column.

## Algorithm
If the matrix is size 1, just one number, the determinant is that number.

If the matrix is size 2, like [[a,b],[c,d]], the determinant is a*d minus b*c.

If the matrix is bigger, go through each column j in the first row. Build the smaller matrix left after removing row 0 and column j. Multiply data[0][j] by the determinant of that smaller matrix, worked out using the same steps again. Add or take away this value, and keep switching between adding and taking away as j increases.

Add all of these together to get the final determinant.

This way of doing it is easy to follow and matches how it's taught in maths class, but it gets slow on bigger matrices since it keeps making smaller matrices over and over. For small matrices in this assignment it works fine.

## Possible Error Points
This Matrix class always makes a square matrix, since the constructor only takes one size number. It cannot even hold a matrix that is not square.

Because of how the recursion works, a big matrix, like 10 by 10 or more, would take a long time to run. This method only really works well for small matrices.

It is easy to forget to switch the plus and minus sign at each step. This would give a wrong answer without the program crashing, so it is a hard mistake to notice.

Getting the size 1 or size 2 case wrong, or mixing up the order in a*d minus b*c, would break every bigger matrix too, since everything depends on those two cases being correct.
