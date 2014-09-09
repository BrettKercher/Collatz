// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <utility>  // pair

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param r an std::istream
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
std::pair<int, int> collatz_read (std::istream& r);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// ------------
// collatz_cycle_length
// ------------

/**
 * @param i the number who's cycle length we want to calculate
 * @return the cycle length of i
 */
int collatz_cycle_length (int i);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an std::istream
 * @param w an std::ostream
 */
void collatz_solve (std::istream& r, std::ostream& w);

#endif // Collatz_h



// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout
#include <cassert>  // assert
#include <utility>  // make_pair, pair


// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}

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
	
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n = n >> 1;
			c++;
		}
		else
		{
			n = n + (n >> 1) + 1;
			c+=2; //Add 2 to cycle length, since the above is doing (3n+1)/2, ie, the next two numbers in the cycle
		}
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





