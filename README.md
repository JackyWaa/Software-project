# Five-in-a-Row Game
Demonstration

Introduction

This project aims to develop a Five-in-a-Row game, providing players with the classic Five-in-a-Row gaming experience. Five-in-a-Row, also known as Gomoku, is a strategic board game where two players take turns placing their stones on a 15x15 grid. The objective is for a player to be the first to achieve a row of five connected stones horizontally, vertically, or diagonally.

The game offers an engaging and competitive gameplay experience, requiring players to think strategically and plan their moves in order to block their opponent while creating opportunities for their own winning combinations. It combines elements of strategy, pattern recognition, and foresight.

As the game progresses, players must carefully analyze the state of the board, anticipate their opponent's moves, and adjust their strategies accordingly. The game provides a captivating and dynamic experience suitable for players of all ages and skill levels.

This project aims to implement the game using object-oriented programming principles. It will include classes such as `Board` to represent the game board, and `Game` to handle the game flow and determine win conditions. The development will focus on clean code, modularity, and extensibility, allowing for easy customization and potential future enhancements.

By developing this Five-in-a-Row game, we aim to provide an enjoyable and challenging gaming experience for players, allowing them to relive the excitement of this classic board game and test their strategic thinking skills.

## Graphical Abstract

<img decoding="async" src="1.jfif" width="500" />

## How to operate?
1. **Start the game:** Launch the electronic Gomoku project on your device.
2. **Determine who goes first:** Decide who goes first through a mutual agreement or any method of your choice.
3. **Place a stone:** Use the mouse cursor to hover over the intersection of the board where you want to place your stone. Click the mouse to confirm the position and place your stone. Player 1 (usually black) takes the first turn, followed by Player 2 (usually white).
4. **Winning condition:** The first player to connect five stones in a row horizontally, vertically, or diagonally wins the game. If the board is filled with no player achieving five in a row, the game is a draw.
5. **Continue playing:** Players take turns placing stones until a winner is determined or the game ends in a draw.
7. **Restart or exit:** After the game is over, players can choose to restart the game, play again, or exit the electronic Gomoku project.

## Purpose of the software
The purpose of this Gomoku software project is to develop a digital version of the traditional Gomoku game for players to enjoy and engage in strategic gameplay. The project aims to provide a platform for players to challenge each other in a virtual environment, test their skills, and have fun while playing the classic board game.

Architecture Approach: Time to market + Waterfall

The Waterfall Model is applied for the development of this software. This model is chosen for its structured and sequential approach, which involves distinct phases such as requirements analysis, design, implementation, testing, and maintenance. This approach is well-suited for projects with well-defined and stable requirements, such as game development, where the end goal is clear from the beginning.The high-quality development strategy is employed to emphasize the importance of code quality, testing, and user experience. By prioritizing these aspects, the software aims to deliver a polished and enjoyable gaming experience while maintaining robustness and reliability.

## Possible Usage of the Software (Target Market)
The software is targeted towards:
- **Gamers**: Individuals who enjoy playing strategy board games and are seeking a challenging and engaging digital gaming experience.
- **Enthusiasts**: Fans of the Five-in-a-Row game who want to play it on their digital devices with high-quality graphics and intuitive gameplay.
- **Casual Players**: People looking for a fun and intellectually stimulating game to play in their leisure time.

## Development Plan


### Development Process
### Environment Setup and Basic Functionality Implementation
1.**Environment Setup**
Download and install the C++ compiler. Commonly used C++ compilers include GCC (GNU Compiler Collection), Clang and Microsoft Visual C++. Choose the appropriate compiler according to the operating system.

2.**Configure environment variables:**
By adding the path to the compiler to your system's environment variables, you can run the compiler command directly from the command line or terminal.

3.**Create a chessboard:**

Create a two-dimensional array or list to represent the chessboard, with each element representing a position on the chessboard.
Initialize the board, setting all positions to "empty".

4.**Take turns playing chess:**

Two players are allowed to take turns placing pieces on the board.
Players can click or select locations on the board to place pieces.

5.**Check the winning conditions:**

Dynamic chessboard management: Use advanced data structures to efficiently represent and manipulate chessboard status to achieve fast chess move processing and winning condition detection.
Intelligent winning detection algorithm:  Use an efficient algorithm to scan the board in real time, identify potential winning lines, and quickly determine the game result.

