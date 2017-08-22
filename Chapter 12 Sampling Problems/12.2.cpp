/* 
 * Programming Pearls Chapter 12 Sampling Problems
 * Problem:How to generate m random integers (not repetitive) within 0 ~ n-1
 * Requirements: Output in sequence, and ensure that each subset is selected for the same probability.
 *
 * Optimization:
 * Given a set of S, insert one element at a time. 
 * Before inserting, check that the number of S has reached m and the random number is not in m.
 */

#include <iostream>
#include <time.h>
#include <set>
using namespace std;

void getSet(int m, int n)//seclet m subsets in 0~n-1.
{
	srand(time(NULL));//Very important
	set<int> S;
	while (S.size() < m)//untill fill up
		S.insert(rand() % n);
	set<int>::iterator i;
	for (i = S.begin(); i != S.end(); ++i)
		cout << *i << " ";
}

int main()
{
	getSet(5, 10);
	return 0;
}
