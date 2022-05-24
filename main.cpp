#include "cube.cpp"

int main() {
    system("chcp 65001");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << "Hello!!!! This is a cube solver";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    cout << " ☼" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << "Please, choose one of the possible options: " << endl;
    cout << "1    -    generate and print cube" << endl;
    cout << "2    -    read and print cube from the file" << endl;
    cout << "3    -    print cube with the pattern " << endl;
    cout << "4    -    read cube from the file, solve it" << endl;
    cout << "5    -    generate cube and solve it" << endl;
    cout << "6    -    to do rotate with a cube" << endl;

    int option;
    Cube cube;
    Reader reader("file.in");
    reader.readCube();
    Cube c = reader.cube_;
    cin >> option;
    switch (option) {
        case 1:
            c.generateCube();
            cout << "Generated cube:" << endl;
            c.printCube();
            c.solveCube();
            cout << "Solved cube" << endl;
            c.printCube();
            break;
        case 2:
            cout << "Cube from the file" << endl;
            c.printCube();
            c.solveCube();
            cout << "Solved cube" << endl;
            c.printCube();
            break;
        case 3:
            cube.generateSolvedCube();
            cube.generateFlower();
            cout << "Cube with the pattern:" << endl;
            cube.printCube();
            break;
        case 4:
            reader.readCube();
            cout << "Cube from the file" << endl;
            c.printCube();
            c.solveCube();
            cout << "Solved cube" << endl;
            c.printCube();
            cout << endl;
            break;
        case 5:
            cout << "Generated cube" << endl;
            c.generateCube();
            c.printCube();
            c.makeLogging(true);
            c.solveCube();
            cout << endl;
            cout << "Solved cube" << endl;
            cout << endl;
            c.printCube();
            break;
        case 6:
            cout << "Generated cube" << endl;
            c.generateCube();
            c.printCube();
            cout << "Enter the option" << endl;
            char op;
            cin >> op;
            c.doOption(op);
            cout << "Rotated cube" << endl;
            c.printCube();
    }
    cout << "Thank you for using!";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    cout << "☼" << endl;
}