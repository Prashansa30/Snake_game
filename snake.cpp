#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Map dimensions
const int mapwidth = 20;
const int mapheight = 20;
const int mapSize = mapwidth * mapheight;  // ✅ renamed from size

// Map data
int map[mapSize];

// Snake state
int snakeX, snakeY, snakeLength;
int direction; // 0=up, 1=right, 2=down, 3=left

// Food
int foodX, foodY;

// Game state
bool gameOver = false;

// Draw the map
void draw() {
    system("cls");  // clear console

    for (int y = 0; y < mapheight; y++) {
        for (int x = 0; x < mapwidth; x++) {
            if (x == 0 || y == 0 || x == mapwidth - 1 || y == mapheight - 1) {
                cout << "#";  // border
            } else if (x == snakeX && y == snakeY) {
                cout << "O";  // snake head
            } else if (x == foodX && y == foodY) {
                cout << "F";  // food
            } else {
                bool printed = false;
                for (int i = 0; i < mapSize; i++) {
                    if (map[i] > 0) {
                        int sx = i % mapwidth;
                        int sy = i / mapwidth;
                        if (sx == x && sy == y) {
                            cout << "o"; // snake body
                            printed = true;
                        }
                    }
                }
                if (!printed) cout << " ";
            }
        }
        cout << endl;
    }

    cout << "Score: " << (snakeLength - 1) << endl;
}

// Place new food
void placeFood() {
    foodX = rand() % (mapwidth - 2) + 1;
    foodY = rand() % (mapheight - 2) + 1;
}

// Move snake
void move(int dx, int dy) {
    int newX = snakeX + dx;
    int newY = snakeY + dy;

    if (newX <= 0 || newY <= 0 || newX >= mapwidth - 1 || newY >= mapheight - 1) {
        gameOver = true;  // hit wall
        return;
    }

    int index = newY * mapwidth + newX;
    if (map[index] > 0) {
        gameOver = true;  // hit itself
        return;
    }

    if (newX == foodX && newY == foodY) {
        snakeLength++;
        placeFood();
    }

    map[snakeY * mapwidth + snakeX] = snakeLength;
    snakeX = newX;
    snakeY = newY;
}

// Update snake state
void update() {
    switch (direction) {
        case 0: move(0, -1); break;  // up
        case 1: move(1, 0); break;   // right
        case 2: move(0, 1); break;   // down
        case 3: move(-1, 0); break;  // left
    }

    for (int i = 0; i < mapSize; i++) {
        if (map[i] > 0) map[i]--;
    }
}

// Handle input
void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': direction = 0; break;
            case 'd': direction = 1; break;
            case 's': direction = 2; break;
            case 'a': direction = 3; break;
        }
    }
}

// Main function
int main() {
    srand(GetTickCount());

    snakeX = mapwidth / 2;
    snakeY = mapheight / 2;
    snakeLength = 1;
    direction = 1; // start moving right

    placeFood();

    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(150); // control speed
    }

    cout << "Game Over! Final Score: " << (snakeLength - 1) << endl;
    system("pause");
    return 0;
}