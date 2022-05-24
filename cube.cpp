#include <iostream>
#include <vector>
#include <Windows.h>
#include <random>
#include <fstream>

using namespace std;

enum colors_enum {
    WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    BLUE = FOREGROUND_BLUE,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    ORANGE = FOREGROUND_RED | FOREGROUND_GREEN,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
};

enum sides {
    UP = 0,
    LEFT,
    FRONT,
    RIGHT,
    BACK,
    DOWN
};

// sides[0] - up       |  0 - white
// sides[1] - left     |  1 - orange
// sides[2] - front    |  2 - green
// sides[3] - right    |  3 - red
// sides[4] - back     |  4 - blue
// sides[5] - down     |  5 - yellow


//         W W W
//         W W W
//         W W W
//
// O O O   G G G  R R R  B B B
// O O O   G G G  R R R  B B B
// O O O   G G G  R R R  B B B
//
//         Y Y Y
//         Y Y Y
//         Y Y Y

class Cube {
public:
    bool log_ = false;
    vector<vector<char>> sides;


    Cube() {
        sides.resize(6);
        for (int i = 0; i < 6; i++) {
            sides[i].resize(9);
        }
    }

    Cube(const Cube &other) {
        sides.resize(6);
        for (int i = 0; i < 6; i++) {
            sides[i].resize(9);
            for (int j = 0; j < 9; j++) {
                this->sides[i][j] = other.sides[i][j];
            }
        }
    }

