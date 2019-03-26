# magic-square

A magic square is a square grid of n x n numbers that contains ever number from 1 to n² in a way that every row, column and diagonal has the same sum. I wrote this program in my first semester: It calculates the number of all magic squares of dimension 4 (which are 7040).

## The trick

Simply filling every permutation of (1, ..., n²) into a grid and check the magic square condition would need huge computation time. There are 16! = 20.922.789.888.000 permutations of (1, ..., 16). The trick is the following: Put all information we have for magic squares into a system of linear equations and look at the solution space. Lets denote the coefficients of the magic square by v_i, where i ranges from 1 to 16. We know for example that v_1 + v_2 + v_3 + v_4 = 34. There are 9 further equations like that. The coefficient matrix for the resulting system of linear equation is

1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 | 34
0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 | 34
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 | 34
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 | 34
1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 | 34
0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 | 34
0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 | 34
0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 | 34
1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 | 34
0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 | 34
