//Author: Will Nguyen
//Date: 21/03/2025

#include "bdc.h"
#include "biggest-divisible-conglomerate.cpp"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>

int main() {
	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);

	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!
	// Test 3: Single Element
	values = {42};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {42};
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln);

	// Test 4: No Divisible Elements (Prime Numbers)
	values = {3, 5, 7, 11, 13};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans.size() == 1); // Since no elements are divisible by each other, only one should be chosen.

	// Test 5: Already Sorted Input
	values = {1, 2, 4, 8, 16, 32};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {32, 16, 8, 4, 2, 1};
	set<int> answerSet5(ans.begin(), ans.end());
	assert( answerSet5 == soln);

	// Test 6: Empty List
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {};
	set<int> answerSet6(ans.begin(), ans.end());
	assert( answerSet6 == soln);

	// Test 7: Random List I made
	values = {3, 5, 15, 20, 21, 30};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet7(ans.begin(), ans.end());
	soln = {5, 15, 30};
	first = (answerSet7 == soln);
	soln = {3, 15, 30};
	second = (answerSet7 == soln);
	assert( first || second);

	// Test 8: List of two non-divisible elements
	values = {7, 3};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet8(ans.begin(), ans.end());
	soln = {7};
	first = (answerSet8 == soln);
	soln = {3};
	second = (answerSet8 == soln);
	assert(first || second);

	// Test 9: List of more than two non-divisible elements
	values = {7, 11, 17, 3, 2};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet9(ans.begin(), ans.end());
	soln = {17};
	first = (answerSet9 == soln);
	soln = {2};
	second = (answerSet9 == soln);
	assert(first || second);

	// Test 10: Powers of 3
	values = {3, 9, 27, 81, 243, 729, 2187};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {2187, 729, 243, 81, 27, 9, 3};
	assert(set<int>(ans.begin(), ans.end()) == soln);

	// Test 11: Very Large Numbers
	values = {1000000000, 500000000, 250000000, 125000000, 62500000};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {1000000000, 500000000, 250000000, 125000000, 62500000};
	assert(set<int>(ans.begin(), ans.end()) == soln);

	cout << "ALL TESTS PASSED" << endl;
	return 0;
}
