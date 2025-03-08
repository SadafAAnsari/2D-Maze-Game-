#include <iostream>
#include "Game.h"

using namespace std;

void Game::drawMaze() {
    system("cls"); // Use "clear" for Linux/Mac
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

void Game::handleInput() {
    char move;
    cin >> move;

    int newX = playerX, newY = playerY;
    if (move == 'w') newX--;
    if (move == 's') newX++;
    if (move == 'a') newY--;
    if (move == 'd') newY++;

    if (maze[newX][newY] != '█') {
        swap(maze[playerX][playerY], maze[newX][newY]);
        playerX = newX;
        playerY = newY;
    }
}

void Game::run() {
    while (maze[playerX][playerY] != 'E') {
        drawMaze();
        handleInput();
    }
    cout << "Congratulations! You reached the exit!\n";
}

