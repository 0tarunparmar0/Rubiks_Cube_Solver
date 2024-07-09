// Created by Shubham Patil on 17/12/21.
//

#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

/**
 * This class serves as a foundational framework for various models of the Rubik's Cube.
 * Each model can differ in representation and operational efficiency, which this class
 * aims to explore and optimize through benchmarking.
 */

class RubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    /*
     * Retrieves the color of a specific cell on a given Rubik's Cube face.
     * Rows and columns are 0-indexed, arranged top to bottom and left to right when facing the cube.
     * @param face: The face of the Rubik's Cube (UP, LEFT, FRONT, RIGHT, BACK, DOWN)
     * @param row: Row index of the cell
     * @param col: Column index of the cell
     * @return The color of the specified cell
     */
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    /*
     * Returns the first letter of the given COLOR enum.
     * Eg: For COLOR::GREEN, returns 'G'
     */
    static char getColorLetter(COLOR color);

    /*
     * Checks if the Rubik's Cube is in a solved state.
     * @return true if solved, false otherwise
     */
    virtual bool isSolved() const = 0;

    /*
     * Converts a MOVE enum into its corresponding string representation.
     * @param ind: The MOVE enum value
     * @return The string representation of the move
     */
    static string getMove(MOVE ind);

    /*
     * Prints a planar representation of the Rubik's Cube.
     * Visualizes the cube with labeled sides and color distribution.
     */
    void print() const;

    /*
     * Randomly shuffles the cube by performing 'times' random moves.
     * @param times: Number of random moves to perform
     * @return List of moves performed during the shuffle
     */
    vector<MOVE> randomShuffleCube(unsigned int times);

    /*
     * Performs a specific move on the Rubik's Cube.
     * @param ind: The move to perform
     * @return Reference to the modified Rubik's Cube
     */
    RubiksCube &move(MOVE ind);

    /*
     * Inverts a specific move on the Rubik's Cube.
     * @param ind: The move to invert
     * @return Reference to the modified Rubik's Cube
     */
    RubiksCube &invert(MOVE ind);

    /*
     * Rotates the Rubik's Cube faces according to standard notation.
     * Includes single turns (F, U, L, D, R, B), primes (F', U', L', D', R', B'),
     * and double turns (F2, U2, L2, D2, R2, B2).
     */

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    /*
     * Retrieves a string representing the colors of the cube's corners.
     * @param ind: Index of the corner
     * @return String representation of the corner's colors
     */
    string getCornerColorString(uint8_t ind) const;

    /*
     * Retrieves the index of a corner in the cube's structure.
     * @param ind: Index of the corner
     * @return Index of the corner in the cube
     */
    uint8_t getCornerIndex(uint8_t ind) const;

    /*
     * Retrieves the orientation of a corner in the cube.
     * @param ind: Index of the corner
     * @return Orientation of the corner
     */
    uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
