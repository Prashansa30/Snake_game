🐍 Snake Game in C++

A simple Snake Game built using C++ for the console.
Originally developed by TheKittyKat, improved and fixed version by ChatGPT.

📌 Features

Classic Snake gameplay in console

Food (O) appears randomly inside the map

Snake (o) grows when it eats food

Collision with walls (X) or itself ends the game

Score based on snake length

🖥 How to Play

W → Move Up

A → Move Left

S → Move Down

D → Move Right

Avoid hitting the walls or yourself!

⚙ How to Compile & Run (Windows – MSVC)

Open Developer Command Prompt for VS 2022 (or x64 Native Tools Command Prompt).

Navigate to your project folder:

cd "C:\Users\HP\Desktop\Project 1"


Compile:

cl snake.cpp


Run:

snake.exe

⚙ How to Compile & Run (MinGW – g++)

If you’re using MinGW-w64:

g++ snake.cpp -o snake.exe
snake.exe

📂 Project Structure
Snake-Game-Cpp/
│── snake.cpp      # Main source code
│── README.md      # Project description & instructions

🎮 Screenshot (Sample)
XXXXXXXXXXXXXXXXXXXX
X                  X
X     ooo          X
X        O         X
X                  X
XXXXXXXXXXXXXXXXXXXX

🏆 Future Improvements

Add levels or difficulty settings

Add score tracking with high scores

Improve console graphics with colors

✨Enjoy the game & feel free to fork this repo
