#include <conio.h>
#include <iomanip>
#include <iostream>
#include<fcntl.h>
#include<stdio.h>
#include<Windows.h>
#include<time.h>
using namespace std;
#include"struct.h"
#include"functions.h"


void main() {

	bool b = PlaySound(TEXT("my-music-battleship.wav"), NULL, SND_ASYNC);

	srand(time(0));

	FirstScreen();
	ShowMenu();
}