6.**Judging a tie:**

If the board is full and there are no five pieces connected, the game is a draw.

7.**Restart:**

Implement a feature where players can press Shift + R to restart the game when it is not over.

### Members
loong - p2211697
* **Main programmer** (develop basic logic of the game)
* Create variable and requirement tables for code development;
* Assist in writing README.md;

jacky - p2211336
* **Project Manager** (make development plan)
* **Main programmer** (solve problems in game running, develop basic logic of the game and set an initial cover)
* help record demo

andy - p2211571
* **Test controller** (test the problem of the game)
* Assist in writing README.md *
* help record demo

### Schedule

**2.21 - 3.18:** Making decisions, negotiating, and first planning

**3.18 - 4.10:** Coding, testing, problem-solving, and development

**4.10 - 4.18:** Creating a README file and making movies

**4.18 - 4.20:**  Project final inspection

### Algorithm
1.**initialization:**
**Create a 15x15 board.
Initialize all board elements to 0 (meaning empty).
Set the current player to 1 (Black).

2.**Game loop:**
Enter an infinite loop.
Wait for the player to click on a location on the board.
Get the coordinates (x, y) of the mouse click position.

3.**Handling clicks:**
**Check if position (x, y) is empty (piece[x][y] == 0).
If empty, places the current player's piece at position (x, y) (piece[x][y] = currentPlayer).
Switch the current player to the other side (currentPlayer *= -1).

4.**Check the win:**
Check if there are any five pieces around position (x, y).
If there are five pieces in a row, the game ends and the current player wins.

5.**Check the draw:**
Check if the board is full (all positions are occupied).
If the board is full and there are no winning combinations, the game ends in a draw.

6.**The loop continues:**
Return to step 2 to continue the game loop.

* Display the board:
If the board is full (no spaces available), the game ends and the game ends in a draw.
Update interface:
Draw pieces on the board based on the current player and click position.

### Current Status of Our Software
* Board setup: 15x15 grid with lines and points for visual reference.
```cpp
void putbackground() {
	putimage(0, 0, 240, 240, &bgp, 60, 60);
	putimage(240, 0, 240, 240, &bgp, 60, 60);
	putimage(0, 240, 240, 240, &bgp, 60, 60);
	putimage(240, 240, 240, 240, &bgp, 60, 60);

}

void draw_line() {
	setlinecolor(BLACK);
	for (int x = 15; x < 480; x += 30)
		line(x, 15, x, 465);
	for (int y = 15; y < 480; y += 30)
		line(15, y, 465, y);
}

void draw_point() {
	setfillcolor(BLACK);
	fillcircle(4 * 30 - 15, 4 * 30 - 15, 3);
	fillcircle(4 * 30 - 15, 12 * 30 - 15, 3);
	fillcircle(8 * 30 - 15, 8 * 30 - 15, 3);
	fillcircle(12 * 30 - 15, 4 * 30 - 15, 3);
	fillcircle(12 * 30 - 15, 12 * 30 - 15, 3);
}
```
* Player turns: Players can take turns to place their pieces on the board.
```cpp
int num = 1;
void draw_piece(int m, int n) {
    if (num == 1)
        setfillcolor(BLACK);
    else if (num == -1)
        setfillcolor(WHITE);

    // Convert mouse coordinates to grid coordinates
    int x = m / 30;
    int y = n / 30;

    // Check if the selected position is valid
    if (change_piece(x, y) == 0)
        return;

    // Draw the piece on the board
    fillcircle(m - (m % 30) + 15, n - (n % 30) + 15, 13);

    // Switch player turn
    num *= -1;
}
```
* Piece placement: Players can click on the board to place their pieces.
```cpp
MOUSEMSG m;
while (1) {
	m = GetMouseMsg();
	if (m.uMsg == WM_LBUTTONDOWN) {
		draw_piece(m.x,m.y);
	}
	while (check_over() == 1) {
		display_winner(num);
		displayButton();
		std::cin >> input;
		if (input == 'R' || input == 'r') {
			restart_game();
			cleardevice(); 
			putbackground(); 
			draw_line();
			draw_point();
		}
		else {
			std::cout << "Invalid input. Please enter 'R' to restart." << std::endl;
		}
	}
}
closegraph();
return 0;
```


