# magic-square

A magic square is a square grid of n x n numbers that contains ever number from 1 to n² in a way that every row, column and diagonal has the same sum. I wrote this program in my first semester: It calculates the number of all magic squares of dimension 4 (which are 7040).

## The trick

Simply filling every permutation of (1, ..., n²) into a grid and check the magic square condition would need huge computation time. There are 16! = 20.922.789.888.000 permutations of (1, ..., 16). The trick is the following: Put all information we have for magic squares into a system of linear equations and look at the solution space. Lets denote the coefficients of the magic square by x_i, where i ranges from 1 to 16. We know for example that x_1 + x_2 + x_3 + x_4 = 34. There are 9 further equations like that.

The solution space is 7-dimensional which is the reason why specifying x_1, ..., x_7 already determines the whole square. There are 16!/9! = 57.657.600 possibilities to assign distinct numbers between 1 and 16 to the first 7 coefficients of the magic square. This is a number that todays (even yesterdays) processors can cope.

## Performance

My computer finds all 7040 magic squares within 3.42 seconds. But it gets better. While compiling the program one can choose between some optimization settings. These 3.42 seconds can be achieved without any optimization. The following table compares some of the optimization settings.

compile code | run time of compiled program
-------------|-----------------------------
`gcc -O0 magic.c` | 3.42 seconds
`gcc -O1 magic.c` | 1.41 seconds
`gcc -O2 magic.c` | 1.39 seconds
`gcc -O3 magic.c` | 1.24 seconds

The best optimized programs runs 276% faster than the one without optimization. I think this is quite amazing.
