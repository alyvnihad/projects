#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Point { int x, y; };

const int width = 70;
const int height = 20;

vector<Point> snake;
Point food;
char direction = 'R';
bool gameOver = false;
bool paused = false;
bool start = false;
int score = 0;
int speed = 200;

// Spawn food at a random position
void spawnFood() {
    food.x = rand() % (width - 2) + 1;
    food.y = rand() % (height - 2) + 1;
}

void draw() {
    system("cls"); // Linux or Mac("clear")

    // Top wall
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Inner space with left and right walls
    for (int y = 0; y < height; y++) {
        cout << "#"; // Left wall
        for (int x = 0; x < width; x++) {
            cout << " "; // Empty space
        }
        cout << "#"; // Rigth wall
        cout << endl;
    }

    // Bottom wall
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
}

// Move the console cursor to (x, y)
void setCursor(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Move the snake and update its position on screen
void moveSnake() {
    // Erase the tail
    Point tail = snake.back();
    setCursor(tail.x + 1, tail.y + 1);
    cout << " ";

    // Shift the body segments
    for (int i = snake.size() - 1; i > 0; i--)
        snake[i] = snake[i - 1];

    // Move the head in the current direction
    switch(direction){
        case 'U': snake[0].y--; break;
        case 'D': snake[0].y++; break;
        case 'L': snake[0].x--; break;
        case 'R': snake[0].x++; break;
    }


    // Draw the new head
    setCursor(snake[0].x + 1, snake[0].y + 1);
    cout << "O";

    // Draw the food
    if(score % 30 != 0 || score == 0){
        setCursor(food.x + 2 , food.y + 2);
        cout << "@";
    }

    if(score >= 30 && score % 30 == 0){
        setCursor(food.x + 1 , food.y + 1);
        cout << "$";
    }

    // Draw the body segments
    for (int i = 1; i < snake.size(); i++){
        setCursor(snake[i].x + 1, snake[i].y + 1);
        cout << "o";
    }

}


// Check collisions with walls or itself
void checkCollision() {
    if (snake[0].x <= -1 || snake[0].x >= width ||
        snake[0].y <= -1 || snake[0].y >= height)
        gameOver = true;

    for (int i = 1; i < snake.size(); i++) {
        if (snake[i].x == snake[0].x &&
            snake[i].y == snake[0].y)
            gameOver = true;
    }
}


// Check if the snake eats the food
void eatFood() {
    if (snake[0].x == food.x+1 && snake[0].y == food.y+1) {
        snake.push_back(snake.back());
        spawnFood();
        score+=5;
    }
    if (snake[0].x == food.x && snake[0].y == food.y && score%30 == 0) {
        snake.push_back(snake.back());
        spawnFood();
        score+=10;
        if(speed>50){
            speed-=10;
        }
    }
}

void startGame(){
    draw(); // Draw the border once

    while(start) {
        if(_kbhit()){
            char key = _getch();

            // Backspace key Game Quit
            if(key == 8){
                start = !start;
            }

            if(key == 27){ // ESC key toggles pause
                paused = !paused;
            }

            if(!paused){ // Only change direction if not paused
                if(key=='w' || key=='W' || key=='8') direction='U';
                if(key=='s' || key=='S' || key=='2') direction='D';
                if(key=='a' || key=='A' || key=='4') direction='L';
                if(key=='d' || key=='D' || key=='6') direction='R';
            }

        }
        if(!paused){
                moveSnake();
                checkCollision();
                eatFood();

                // Display game status
                setCursor(width/width - 1, height + 2);
                cout << "Continue";
                setCursor(width/width - 1, height + 3);
                cout << "Score: " << score;
        }else{
            setCursor(width/width - 1, height + 2);
            cout << "Paused  ";
        }

        if(gameOver || !start){
            setCursor(width/2 - 5, height/2);
            cout << "GAME OVER!";
            break;
        }

        Sleep(speed);

    }
}

int main() {
    snake.push_back({10,10});

    setCursor(width/2-5, height/2);
    cout<<"Game Instructions click on Tab";

    setCursor(width/2-5, height/2-2);
    cout<<"Game Start click on Enter";

    setCursor(width/2-5, height/2+2);
    cout<<"Game Quit click on Backspace";

    while(!start){

        if(_kbhit()){
            char key = _getch();

            if(key == 9){
                setCursor(width/2-5, height/2+5);
                cout<<"Game Paused or Continue click on ESC";
                setCursor(width/2-5, height/2+6);
                cout<<"Move: w=>Up, s=>Down, a=>Left, d=>Right";
                setCursor(width/2-5, height/2+7);
                cout<<"Game Quit click on Backspace";
            }

            else if(key == 13 && !start){
                start =!start;
                startGame();
                return 0;
            }

            else if(key == 8){
                return 0;
            }

        }
    }


}
