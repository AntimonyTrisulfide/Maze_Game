#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

char grid[11][11] = {
    {'\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0'},
    {' ', ' ', '\xB0', ' ', ' ', ' ', '\xB0', ' ', ' ', ' ', '\xB0'},
    {'\xB0', ' ', '\xB0', ' ', '\xB0', ' ', '\xB0', '\xB0', '\xB0', ' ', '\xB0'},
    {'\xB0', ' ', '\xB0', ' ', '\xB0', ' ', ' ', ' ', ' ', ' ', '\xB0'},
    {'\xB0', ' ', '\xB0', ' ', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', ' ', '\xB0'},
    {'\xB0', ' ', ' ', ' ', '\xB0', ' ', ' ', ' ', ' ', ' ', '\xB0'},
    {'\xB0', '\xB0', '\xB0', ' ', '\xB0', '\xB0', '\xB0', ' ', '\xB0', ' ', '\xB0'},
    {'\xB0', ' ', ' ', ' ', ' ', ' ', '\xB0', ' ', '\xB0', ' ', '\xB0'},
    {'\xB0', '\xB0', '\xB0', ' ', '\xB0', ' ', '\xB0', ' ', '\xB0', '\xB0', '\xB0'},
    {'\xB0', ' ', ' ', ' ', '\xB0', ' ', '\xB0', ' ', ' ', ' ', ' '},
    {'\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0'}
};

void PrintGrid() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (grid[i][j] == '\xB0') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Brown
            } else if (grid[i][j] == ' ') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // White
            } else if (grid[i][j] == '#') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // Green
            }

            cout << grid[i][j];

            // Reset console color to default
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        cout << endl;
    }
}

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PrintMainMenu(){
    cout << " __  __                      _____                         " << endl;
    cout << "|  \\/  |                    / ____|                        " << endl;
    cout << "| \\  / |  __ _  ____  ___  | |  __   __ _  _ __ ___    ___ " << endl;
    cout << "| |\\/| | / _` ||_  / / _ \\ | | |_ | / _` || '_ ` _ \\  / _ \\" << endl;
    cout << "| |  | || (_| | / / |  __/ | |__| || (_| || | | | | ||  __/" << endl;
    cout << "|_|  |_| \\__,_|/___| \\___|  \\_____| \\__,_||_| |_| |_| \\___|" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << " _                 __                         __            " << endl;
    cout << "|_) __ _  _  _    |_ __ _|_ _  __   _|_ _    (_ _|_ _  ___|_" << endl;
    cout << "|   | (/__> _>    |__| | |_(/_ |     |_(_)   __) |_(_| |  |_" << endl;
    cout << endl;
    cout << endl;
    cout << "Made by Manav Marmat"<<endl;
    cout << "Controls - Arrow Keys to Move, Backspace to Reset, Escape to Exit and Enter to Start (in Main menu only)";
}

int main() {
    PrintMainMenu();

    bool hasstarted = false;
    do {
        char input = _getch();
        if (input == 13) {
            hasstarted = true;
            ClearScreen();
            cout << "Loading............." << endl;
            Sleep(2000);
            break;
        }
    } while (true);

    int x = 0, y = 1;
    int posx = x, posy = y;
    ClearScreen();

    bool hasWon = false;
    grid[y][x] = '#';
    PrintGrid();
    while (hasWon == false && hasstarted == true) {       
        char input = _getch();

        if (input == 27) {
            cout << "Exiting program." << endl;
            Sleep(3000);
            return 1;
        }

        char secondInput = _getch();

        switch (secondInput) {
            case 72:
                if (grid[y - 1][x] == '\xB0') {
                } else if (y > 0) {
                    grid[y - 1][x] = grid[y][x];
                    posy = posy-1;
                    grid[y][x] = ' ';
                    y--;
                }
                break;
            case 80:
                if (grid[y + 1][x] == '\xB0') {
                } else if (y < 10) {
                    grid[y + 1][x] = grid[y][x];
                    grid[y][x] = ' ';
                    posy = posy+1;
                    y++;
                }
                break;
            case 75:
                if (grid[y][x - 1] == '\xB0') {
                } else if (x > 0) {
                    grid[y][x - 1] = grid[y][x];
                    grid[y][x] = ' ';
                    posx = posx-1;
                    x--;
                }
                break;
            case 77:
                if (grid[y][x + 1] == '\xB0') {
                } else if (x < 10) {
                    grid[y][x + 1] = grid[y][x];
                    grid[y][x] = ' ';
                    posx = posx+1;
                    x++;
                }
                break;
            case 27:
                cout << "Exiting program." << endl;
                Sleep(3000);
                break;    
            case 8:    
                cout << "Restarting program."<<endl;
                Sleep(3000);
                grid[posy][posx]=' ';
                y=1,x=0;
                grid[y][x]='#';
                posy=y, posx=x;
                ClearScreen();
                PrintGrid();
                break;
            default:
                cout << "Error" << endl;
                break;
        }

        ClearScreen();
        PrintGrid();

        if (y == 9 && x == 10) {
            ClearScreen();
            PrintGrid();
            hasWon = true;
            cout << "Congrats!, You Won (Press ESC to Exit Game or Press Backspace to Restart)" << endl;
            do {
                char input = _getch();
                if (input == 27) {
                    cout << "Exiting program." << endl;
                    Sleep(3000);
                    break;
                }
                else if (input == 8){
                    cout << "Restarting program."<<endl;
                    Sleep(3000);
                    grid[9][10]=' ';
                    grid[1][0]='#';
                    y=1, x=0;                    
                    posy=y, posx=x;
                    hasWon = false;
                    ClearScreen();
                    PrintGrid();
                    break;
                }
                //else if (input == 109 || 77){
                //    cout<< "Exiting to Main menu."<<endl;
                //    Sleep(4000);
                //    ClearScreen();
                //    PrintMainMenu();
                //    hasstarted = false;
                //    hasWon = false;
                //    break;
                //}
                else{
                    cout<<"Error";
                }
            } while (true);
        }
    }
    return 0;
}