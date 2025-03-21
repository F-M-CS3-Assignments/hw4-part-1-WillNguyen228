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
int find_next_dividend_position(const std::vector<int>& input, size_t index, int divisor) { //Made index size_t so that it matches the unsigned value input.size() return
    for (; index < input.size(); index++) {
        // As soon as we find a number divisible by 'divisor', return its index
        cout << input[index] << " % " << divisor << " = " << input[index] % divisor << endl;
        if (input[index] % divisor == 0) {
            cout << "Add " << input[index] << endl;
            return index;
        }
    }
    // return -1 if no divisible number is found
    return -1;
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
vector<int> sub_vec(const vector<int>& input, int start_index) {
    return vector<int>(input.begin() + start_index, input.end());
}

vector<int> bdc_helper(const std::vector<int>& input) {
    if (input.size() <= 1) return input; //Base case: Empty list and lists of one element

    vector<std::vector<int>> candidates; //Initializing a vector of vector for each integer element 
    
    for (size_t i = 0; i < input.size(); ++i) {
        vector<int> L = {input[i]}; //making a small vector with input[i] from the left of the vector as the only item

        //From the position i+1, find the position of next number in the input vector which
        //is divisible by input[i]
        int j = find_next_dividend_position(input, i + 1, input[i]);
        vector<int> Rin = sub_vec(input, j); //subvec is a funciton that make a sub vector from index j to the end
        vector<int> R = bdc_helper(Rin);  //call the recursive function with a subproblem (a smaller input vector)

        //combine input[i] with all the numbers which are divisible by input[i] and
        //form a conglomerate
        L.insert(L.end(), R.begin(), R.end());
        candidates.push_back(L); //adding the candidate conglomerate to the list
    }

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