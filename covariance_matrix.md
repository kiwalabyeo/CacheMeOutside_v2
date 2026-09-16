# covariance_matrix()

## What it does
Imagine a table where each row is one observation and each column is one thing being measured, like height and weight. The covariance matrix shows how each pair of columns changes together. The diagonal values show how much one column changes on its own. The other values show if two columns tend to go up together, go in opposite directions, or are not really connected.

## OOP Concepts Used
I called this class Dataset instead of Matrix, because it stands for rows of observations and columns of things being measured, even though it stores the numbers the same way, in a private variable called data.

The constructor Dataset(int rows, int cols) sets up an empty table of the right size.

Instead of writing one big function, I made a small helper called columnMean() that just finds the average of one column. covariance_matrix() calls this helper for every column. This makes the code easier to read.

covariance_matrix() does not change the Dataset at all. It only reads the numbers and gives back a new table of results.

## Algorithm
Work out the average of every column using columnMean().

Make an empty result table with one row and one column for each variable.

For every pair of columns, go through every row and add up (value in column a minus its average) times (value in column b minus its average). Then divide this total by the number of rows minus 1.

Put that number into the result table.

Give back the finished result table.

Since we compare every column with every other column, this takes a bit more time when there are many columns.

## Possible Error Points
Dividing by rows minus 1 would divide by zero if there is only 1 row of data. The code does not check for this, so you need at least 2 rows for it to work properly.

If you build the table sideways by mistake, with variables as rows instead of columns, the answer would be the wrong size and would not mean what you expect.

This code divides by rows minus 1. Some other tools divide by rows instead, giving a slightly different answer. It is worth checking which one is expected if comparing with another program.

Since we use decimal numbers, very small results close to 0 might show up as tiny numbers like 0.0000001 instead of exactly 0. This is just normal rounding, not a bug.
