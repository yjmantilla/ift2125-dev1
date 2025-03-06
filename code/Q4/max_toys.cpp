// CE FICHIER NE SERT QU'A APPELER ET TESTER VOTRE CODE. 
// VOUS NE DEVRIEZ PAS AVOIR BESOIN DE LE MODIFIER, SAUF POUR 
// AJOUTER VOUS-MÊME D'AUTRES TESTS SI VOUS LE VOULEZ.
// NE PAS REMETTRE SUR STUDIUM.

// THIS FILE IS ONLY USED TO CALL AND TEST YOUR CODE.
// YOU SHOULD NOT HAVE TO MODIFY IT, EXCEPT FOR ADDING 
// NEW CUSTOM TESTS IF YOU WISH TO DO SO.
// DO NOT SUBMIT ON STUDIUM.

#include <iostream> // pour l'affichage dans la console // for display in console
#include "MaxToysCalculator.h" // pour la classe principale de l'exercice // for the main class of the exercise
#include <vector> // pour utiliser les vecteurs de la librairie standard // to use vectors from the standard library
#include <cstdlib> // pour convertir le input en int // to convert input to int
#include <cassert>

// commandes / command (PowerShell) :
// g++ -o max_toys.exe max_toys.cpp MaxToysCalculator.cpp
// .\max_toys.exe

// for VS Code, make sure to compile all the files of the project
// you might want to change "${file}", by "${fileDirname}\\**.cpp" in the tasks.json of .vscode -> taks -> args
// pour VS Code, veillez à compiler tous les fichiers du projet
// vous souhaiterez peut-être remplacer "${file}", par "${fileDirname}\\**.cpp" dans le fichier task.json de .vscode -> taks -> args

using namespace std;

bool TestMaxToysCalculator();

int main(int argc, char *argv[])
{
    std::cout << "Calculateur de maximum jouets / Max toys Calculator" << std::endl;

    vector<int> Toys = {2, 1, 5, 2, 3, 2};
    int S = 7;

    MaxToysCalculator Calculator = MaxToysCalculator();
    int MaxToys = Calculator.CalculateMaxToys(Toys, S);

    std::cout << "Le maximum de jouets consécutifs qu'il est possible d'acheter est / The maximum of consecutive toys that it's possible to buy : ";
    std::cout << MaxToys << std::endl;

    // tests
    if (TestMaxToysCalculator()){
        std::cout << "Tests reussis / Tests passed !" << std::endl;
    } else {
        std::cout << "Tests echoues / Failed tests :(" << std::endl;
    }

}

bool TestMaxToysCalculator(){
    vector<pair<vector<int>, int>> testCases = {
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 4},   // Sortie attendue/Expected Output: 4 (segment {1,1,1,1})
        {{1, 2, 3, 4, 5}, 7},   // Sortie attendue/Expected Output: 3 (segment {1,2,3})
        {{2, 1, 5, 2, 3, 2}, 7}, // Sortie attendue/Expected Output: 3 (segment {2,3,2})
        {{3, 1, 2, 1, 1}, 4},    // Sortie attendue/Expected Output: 3 (segment {1,2,1} ou {2,1,1})
        {{10, 20, 30}, 5},       // Sortie attendue/Expected Output: 0 (aucun segment)
        {{5, 1, 2, 7, 3}, 8},    // Sortie attendue/Expected Output: 3 (segment {5, 1, 2})
    };

    vector<int> expectedResults = {4, 3, 3, 3, 0, 3};

    MaxToysCalculator Calculator = MaxToysCalculator();

    for (size_t i = 0; i < testCases.size(); i++) {
        const auto& pair = testCases[i];
        const auto& Toys = pair.first;
        const auto& S = pair.second;
        int result = Calculator.CalculateMaxToys(Toys, S);
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
