#include "solver.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    Solver s;
    unordered_set<string> solutions = s.solveAll({1, 2, 3, 4});
    cout << "Found " << solutions.size() << " solutions:\n";
    for (auto& str : solutions)
        cout << str << '\n';
}