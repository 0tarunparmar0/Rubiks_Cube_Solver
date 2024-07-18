#include "RubiksCube.h"
#include "RubiksCube.cpp"

class RubiksCube3dArray : public RubiksCube
{
private:
    // Rotates a face of the cube clockwise
    void rotateFace(int ind)
    {

        //  Transpose...
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i < j)
                    swap(cube[ind][i][j], cube[ind][j][i]);
            }
        }

        // Reverse the Rows
        for (int i = 0; i < 3; i++)
        {
            swap(cube[ind][i][0], cube[ind][i][2]);
        }
    }

public:
    char cube[6][3][3]{};

    // Constructor to initialize the cube with solved state colors
    RubiksCube3dArray()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
            }
        }
    }

    // Returns the color of a specific face, row, and column
    COLOR getColor(FACE face, unsigned row, unsigned col) const override
    {
        char color = cube[int(face)][row][col];
        switch (color)
        {
        case 'B':
            return COLOR::BLUE;
        case 'R':
            return COLOR::RED;
        case 'G':
            return COLOR::GREEN;
        case 'O':
            return COLOR::ORANGE;
        case 'Y':
            return COLOR::YELLOW;
        default:
            return COLOR::WHITE;
        }
    }

    // Checks if the cube is solved
    bool isSolved() const override
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i)))
                        continue;
                    return false;
                }
            }
        }
        return true;
    }

    // Rotates the top face of the cube clockwise
    RubiksCube &u() override
    {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    // Rotates the top face of the cube counterclockwise
    RubiksCube &uPrime() override
    {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    // Rotates the top face of the cube 180 degrees
    RubiksCube &u2() override
    {
        this->u();
        this->u();

        return *this;
    }

    // Rotates the left face of the cube clockwise
    RubiksCube &l() override
    {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++)
            cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++)
            cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++)
            cube[2][i][0] = temp_arr[i];

        return *this;
    }

    // Rotates the left face of the cube counterclockwise
    RubiksCube &lPrime() override
    {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    // Rotates the left face of the cube 180 degrees
    RubiksCube &l2() override
    {
        this->l();
        this->l();

        return *this;
    }

    // Rotates the front face of the cube clockwise
    RubiksCube &f() override
    {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++)
            cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++)
            cube[3][i][0] = temp_arr[i];

        return *this;
    }

    // Rotates the front face of the cube counterclockwise
    RubiksCube &fPrime() override
    {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    // Rotates the front face of the cube 180 degrees
    RubiksCube &f2() override
    {
        this->f();
        this->f();

        return *this;
    }

    // Rotates the right face of the cube clockwise
    RubiksCube &r() override
    {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++)
            cube[4][i][0] = temp_arr[i];

        return *this;
    }

    // Rotates the right face of the cube counterclockwise
    RubiksCube &rPrime() override
    {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    // Rotates the right face of the cube 180 degrees
    RubiksCube &r2() override
    {
        this->r();
        this->r();

        return *this;
    }

    // Rotates the back face of the cube clockwise
    RubiksCube &b() override
    {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++)
            cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++)
            cube[1][i][0] = temp_arr[i];

        return *this;
    }

    // Rotates the back face of the cube counterclockwise
    RubiksCube &bPrime() override
    {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    // Rotates the back face of the cube 180 degrees
    RubiksCube &b2() override
    {
        this->b();
        this->b();

        return *this;
    }

    // Rotates the bottom face of the cube clockwise
    RubiksCube &d() override
    {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++)
            cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++)
            cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++)
            cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++)
            cube[3][2][i] = temp_arr[i];

        return *this;
    }

    // Rotates the bottom face of the cube counterclockwise
    RubiksCube &dPrime() override
    {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    // Rotates the bottom face of the cube 180 degrees
    RubiksCube &d2() override
    {
        this->d();
        this->d();

        return *this;
    }

    // Compares two RubiksCube3dArray objects for equality
    bool operator==(const RubiksCube3dArray &r1) const
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (r1.cube[i][j][k] != cube[i][j][k])
                        return false;
                }
            }
        }
        return true;
    }

    // Assigns the state of one RubiksCube3dArray object to another
    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d
{
    // Hash function for the RubiksCube3dArray
    size_t operator()(const RubiksCube3dArray &r1) const
    {
        string str = "";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};
