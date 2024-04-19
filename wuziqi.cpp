#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>

int num = 1;
IMAGE bgp;
int piece[15][15];

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
}

void display_winner(int num) {
	if (num == -1) {
		outtextxy(160, 100, _T("Black Win! "));
		outtextxy(30, 130, _T("Press 'R' to restart the game"));
	}
	else if (num == 1) {
			outtextxy(160, 100, _T("White Win! "));
			outtextxy(30, 130, _T("Press 'R' to restart the game"));
	}
	else {
		outtextxy(160, 100, _T("N0 Winner! "));
		outtextxy(30, 130, _T("Press 'R' to restart the game"));
	}
	
}


void restart_game() {
	std::cout << "Restart game" << std::endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++)
			piece[i][j] = 0;
	}
	num = 1;
}

void displayButton() {
	std::cout << "Press 'R' to restart the game" << std::endl;
}

int main() {
	initgraph(480, 480);
	loadimage(&bgp,_T("background.jpeg"));
	settextcolor(RED);
	settextstyle(42, 10, _T("Times New Roman"));
	setbkmode(TRANSPARENT);
	char input;
	putbackground();
	draw_line();
	draw_point();
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
}