    Cube &operator=(Cube const &other) {
        if (&other == this) {
            return *this;
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                this->sides[i][j] = other.sides[i][j];
            }
        }
        return *this;
    }

    void makeLogging(bool log){
        log_ = log;
    }

    void solveCube() {
        firstLayer();
        secondLayer();
        yellowCross();
        goodYellowCross();
        rightAngles();
        lastLayer();
    }

    void printCube() {
        printUpOrDown(0);
        printMiddle();
        printUpOrDown(5);
        cout << endl;
    }

    void R() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][3 * i + 2];
            sides[FRONT][3 * i + 2] = sides[DOWN][3 * i + 2];
            sides[DOWN][3 * i + 2] = sides[BACK][6 - 3 * i];
            sides[BACK][6 - 3 * i] = sides[UP][3 * i + 2];
            sides[UP][3 * i + 2] = tmp;
        }
        RotateSide(3);
        if (log_){
            cout << " R ";
        }
    }

    void r() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][3 * i + 2];
            sides[FRONT][3 * i + 2] = sides[UP][3 * i + 2];
            sides[UP][3 * i + 2] = sides[BACK][6 - 3 * i];
            sides[BACK][6 - 3 * i] = sides[DOWN][3 * i + 2];
            sides[DOWN][3 * i + 2] = tmp;
        }
        rotateSide(3);
        if (log_){
            cout << " r ";
        }
    }

    void l() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][3 * i];
            sides[FRONT][3 * i] = sides[DOWN][3 * i];
            sides[DOWN][3 * i] = sides[BACK][8 - i * 3];
            sides[BACK][8 - i * 3] = sides[UP][3 * i];
            sides[UP][3 * i] = tmp;
        }
        rotateSide(1);
        if (log_){
            cout << " l ";
        }
    }

    void L() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][3 * i];
            sides[FRONT][3 * i] = sides[UP][3 * i];
            sides[UP][3 * i] = sides[BACK][8 - i * 3];
            sides[BACK][8 - i * 3] = sides[DOWN][3 * i];
            sides[DOWN][3 * i] = tmp;
        }
        RotateSide(1);
        if (log_){
            cout << " L ";
        }
    }

    void U() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][i];
            sides[FRONT][i] = sides[RIGHT][i];
            sides[RIGHT][i] = sides[BACK][i];
            sides[BACK][i] = sides[LEFT][i];
            sides[LEFT][i] = tmp;
        }
        RotateSide(0);
        if (log_){
            cout << " U ";
        }
    }

    void u() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][i];
            sides[FRONT][i] = sides[LEFT][i];
            sides[LEFT][i] = sides[BACK][i];
            sides[BACK][i] = sides[RIGHT][i];
            sides[RIGHT][i] = tmp;
        }
        rotateSide(0);
        if (log_){
            cout << " u ";
        }
    }

    void d() {
        for (int i = 6; i < 9; i++) {
            char tmp = sides[FRONT][i];
            sides[FRONT][i] = sides[RIGHT][i];
            sides[RIGHT][i] = sides[BACK][i];
            sides[BACK][i] = sides[LEFT][i];
            sides[LEFT][i] = tmp;
        }
        rotateSide(5);
        if (log_){
            cout << " d ";
        }
    }

    void D() {
        for (int i = 6; i < 9; i++) {
            char tmp = sides[FRONT][i];
            sides[FRONT][i] = sides[LEFT][i];
            sides[LEFT][i] = sides[BACK][i];
            sides[BACK][i] = sides[RIGHT][i];
            sides[RIGHT][i] = tmp;
        }
        RotateSide(5);
        if (log_){
            cout << " D ";
        }
    }

    void F() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[UP][8 - i];
            sides[UP][8 - i] = sides[LEFT][3 * i + 2];
            sides[LEFT][i * 3 + 2] = sides[DOWN][i];
            sides[DOWN][i] = sides[RIGHT][6 - 3 * i];
            sides[RIGHT][6 - 3 * i] = tmp;
        }
        RotateSide(2);
        if (log_){
            cout << " F ";
        }
    }

    void f() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[UP][8 - i];
            sides[UP][8 - i] = sides[RIGHT][6 - i * 3];
            sides[RIGHT][6 - 3 * i] = sides[DOWN][i];
            sides[DOWN][i] = sides[LEFT][3 * i + 2];
            sides[LEFT][3 * i + 2] = tmp;
        }
        rotateSide(2);
        if (log_){
            cout << " f ";
        }
    }

    void b() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[UP][i];
            sides[UP][i] = sides[LEFT][6 - 3 * i];
            sides[LEFT][6 - 3 * i] = sides[DOWN][8 - i];
            sides[DOWN][8 - i] = sides[RIGHT][3 * i + 2];
            sides[RIGHT][3 * i + 2] = tmp;
        }
        rotateSide(4);
        if (log_){
            cout << " b ";
        }
    }

    void mHor() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][i + 3];
            sides[FRONT][i + 3] = sides[RIGHT][i + 3];
            sides[RIGHT][i + 3] = sides[BACK][i + 3];
            sides[BACK][i + 3] = sides[LEFT][i + 3];
            sides[LEFT][i + 3] = tmp;
        }

    }

    void MVert() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[FRONT][i * 3 + 1];
            sides[FRONT][i * 3 + 1] = sides[DOWN][i * 3 + 1];
            sides[DOWN][i * 3 + 1] = sides[BACK][i * 3 + 1];
            sides[BACK][i * 3 + 1] = sides[UP][i * 3 + 1];
            sides[UP][i * 3 + 1] = tmp;
        }
    }

    void B() {
        for (int i = 0; i < 3; i++) {
            char tmp = sides[UP][i];
            sides[UP][i] = sides[RIGHT][3 * i + 2];
            sides[RIGHT][3 * i + 2] = sides[DOWN][8 - i];
            sides[DOWN][8 - i] = sides[LEFT][6 - 3 * i];
            sides[LEFT][6 - 3 * i] = tmp;
        }
        RotateSide(4);
        if (log_){
            cout << " B ";
        }
    }

    void RotateSide(int side) {
        vector<char> tmp(9);
        for (int i = 0; i < 9; i++) {
            tmp[i] = sides[side][i];
        }
        sides[side][0] = tmp[6];
        sides[side][1] = tmp[3];
        sides[side][2] = tmp[0];
        sides[side][3] = tmp[7];
        sides[side][5] = tmp[1];
        sides[side][6] = tmp[8];
        sides[side][7] = tmp[5];
        sides[side][8] = tmp[2];
    }

    void rotateSide(int side) {
        vector<char> tmp(9);
        for (int i = 0; i < 9; i++) {
            tmp[i] = sides[side][i];
        }
        sides[side][0] = tmp[2];
        sides[side][1] = tmp[5];
        sides[side][2] = tmp[8];
        sides[side][3] = tmp[1];
        sides[side][5] = tmp[7];
        sides[side][6] = tmp[0];
        sides[side][7] = tmp[3];
        sides[side][8] = tmp[6];
    }

    void RotateRight() {
        vector<int> tmp(9);
        copy(sides[4].begin(), sides[4].end(), tmp.begin());
        for (int i = 4; i >= 2; i--) {
            copy(sides[i - 1].begin(), sides[i - 1].end(), sides[i].begin());
        }
        copy(tmp.begin(), tmp.end(), sides[1].begin());
        rotateSide(0);
        RotateSide(5);
        if (log_){
            cout << " → ";
        }
    }

    void RotateLeft() {
        vector<int> tmp(9);
        copy(sides[1].begin(), sides[1].end(), tmp.begin());
        for (int i = 1; i <= 3; i++) {
            copy(sides[i + 1].begin(), sides[i + 1].end(), sides[i].begin());
        }
        copy(tmp.begin(), tmp.end(), sides[4].begin());
        RotateSide(0);
        rotateSide(5);
        if (log_){
            cout << " ← ";
        }
    }

    void RotateUp() {
        rotateSide(LEFT);
        RotateSide(RIGHT);
        vector<char> tmp(9);
        for (int i = 0; i < 9; i++) {
            tmp[8 - i] = sides[0][i];
        }
        copy(sides[2].begin(), sides[2].end(), sides[0].begin());
        copy(sides[5].begin(), sides[5].end(), sides[2].begin());
        vector<char> tmp1(9);
        for (int i = 0; i < 9; i++) {
            tmp1[8 - i] = sides[4][i];
        }
        copy(tmp1.begin(), tmp1.end(), sides[5].begin());
        copy(tmp.begin(), tmp.end(), sides[4].begin());
        if (log_){
            cout << " ↑ ";
        }
    }

    void RotateDown() {
        RotateSide(LEFT);
        rotateSide(RIGHT);
        vector<char> tmp(9);
        for (int i = 0; i < 9; i++) {
            tmp[8 - i] = sides[4][i];
        }
        vector<char> tmp1(9);
        for (int i = 0; i < 9; i++) {
            tmp1[8 - i] = sides[5][i];
        }
        copy(tmp1.begin(), tmp1.end(), sides[4].begin());
        copy(sides[2].begin(), sides[2].end(), sides[5].begin());
        copy(sides[0].begin(), sides[0].end(), sides[2].begin());
        copy(tmp.begin(), tmp.end(), sides[0].begin());
        if (log_){
            cout << " ↓ ";
        }
    }


    void generateSolvedCube() {
        sides[0].assign(9, 'O');
        sides[1].assign(9, 'G');
        sides[2].assign(9, 'W');
        sides[3].assign(9, 'B');
        sides[4].assign(9, 'Y');
        sides[5].assign(9, 'R');
    }

    bool checkInv() {
        int y = 0;
        int w = 0;
        int g = 0;
        int b = 0;
        int r = 0;
        int o = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                if (sides[i][j] == 'W') {
                    w++;
                } else if (sides[i][j] == 'Y') {
                    y++;
                } else if (sides[i][j] == 'B') {
                    b++;
                } else if (sides[i][j] == 'O') {
                    o++;
                } else if (sides[i][j] == 'R') {
                    r++;
                } else if (sides[i][j] == 'G') {
                    g++;
                }
            }
        }
        return o == 9 && b == 9 && w == 9 & g == 9 & r == 9 && y == 9;
    }

    void generateCube() {
        generateSolvedCube();
        bool fl = log_;
        makeLogging(false);
        vector<char> options = {'R', 'r', 'L', 'l', 'U', 'u', 'D', 'd', 'F', 'f', 'B', 'b'};
        for (int i = 0; i < 12; i++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(0, 11);
            int ind = dist(gen);
            doOption(options[ind]);
        }
        makeLogging(fl);
    }

    void generateFlower() {
        generateSolvedCube();
        for (int i = 0; i < 4; i++) {
            MVert();
            mHor();
        }
    }

    void doOption(char option) {
        switch (option) {
            case 'R':
                R();
                break;
            case 'r':
                r();
                break;
            case 'L':
                L();
                break;
            case 'l':
                l();
                break;
            case 'U':
                U();
                break;
            case 'u':
                u();
                break;
            case 'D':
                D();
                break;
            case 'd':
                d();
                break;
            case 'B':
                B();
                break;
            case 'b':
                b();
                break;
            case 'F':
                F();
                break;
            case 'f':
                f();
                break;
            default:
                break;
        }
    }

    void rotateWholeLeft() {
        rotateSide(FRONT);
        RotateSide(BACK);
        rotateSide(UP);
        rotateSide(LEFT);
        rotateSide(RIGHT);
        rotateSide(DOWN);
        vector<int> tmp(9);
        copy(sides[5].begin(), sides[5].end(), tmp.begin());
        copy(sides[1].begin(), sides[1].end(), sides[5].begin());
        copy(sides[0].begin(), sides[0].end(), sides[1].begin());
        copy(sides[3].begin(), sides[3].end(), sides[0].begin());
        copy(tmp.begin(), tmp.end(), sides[3].begin());
        if (log_){
            cout << "";
        }
    }


    void getCross() {
        int c = 0;
        while (c != 4) {
            if (sides[FRONT][3] == 'W') {
                c++;
                rotateWholeLeft();
                continue;
            } else if (sides[UP][3] == 'W') {
                L();
            } else if (sides[UP][1] == 'W') {
                u();
                L();
                U();
            } else if (sides[UP][5] == 'W') {
                u();
                u();
                L();
                u();
                u();
            } else if (sides[UP][7] == 'W') {
                U();
                L();
            } else if (sides[RIGHT][3] == 'W') {
                R();
                F();
                U();
                f();
            } else if (sides[RIGHT][1] == 'W') {
                F();
                U();
                f();
            } else if (sides[RIGHT][5] == 'W') {
                B();
                u();
                L();
                U();
            } else if (sides[RIGHT][7] == 'W') {
                f();
                d();
                F();
            } else if (sides[DOWN][3] == 'W') {
                l();
            } else if (sides[DOWN][1] == 'W') {
                d();
                l();
            } else if (sides[DOWN][5] == 'W') {
                f();
                f();
                R();
                f();
                f();
            } else if (sides[DOWN][7] == 'W') {
                D();
                l();
                d();
            } else if (sides[LEFT][3] == 'W') {
                b();
                u();
                L();
                U();
            } else if (sides[LEFT][1] == 'W') {
                l();
                b();
                u();
                L();
                U();
            } else if (sides[LEFT][5] == 'W') {
                l();
                l();
                b();
                u();
                L();
                U();
            } else if (sides[LEFT][7] == 'W') {
                f();
                D();
                F();
            } else if (sides[BACK][3] == 'W') {
                B();
                B();
                L();
                L();
            } else if (sides[BACK][1] == 'W') {
                B();
                L();
                L();
            } else if (sides[BACK][5] == 'W') {
                L();
                L();
            } else if (sides[BACK][7] == 'W') {
                b();
                L();
                L();
            }
            c++;
            rotateWholeLeft();
        }
    }

    void pifPuf() {
        R();
        U();
        r();
        u();
    }

    void pifPufLeft() {
        l();
        u();
        L();
        U();
    }


