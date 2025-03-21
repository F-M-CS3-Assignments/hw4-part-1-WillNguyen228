//Author: Will Nguyen
//Date: 03/21/2025

#include "bdc.h" //including necessary functions from the header file
#include <iostream>  // Add this line for debugging
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Function to convert a vector of integers into a string 
string vec_to_string(vector<int> v) {
    string result = "["; //declare a beginning of the vector
    for (size_t i = 0; i < v.size(); i++) {
        result += to_string(v[i]); //adding each component to the string
        if (i < v.size() - 1) {
            result += ", "; //-1 to not go over the index range 0 -> end
        }
    }
    result += "]";
    return result;
}

// Helper funciton to find the position of the next number divisible by input[i]
int find_next_dividend_position(const std::vector<int>& input, size_t index) { //Made index size_t so that it matches the unsigned value input.size() return
    if (index >= input.size()) {
        return -1; //No more elements to check
    }
    int divisor = input[index - 1];

    for (size_t i = index; i < input.size(); i++) {
        // As soon as we find a number divisible by 'divisor', return its index
        // Debugging line to check elements
        // cout << input[i] << " % " << divisor << " = " << input[i] % divisor << endl;
        if (input[i] % divisor == 0) {
            // cout << "Add " << input[i] << endl;
            return i;
        }
    }
    return input.size(); // No divisible number found;
}

//This is a helper function that helps finds the longest vector in a list of vectors
vector<int> find_longest_vector(const std::vector<std::vector<int>>& candidates) {
    vector<int> longest; //Create a placeholder for the longest vector
    for (const auto& vec : candidates) {
        if (vec.size() > longest.size()) { //iterates through 
            longest = vec; //if the code sees a longer vector, it puts it in the place holder
        }
    }
    return longest;
}

//Function to get a sub vector from the given index to the end of the vector
vector<int> sub_vec(const vector<int>& input, size_t start_index) {
    return vector<int>(input.begin() + start_index, input.end());
}

//Recursive helper function to find the largest disible conglomerate
vector<int> bdc_helper(const vector<int>& input) {
    if (input.size() <= 1) return input; //Base case: Empty list and lists of one element

    vector<vector<int>> candidates; //Initializing a vector of vector for each integer element 
    
    for (size_t i = 0; i < input.size() - 1; i++) {
        vector<int> L = {input[i]}; //making a small vector with input[i] from the left of the vector as the only item

        //From the position i+1, find the position of next number in the input vector which
        //is divisible by input[i]
        int j = find_next_dividend_position(input, i + 1);
        if (j == -1) {
            vector<int> empty_vector;
            bdc_helper(empty_vector);
        }

        vector<int> Rin = sub_vec(input, j); //subvec is a funciton that make a sub vector from index j to the end
        // cout << vec_to_string(Rin) << endl; //Debugging lind to check the right side before the recursion
        vector<int> R = bdc_helper(Rin);  //call the recursive function with a subproblem (a smaller input vector)

        //Checks if the elements in R are divisble by input[i], return empty list if not
        for (int element : R) {
            if (element % input[i] == 0) { 
                //combine input[i] with all the numbers which are divisible by input[i] and
                //form a 
                // cout << "Combine " << vec_to_string(L) << " and " << vec_to_string(R) << endl;
                L.insert(L.end(), R.begin(), R.end());
                break;
            }
            else {
                vector<int> emptyList;
                L.insert(L.end(), emptyList.begin(), emptyList.end());
                break;
            }
        }
        candidates.push_back(L); //adding the candidate conglomerate to the list
    }

    //Debugging line ot check for finished candidates
    // for (vector<int> cand : candidates) {
    //     cout << vec_to_string(cand) << endl;
    // }

    //return the longest conglomerate in the candidates
    return find_longest_vector(candidates); //find_longest_vector is a function that picks the longest vector out
}

//This is the main function that sorts the input and calls the recursive function
vector<int> biggest_divisible_conglomerate(vector<int> input) {

    //We are sorting the integers in the input so that smaller numbers 
    //appear first and can be checked for divisibility with higher numbers in the list
    sort(input.begin(), input.end());

    return bdc_helper(input);
}