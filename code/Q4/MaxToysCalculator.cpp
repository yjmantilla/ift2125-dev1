#include "MaxToysCalculator.h"
#include <vector>
#include <math.h>
#include <iostream>

// ce fichier contient les definitions des methodes de la classe MaxToysCalculator
// this file contains the definitions of the methods of the MaxToysCalculator class

using namespace std;

MaxToysCalculator::MaxToysCalculator()
{
}

int MaxToysCalculator::CalculateMaxToys(const vector<int>& Toys, int S) {

   // Student: Yorguin José Mantilla Ramos - 20253616
   // Sliding Window Approach to find the longest contiguous segment
   // The idea will be to start with a window of size 0 and expand it toy by toy
   // If the sum of the toys in the window exceeds the budget, we shrink the window from the left
   // Moreover because they are required to be contiguous, 
   // I think this greedy approach actually returns the global optimum.
   // But im not completely sure... 

   int left = 0;         // Left boundary of the window (start of toy segment)
   int current_sum = 0;  // Sum of toy prices in the window
   int max_toys = 0;     // The best (largest) segment we've found so far

   // Right pointer expands the window toy by toy
   for (int right = 0; right < Toys.size(); right++) {
       current_sum += Toys[right];  // Include the new toy in our segment

       // If we've exceeded the budget, shrink the window from the left
       while (current_sum > S) {
           current_sum -= Toys[left]; // Remove the toy at the left boundary
           left++;  // Move the left pointer to shrink the window
       }

       // Update the max length of a valid contiguous segment
       max_toys = max(max_toys, right - left + 1);
   }

   return max_toys;
}
