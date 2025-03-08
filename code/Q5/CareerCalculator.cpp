#include "CareerCalculator.h"
#include <vector>
#include <math.h>
#include <iostream>

// ce fichier contient les definitions des methodes de la classe CareerCalculator
// this file contains the definitions of the methods of the CareerCalculator class

using namespace std;

CareerCalculator::CareerCalculator()
{
}

bool CareerCalculator::CalculateMaxCareer(const vector<int>& Steps) {

    // Student: Yorguin José Mantilla Ramos - 20253616
    // Greedy approach to check if the last stage of the career can be reached
    int end_stage = Steps.size();  // Total number of career stages (squares)
    int max_reachable_square = 0;  // Maximum square that can be reached so far

    for (int square = 0; square < end_stage; square++) {
        if (square > max_reachable_square) {
            return false; // If we reached an unreachable square, return false
        }
        // Update the maximum reachable square from the current position
        max_reachable_square = max(max_reachable_square, square + Steps[square]); 

        // If we can reach or surpass the last square, return true
        if (max_reachable_square >= end_stage - 1) {
            return true;
        }
    }
    
    return false; // If loop completes without reaching the last square, return false


    return false;
}
