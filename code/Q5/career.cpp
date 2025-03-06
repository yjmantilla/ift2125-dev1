// CE FICHIER NE SERT QU'A APPELER ET TESTER VOTRE CODE. 
// VOUS NE DEVRIEZ PAS AVOIR BESOIN DE LE MODIFIER, SAUF POUR 
// AJOUTER VOUS-MÊME D'AUTRES TESTS SI VOUS LE VOULEZ.
// NE PAS REMETTRE SUR STUDIUM.

// THIS FILE IS ONLY USED TO CALL AND TEST YOUR CODE.
// YOU SHOULD NOT HAVE TO MODIFY IT, EXCEPT FOR ADDING 
// NEW CUSTOM TESTS IF YOU WISH TO DO SO.
// DO NOT SUBMIT ON STUDIUM.


#include <iostream> // pour l'affichage dans la console // for display in console
#include "CareerCalculator.h" // pour la classe principale de l'exercice // for the main class of the exercise
#include <vector> // pour utiliser les vecteurs de la librairie standard // to use vectors from the standard library
#include <cstdlib> // pour convertir le input en int // to convert input to int
#include <cassert>

using namespace std;

bool TestCareerCalculator();

int main(int argc, char *argv[])
{
    std::cout << "Calculateur d'étapes de carrière / Career Calculator" << std::endl;

    vector<int> Steps = {2, 1, 5, 2, 3, 2};

    CareerCalculator Calculator = CareerCalculator();
    bool Feasible = Calculator.CalculateMaxCareer(Steps);

    std::cout << "Est-ce que l'objectif est réalisable? " << Feasible << std::endl;

    // tests
    if (TestCareerCalculator()){
        std::cout << "Tests reussis / Tests passed !" << std::endl;
    } else {
        std::cout << "Tests echoues / Failed tests :(" << std::endl;
    }

}

bool TestCareerCalculator(){
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4, 3},   // Sortie attendue/Expected Output: true
        {4, 3, 2, 1, 0, 1},   // Sortie attendue/Expected Output: false
        {1, 1, 1, 0, 1, 1}, // Sortie attendue/Expected Output: false
    };

    vector<bool> expectedResults = {true, false, false};

    CareerCalculator Calculator = CareerCalculator();

    for (size_t i = 0; i < testCases.size(); i++) {
        const auto& steps = testCases[i];
        bool result = Calculator.CalculateMaxCareer(steps);
        cout << "Test " << i + 1 << ": Expected = " << expectedResults[i] << ", Got = " << result << " --> ";
        if (result == expectedResults[i]) {
            cout << "PASSED" << endl;
        }else{
            assert(result == expectedResults[i]);  // Assertion to verify the correctness
            return false;
        }
    }
    return true;
}