* Piece validation: The software checks if a selected position is valid for placing a piece.
```cpp
int piece[15][15];

void initpiece() {
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            piece[i][j] = 0;
}

int change_piece(int x, int y) {
    if (piece[x][y] != 0)
        return 0;
    else
        piece[x][y] = num;
    return -1;
}
```
* Piece drawing: Placed pieces are drawn on the board with appropriate color and size.
```cpp
void draw_piece(int m,int n) {
	if (num == 1)
		setfillcolor(BLACK);
	else if (num == -1)
		setfillcolor(WHITE);
	int x, y;
	x = m / 30 ;
	y = n / 30 ;
	if (change_piece(x, y) == 0)
		return;
	fillcircle(m - (m % 30) + 15, n - (n % 30) + 15, 13);
	num *= -1;
}
```
* Win condition detection: The software checks for a winning condition after each piece placement.
```cpp
int check_five_piece(int x, int y) {
	if (x<2||y<2||x>12||y>12)
		return 0;
	if (piece[x][y] == piece[x - 1][y] && piece[x][y] == piece[x - 2][y] && piece[x][y] == piece[x + 1][y] && piece[x][y] == piece[x + 2][y])
		return 1;
	if (piece[x][y] == piece[x][y - 1] && piece[x][y] == piece[x][y - 2] && piece[x][y] == piece[x][y + 1] && piece[x][y] == piece[x][y + 2])
		return 1;
	if (piece[x][y] == piece[x - 1][y - 1] && piece[x][y] == piece[x - 2][y - 2] && piece[x][y] == piece[x + 1][y + 1] && piece[x][y] == piece[x + 2][y + 2])
		return 1;
	if (piece[x][y] == piece[x - 1][y + 1] && piece[x][y] == piece[x - 2][y + 2] && piece[x][y] == piece[x + 1][y - 1] && piece[x][y] == piece[x + 2][y - 2])
		return 1;
	return 0;
}

int check_over() {
	for(int i=0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			if (piece[i][j] == 0)
				continue;
			if (check_five_piece(i, j) == 1)
				return 1;
		}
	return 0;
```
* Restart game: If the game is over, the algorithm will prompt the user to restart by pressing 'R+Enter'. If the user inputs 'R+Enter', the game will reset and the board will be cleared.
  ```cpp
  void restart_game() {
	std::cout << "Restart game" << std::endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++)
			piece[i][j] = 0;
	}
	num = 1;

  void displayButton() {
	std::cout << "Press 'R' to restart the game" << std::endl;
```
* Input handling: Mouse clicks are captured and used to determine the position where a piece should be placed.
```cpp
MOUSEMSG m;
while (1) {
	m = GetMouseMsg();
	if (m.uMsg == WM_LBUTTONDOWN) {
		draw_piece(m.x,m.y);
	}
	while (check_over() == 1) {
		display_winner(num);
		displayButton();
		std::cin >> input;
		if (input == 'R' || input == 'r') {
			restart_game();
			cleardevice(); 
			putbackground(); 
			draw_line();
			draw_point();
		}
		else {
			std::cout << "Invalid input. Please enter 'R' to restart." << std::endl;
		}
	}
}
closegraph();
return 0;
```
### Future Plan
* Regret: allows the player to regret the move and undo the previous action.
* Admit Defeat: Players can admit defeat and the game ends.
* AI Battle: Players can play against AI, which has different difficulty levels.
* Replay: Players can replay past games.
* Che Code editor (for example: Visual Studio, Code::Blocks, etc.)
- Operating environment:

## Development and Runtime Environment, Language, and Minimum System Requirements
### Development Environment:
- C++ compiler (for example: GCC, Clang, etc.)
 
### Runtime Environment:
- Operating system: Windows, MacOS, Linux, etc.
- Executable file generated by C++ compiler

### Language:
- C++
### Minimum System Requirements:
- CPU: 1 GHz or more powerful processor
- Memory: At least 1 GB RAM
- Graphics card: OpenGL 2.0 compatible
- Storage: At least 100 MB available space

## Declaration:
