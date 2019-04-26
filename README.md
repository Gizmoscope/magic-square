# magic-square

A magic square is a square grid of n x n numbers that contains ever number from 1 to n² in a way that every row, column and diagonal has the same sum. I wrote this program in my first semester: It calculates the number of all magic squares of dimension 4 (which are 7040).

## The trick

Simply filling every permutation of (1, ..., n²) into a grid and check the magic square condition would need huge computation time. There are 16! = 20.922.789.888.000 permutations of (1, ..., 16). The trick is the following: Put all information we have for magic squares into a system of linear equations and look at the solution space. Lets denote the coefficients of the magic square by x_i, where i ranges from 1 to 16. We know for example that x_1 + x_2 + x_3 + x_4 = 34. There are 9 further equations like that.

The solution space is 7-dimensional which is the reason why specifying x_1, ..., x_7 already determines the whole square. There are 16!/9! = 57.657.600 possibilities to assign distinct numbers between 1 and 16 to the first 7 coefficients of the magic square. This is a number that todays (even yesterdays) processors can cope.

## Performance

My computer finds all 7040 magic squares within 3.42 seconds. But it gets better. While compiling the program one can choose between some optimization settings. These 3.42 seconds can be achieved without any optimization. The following table compares some of the optimization settings.

compile code | run time of compiled program
-------------|-----------------------------
`gcc -O0 magic_v1.c` | 3.42 seconds
`gcc -O1 magic_v1.c` | 1.41 seconds
`gcc -O2 magic_v1.c` | 1.39 seconds
`gcc -O3 magic_v1.c` | 1.24 seconds

The best optimized programs runs 276% faster than the one without optimization. I think this is quite amazing.

## The naive program

Maybe the trick produces some overhead a naive program wouldn't have. However, under the assumption that the naive program would need 9! = 362880 times longer the my program then it would need about 450.000 seconds = 125 hours which are over 5 days.

## Further improvements

With little changes one can improve the performance of the program. I made three observations.

1. The largest number the program uses in the calculation is 68. These numbers can be stored in a smaller data-type. As expected the computation is a little bit faster with `char` values instead of `int`values. (To be honest: I consider this a cheat rather than an improvement.)
2. The last three numbers in a square produced by the `check` function are always distinct and in range. There is no need to check these conditions so that the loop can be terminated earlier. (This clearly is an improvement. However, against my expectations the runtime was not considerably faster.)
3. If two numbers in a row, column or diagonal are large, then the other two need to be small. This can be used to narrow the range of numbers the `find` function tests. (This really improved the runtime noticeably.)

These changes together led to the program `magic_faster.c`. Thinking about the third point I managed to reorganize the way the squares are built to add a futher narrowing of one of the ranges. Actually, the corresponding program `magic_fastest.c` is again faster then the prior versions. Following this improvement I found another fact to make use of:

4. Given a magic square there is another (different) magic square where every `k` is replaced by `17-k`. An easy calculation shows that all sums are indeed still the same. Therefore, the number of all magic squares is twice the number of those magic squares having 1,2, ..., 8 as first entry.

The last fact is used in `magic_v5.c`. The last (maybe obvious) improvement is to use multi-threading which is implemented in `magic_v5_threads.c`. Here is a comparison of the run times.

` `       | `magic_v1.c` | `magic_v2.c` | `magic_v3.c` | `magic_v4.c` | `magic_v5_threads.c` | `magic_v6_threads.c`
----------|--------------|--------------|--------------|--------------|----------------------|---------------------
`gcc -O0` | 3.42 seconds | 1.31 seconds | 1.03 seconds | 0.52 seconds | 0.086 seconds | 0.036 seconds
`gcc -O1` | 1.41 seconds | 0.60 seconds | 0.46 seconds | 0.23 seconds | 0.040 seconds | 0.024 seconds
`gcc -O2` | 1.39 seconds | 0.56 seconds | 0.45 seconds | 0.23 seconds | 0.042 seconds | 0.023 seconds
`gcc -O3` | 1.24 seconds | 0.47 seconds | 0.41 seconds | 0.20 seconds | 0.038 seconds | 0.022 seconds
