#ifndef BDC_H
#define BDC_H

#include <vector>
#include <string>

using namespace std;

// Although pass by reference would probably be more efficient
// for one or both of these methods, it is not a substantial difference
// since the vectors used in this program are not very large.
string vec_to_string(vector<int> v);
int find_next_dividend_position(const vector<int>& input, size_t index);
vector<int> sub_vec(const vector<int>& input, size_t start_index);
vector<int> find_longest_vector(const vector<vector<int>>& candidates);
vector<int> biggest_divisible_conglomerate(vector<int> input);

#endif 