private:

    int findUpAngle(vector<bool> &fl) {
        int c;
        while (true) {
            c = 0;
            fl.assign(4, false);
            if (sides[UP][4] == sides[UP][7]) {
                c++;
                fl[0] = true;
            }
            if (sides[LEFT][4] == sides[LEFT][5]) {
                fl[1] = true;
                c++;
            }
            if (sides[RIGHT][4] == sides[RIGHT][3]) {
                fl[2] = true;
                c++;
            }
            if (sides[DOWN][4] == sides[DOWN][1]) {
                fl[3] = true;
                c++;
            }
            if (c >= 2) {
                break;
            }
            f();
        }
        return c;
    }

    void getGoodCross() {
        vector<bool> fl(4);
        int c = findUpAngle(fl);
        if (c == 4) {
            return;
        }
        if (fl[0] == fl[3] || fl[1] == fl[2]) {
            RotateUp();
            pifPuf();
            R();
            RotateDown();
        }
        f();
        if (fl[0] == fl[3] || fl[1] == fl[2]) {
            RotateUp();
            pifPuf();
            R();
            RotateDown();
        }
        findUpAngle(fl);
        while (sides[DOWN][4] != sides[DOWN][1] || sides[LEFT][4] != sides[LEFT][5]) {
            rotateWholeLeft();
        }
        RotateUp();
        pifPuf();
        R();
        RotateDown();
    }

    bool correctFirstLayer() {
        return sides[BACK][0] == 'W' && sides[BACK][2] == 'W' && sides[BACK][6] == 'W' && sides[BACK][8] == 'W' &&
               sides[DOWN][4] == sides[DOWN][8] && sides[DOWN][4] == sides[DOWN][6] &&
               sides[RIGHT][4] == sides[RIGHT][8] && sides[RIGHT][4] == sides[RIGHT][2] &&
               sides[UP][4] == sides[UP][0] && sides[UP][4] == sides[UP][2] &&
               sides[LEFT][4] == sides[LEFT][0] && sides[LEFT][4] == sides[LEFT][6];
    }

    void firstLayer() {
        getCross();
        getGoodCross();
        RotateUp();
        RotateUp();
        while (!correctFirstLayer()) {
            while (sides[FRONT][0] == 'W' || sides[FRONT][2] == 'W' || sides[FRONT][6] == 'W' ||
                   sides[FRONT][8] == 'W') {
                int count_f = 0;
                while (sides[DOWN][4] != sides[RIGHT][6] || sides[DOWN][2] != sides[RIGHT][4] ||
                       sides[FRONT][8] != 'W') {
                    if (count_f == 4) {
                        rotateWholeLeft();
                        count_f = 0;
                    } else {
                        f();
                        count_f++;
                    }
                }
                RotateUp();
                pifPuf();
                pifPuf();
                pifPuf();
                RotateDown();
                rotateWholeLeft();
            }

            while (sides[DOWN][2] == 'W' || sides[RIGHT][0] == 'W' || sides[UP][6] == 'W' ||
                   sides[LEFT][8] == 'W') {
                int count_f = 0;
                while (sides[FRONT][8] != sides[DOWN][4] || sides[RIGHT][6] != sides[RIGHT][4] ||
                       sides[DOWN][2] != 'W') {
                    if (count_f == 4) {
                        rotateWholeLeft();
                        count_f = 0;
                    } else {
                        f();
                        count_f++;
                    }
                }
                RotateUp();
                pifPuf();
                pifPuf();
                pifPuf();
                pifPuf();
                pifPuf();
                RotateDown();
                rotateWholeLeft();
            }

            while (sides[DOWN][0] == 'W' || sides[RIGHT][6] == 'W' || sides[UP][8] == 'W' ||
                   sides[LEFT][2] == 'W') {
                int count_f = 0;
                while (sides[FRONT][8] != sides[RIGHT][4] || sides[DOWN][2] != sides[DOWN][4] ||
                       sides[RIGHT][6] != 'W') {
                    if (count_f == 4) {
                        rotateWholeLeft();
                        count_f = 0;
                    } else {
                        f();

                        count_f++;
                    }
                }
                RotateUp();
                pifPuf();
                RotateDown();
                rotateWholeLeft();
            }


            int count_f = 0;
            while (count_f != 4) {
                if ((sides[RIGHT][8] != sides[RIGHT][4] || sides[DOWN][8] != sides[DOWN][4]) &&
                    (sides[BACK][6] == 'W' || sides[DOWN][8] == 'W' ||
                     sides[RIGHT][8] == 'W')) {
                    RotateUp();
                    pifPuf();
                    RotateDown();
                    rotateWholeLeft();
                }
                rotateWholeLeft();
                count_f++;
            }
        }
        RotateUp();
        RotateUp();
    }

    bool correctSecondLayer() {
        return sides[DOWN][4] == sides[DOWN][5] && sides[DOWN][4] == sides[DOWN][3] &&
               sides[LEFT][4] == sides[LEFT][1] && sides[LEFT][4] == sides[LEFT][7] &&
               sides[RIGHT][4] == sides[RIGHT][1] && sides[RIGHT][4] == sides[RIGHT][7] &&
               sides[UP][4] == sides[UP][5] && sides[UP][4] == sides[UP][3];
    }

    void secondLayer() {
        RotateUp();
        RotateUp();
        while (!correctSecondLayer()) {
            int countF = 0;
            int countRotate = 0;
            while (sides[DOWN][1] != sides[DOWN][4] || sides[FRONT][7] == 'Y') {
                if (countRotate == 4) {
                    break;
                } else {
                    if (countF == 4) {
                        countF = 0;
                        rotateWholeLeft();
                        countRotate++;
                    } else {
                        f();
                        countF++;
                    }
                }
            }
            if (sides[FRONT][7] == sides[LEFT][4]) {
                RotateUp();
                u();
                pifPufLeft();
                RotateRight();
                pifPuf();
                RotateLeft();
                RotateDown();
            } else if (sides[FRONT][7] == sides[RIGHT][4]) {
                RotateUp();
                U();
                pifPuf();
                RotateLeft();
                pifPufLeft();
                RotateRight();
                RotateDown();
            } else {
                int c = 0;
                while (c != 4) {
                    if (sides[DOWN][5] != sides[DOWN][4] && sides[RIGHT][7] != sides[RIGHT][4] &&
                        sides[DOWN][5] != 'Y' && sides[RIGHT][7] != 'Y') {
                        RotateUp();
                        pifPuf();
                        RotateLeft();
                        pifPufLeft();
                        RotateRight();
                        RotateDown();
                    }
                    rotateWholeLeft();
                    c++;
                }
            }
        }
        RotateUp();
        RotateUp();
    }

    void yellowCross() {
        RotateUp();
        RotateUp();
        if (sides[FRONT][1] == 'Y' && sides[FRONT][3] == 'Y' && sides[FRONT][5] == 'Y' && sides[FRONT][7] == 'Y') {
            return;
        }
        int c = 0;
        while (sides[FRONT][3] != 'Y') {
            if (c == 4) {
                break;
            }
            c++;
            f();
        }
        if (sides[FRONT][5] == 'Y') {
            RotateUp();
            F();
            pifPuf();
            f();
            RotateDown();
        } else if (sides[FRONT][1] == 'Y' || sides[FRONT][7] == 'Y') {
            if (sides[FRONT][7] == 'Y') {
                F();
            }
            RotateUp();
            F();
            pifPuf();
            pifPuf();
            f();
            RotateDown();
        } else {
            RotateUp();
            F();
            pifPuf();
            f();
            U();
            U();
            F();
            pifPuf();
            pifPuf();
            f();
            RotateDown();
        }
    }

    void goodYellowCross() {
        if (sides[LEFT][5] == sides[LEFT][4] && sides[RIGHT][3] == sides[RIGHT][4]
            && sides[DOWN][1] == sides[DOWN][4] && sides[UP][7] == sides[UP][4]) {
            return;
        }
        int c;
        while (true) {
            c = 0;
            if (sides[RIGHT][3] == sides[RIGHT][4]) {
                c++;
            }
            if (sides[UP][7] == sides[UP][4]) {
                c++;
            }
            if (sides[LEFT][5] == sides[LEFT][4]) {
                c++;
            }
            if (sides[DOWN][1] == sides[DOWN][4]) {
                c++;
            }
            if (c >= 2) {
                break;
            }
            f();
        }
        if (sides[LEFT][5] == sides[LEFT][4] && sides[RIGHT][3] == sides[RIGHT][4]
            && sides[DOWN][1] == sides[DOWN][4] && sides[UP][7] == sides[UP][4]) {
            return;
        }
        while (sides[RIGHT][3] != sides[RIGHT][4]) {
            rotateWholeLeft();
        }
        if (sides[LEFT][5] == sides[LEFT][4]) {
            RotateUp();
            R();
            U();
            r();
            U();
            R();
            U();
            U();
            r();
            RotateDown();
        }
        while (true) {
            c = 0;
            if (sides[RIGHT][3] == sides[RIGHT][4]) {
                c++;
            }
            if (sides[UP][7] == sides[UP][4]) {
                c++;
            }
            if (sides[LEFT][5] == sides[LEFT][4]) {
                c++;
            }
            if (sides[DOWN][1] == sides[DOWN][4]) {
                c++;
            }
            if (c >= 2) {
                break;
            }
            f();
        }
        if (sides[LEFT][5] == sides[LEFT][4] && sides[RIGHT][3] == sides[RIGHT][4]
            && sides[DOWN][1] == sides[DOWN][4] && sides[UP][7] == sides[UP][4]) {
            return;
        }
        while (sides[RIGHT][3] != sides[RIGHT][4] || sides[UP][7] != sides[UP][4]) {
            rotateWholeLeft();
        }
        RotateUp();
        R();
        U();
        r();
        U();
        R();
        U();
        U();
        r();
        U();
        RotateDown();
    }

    bool goodAngle() {
        return sides[FRONT][0] == 'Y' && sides[LEFT][2] == sides[LEFT][4] && sides[UP][6] == sides[UP][4] ||
               sides[FRONT][0] == sides[LEFT][4] && sides[LEFT][2] == sides[UP][4] && sides[UP][6] == 'Y' ||
               sides[FRONT][0] == sides[UP][4] && sides[LEFT][2] == 'Y' && sides[UP][6] == sides[LEFT][4];
    }

    bool allAnglesGood() {
        bool fl = true;
        for (int i = 0; i < 4; i++) {
            if (!goodAngle()) {
                fl = false;
            }
            rotateWholeLeft();
        }
        return fl;
    }

    void rightAngles() {
        int c = 0;
        while (!goodAngle()) {
            if (c == 4) {
                break;
            }
            c++;
            rotateWholeLeft();
        }
        if (c == 4) {
            RotateUp();
            U();
            R();
            u();
            l();
            U();
            r();
            u();
            L();
            RotateDown();
        }
        while (!goodAngle()) {
            c++;
            rotateWholeLeft();
            if (c == 4) {
                break;
            }
        }
        while (!allAnglesGood()) {
            RotateUp();
            U();
            L();
            u();
            r();
            U();
            l();
            u();
            R();
            RotateDown();
        }
    };

    void lastLayer() {
        for (int i = 0; i < 4; i++) {
            while (sides[FRONT][8] != 'Y') {
                RotateUp();
                r();
                d();
                R();
                D();
                RotateDown();
            }
            F();
        }
    }

    void printSquare(char c) {
        switch (c) {
            case 'W': {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                break;
            }
            case 'R': {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                break;
            }
            case 'G': {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                break;
            }
            case 'Y': {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
                break;
            }
            case 'O': {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ORANGE);
                break;
            }
            case 'B': {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
                break;
            }
        }
        cout << "▨ ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }

    void printUpOrDown(int index) {

        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0) {
                cout << "        ";
            }
            printSquare(sides[index][i]);
            if (i % 3 == 2) {
                cout << endl;
            }
        }
    }

    void printMiddle() {
        for (int k = 0; k < 3; k++) {
            for (int i = 1; i < 5; i++) {
                for (int j = 0; j < 3; j++) {
                    printSquare(sides[i][k * 3 + j]);
                }
            }
            cout << endl;
        }
    }
};


//
// Reading:
// 1 - left
// 2 - front
// 3 - up
// 4 - right
// 5 - back
// 6 - down

class Reader {
public:
    Cube cube_;

    explicit Reader(const std::string &filename) : in(filename) {};

    void readCube() {
        for (int i = 0; i < 6; i++) {
            readSide(cube_.sides[i]);
        }
    }

    void readSide(vector<char> &side) {
        for (int i = 0; i < 9; i++) {
            in >> side[i];
        }
    }

    ~Reader() {
        in.close();
    }


private:
    ifstream in;
};








