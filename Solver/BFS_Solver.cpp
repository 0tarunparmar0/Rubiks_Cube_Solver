#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// Template parameters:
// T: Represents the Rubik's Cube (e.g., 3D array, 1D array, Bitboard)
// H: Corresponding hash function for the Rubik's Cube representation

template<typename T, typename H>
class BFSSolver {
private:
    vector<RubiksCube::MOVE> moves;  // Vector to store the sequence of moves
    unordered_map<T, bool, H> visited;  // Map to keep track of visited states
    unordered_map<T, RubiksCube::MOVE, H> move_done;  // Map to track the move taken to reach each state

    // Helper function to perform Breadth-First Search (BFS) and return a solved Rubik's Cube
    T bfs() {
        queue<T> q;
        q.push(rubiksCube);  // Start BFS with the initial state of the Rubik's Cube
        visited[rubiksCube] = true;  // Mark the initial state as visited

        while (!q.empty()) {
            T node = q.front();  // Get the front element from the queue
            q.pop();
            if (node.isSolved()) {  // Check if the current state is solved
                return node;
            }
            // Iterate through all possible moves
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);  // Apply the current move
                if (!visited[node]) {  // If the state is not visited
                    visited[node] = true;  // Mark it as visited
                    move_done[node] = curr_move;  // Record the move taken to reach this state
                    q.push(node);  // Push the new state into the queue
                }
                node.invert(curr_move);  // Revert the move to explore other possibilities
            }
        }
        return rubiksCube;  // Return the initial state if no solution is found
    }

public:
    T rubiksCube;  // The Rubik's Cube instance to solve

    // Constructor to initialize the solver with a Rubik's Cube
    BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    // Function to solve the Rubik's Cube using BFS and return the sequence of moves
    vector<RubiksCube::MOVE> solve() {
        T solved_cube = bfs();  // Perform BFS to find the solved state
        assert(solved_cube.isSolved());  // Ensure the returned state is solved
        T curr_cube = solved_cube;
        // Trace back the moves from the solved state to the initial state
        while (!(curr_cube == rubiksCube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);  // Record the move
            curr_cube.invert(curr_move);  // Revert the move to trace back
        }
        rubiksCube = solved_cube;  // Update the initial state to the solved state
        reverse(moves.begin(), moves.end());  // Reverse the sequence of moves to get the correct order
        return moves;  // Return the sequence of moves to solve the cube
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H
