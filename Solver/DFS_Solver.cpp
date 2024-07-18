// Created by Lakshya Mittal on 02-01-2022.

#include <bits/stdc++.h>
#include "../Structures/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Template parameters:
// T: Represents the Rubik's Cube (e.g., 3D array, 1D array, Bitboard)
// H: Corresponding hash function for the Rubik's Cube representation

template<typename T, typename H>

class DFSSolver {
private:
    vector<RubiksCube::MOVE> moves;  // Vector to store the sequence of moves
    int max_search_depth;  // Maximum depth to search in the DFS

    // Helper function for performing Depth-First Search (DFS) to find the solution
    bool dfs(int dep) {
        

        if (rubiksCube.isSolved()) return true;

        if (dep > max_search_depth) return false;
        
        for (int i = 0; i < 18; i++) {
        
            rubiksCube.move(RubiksCube::MOVE(i));
        
            moves.push_back(RubiksCube::MOVE(i));
        
            if (dfs(dep + 1)) return true;
        
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;  // The Rubik's Cube instance to solve

    // Constructor to initialize the solver with a Rubik's Cube and optional maximum search depth
    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    // Function to solve the Rubik's Cube
    vector<RubiksCube::MOVE> solve() {
        // Start DFS from depth 1
        dfs(1);
        return moves;  // Return the sequence of moves to solve the cube
    }
};

#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H
