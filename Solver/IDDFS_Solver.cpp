#include <bits/stdc++.h>
#include "../Structures/RubiksCube.h"
// #include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

// Template parameters:
// T: Represents the Rubik's Cube (e.g., 3D array, 1D array, Bitboard)
// H: Corresponding hash function for the Rubik's Cube representation

template<typename T, typename H>
class IDDFSSolver {
private:
    int max_search_depth;  // Maximum depth for iterative deepening DFS
    vector<RubiksCube::MOVE> moves;  // Vector to store the sequence of moves

public:
    T rubiksCube;  // The Rubik's Cube instance to solve

    // Constructor to initialize the solver with a Rubik's Cube and max search depth
    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

//    Used DFSSolver with increasing max_search_depth
    vector<RubiksCube::MOVE> solve() {
        for (int i = 1; i <= max_search_depth; i++) {
            DFSSolver<T, H> dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }


};

#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H