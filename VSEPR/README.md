Written by Jeffrey Maurer, 11/20/2017 in C++ in VS 2013 using SFML.

This has the same backbone as the sphere_packing "game", but instead of solving the sphere-packing problem, it solves the n-dimensional valence shell electron pair repulsion geometry problem by gradient descent. Basically, instead of attraction, these point masses repel.

Also, unlike the sphere-packing model, this is much easier visualized. The first two dimensions are spacial, the next dimension is visualized through "perspective" to imagine another dimension. The next dimension is visuallized through brightness/alpha. The last three dimensions are visualized through control of the rgb palette.
