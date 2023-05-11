#pragma once

enum Simvol { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, ENTER = 13, REVERS = 113 };

enum colors {
	BLACK = 0, RED = 4, GREEN = 2, YELLOW = 14, BLUE = 1, PURPLE = 5, CYAN = 3, GREY = 8, WHITE = 7
};

struct Pacman {

	int x = 5;
	int y = 0;

}pacman;

struct Striked
{
	bool striked = false;
	bool right = false;
	bool right_Access = false;
	bool left = false;
	bool left_Access = false;
	bool up = false;
	bool up_Access = false;
	bool dowm = false;
	bool dowm_Access = false;
	int striked_x = -1;
	int striked_y = -1;

}strike;