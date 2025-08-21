#include <iostream>
#include "solver.h"
using namespace std;

vector<Solver::Node> Solver::getCandidates(Node& a, Node& b) {
    vector<Node> ans;
    ans.push_back(Node{a.val + b.val, "(" + a.expression + " + " + b.expression + ")"});
    ans.push_back(Node{a.val - b.val, "(" + a.expression + " - " + b.expression + ")"});
    ans.push_back(Node{b.val - a.val, "(" + b.expression + " - " + a.expression + ")"});
    ans.push_back(Node{a.val * b.val, "(" + a.expression + " * " + b.expression + ")"});
    if (fabs(b.val) > EPS) ans.push_back(Node{a.val / b.val, "(" + a.expression + " / " + b.expression + ")"});
    if (fabs(a.val) > EPS) ans.push_back(Node{b.val / a.val, "(" + b.expression + " / " + a.expression + ")"});
    return ans;
}

void Solver::solve(vector<Node> nums, unordered_set<string>& solutions) {
    if (nums.size() == 1) {
        if (fabs(nums[0].val - 24.0) < EPS) {
            string ans = nums[0].expression;
            solutions.insert(ans.substr(1, ans.size() - 2));
        }
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) continue;
            vector<Node> next;
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    next.push_back(nums[k]);
                }
            }
            for (Node n : getCandidates(nums[i], nums[j])) {
                next.push_back(n);
                solve(next, solutions);
                next.pop_back();
            }
        }
    }
}

unordered_set<string> Solver::solveAll(vector<int> nums) {
    vector<Node> cleaned;
    unordered_set<string> solutions;
    for (int& i : nums) cleaned.push_back(Node{static_cast<double>(i), to_string(i)});
    solve(cleaned, solutions);
    return solutions;
}