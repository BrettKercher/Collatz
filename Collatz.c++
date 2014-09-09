// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#include "Collatz.h"

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i;
    r >> i;
    if (!r)
        return std::make_pair(0, 0);
    int j;
    r >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    int c, min, max;
    int max_c = 0;
    
    max = i < j ? j : i;
    min = i < j ? i : j;
    
    assert(max < 1000000);
    assert(min > 0);
  
    for(; min <= max; min++)
    {
		c = collatz_cycle_length(min);
		
		assert(c > 0);
		
		if(c > max_c)
			max_c = c;
	}
    
    assert(max_c > 0);
    
    return max_c;
}

// ------------
// collatz_cycle_length
// ------------

int collatz_cycle_length (int i) {
	
	int c = 1;
	
	while(i != 1)
	{
		if(i % 2 == 0)
			i = i / 2;
		else
			i = 3 * i + 1;
		c++;
	}
	
	return c;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int i = p.first;
        const int j = p.second;
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
