#define _USE_MATH_DEFINES
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <string>
#include "graphics.h"
using namespace std;
int main() {
	//initialization
	const int w = 10;
	const int h = 10;
	const int fps = 60;
	long int bstamp;
	long int estamp;
	int seed;
	char board[16][16];
	bool running = true;
	cin >> seed;
	//main loop
	while (running) {
		//grap timestamp
		bstamp = chrono::system_clock::now().time_since_epoch().count();

		//reset board and screen
		for (int x=0;x<w;x++) {
			for (int y=0;y<h;y++) {
				board[x][y] = ' ';
			}
		}

		//display the board
		display(w,h,board);

		//set the fps
		estamp = chrono::system_clock::now().time_since_epoch().count();
		sleep((1/fps)-((estamp-bstamp)/1000000000));
	}
}
