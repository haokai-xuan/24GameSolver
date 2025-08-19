#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solver {
    const double EPS = 1e-6;
    struct Node
    {
        double val;
        string expression;
    };
    vector<Node> getCandidates(Node& a, Node& b);
    void solve(vector<Node> nums, unordered_set<string>& solutions);
    
public:
    unordered_set<string> solveAll(vector<int> nums);
};

#endif