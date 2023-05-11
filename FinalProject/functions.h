#pragma once

int** CreateArr(int size);

int mySize = 10;
bool chekingIgnore = false;

int** playerBoard = CreateArr(mySize);
int** enemyBoard = CreateArr(mySize);

void mysetcolor(int fg, int bg) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

int** CreateArr(int size) {

	int** arr = new int* [size + 1];

	for (size_t i = 0; i < size + 1; i++)
		arr[i] = new int[size + 1] {};

	return arr;
}


void Show_Text(string text, int time = 3)
{
	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
		Sleep(0.1);
	}cout << endl;
}


void WordGameOver();


void YouLoserFunction() {
	system("cls");
	mysetcolor(3, 0);

	system("cls");
	Show_Text("        *     *     * * *     *     *               ", 3);
	Show_Text("         *   *     *     *    *     *               ", 3);
	Show_Text("           *       *     *    *     *               ", 3);
	Show_Text("           *       *     *    *     *               ", 3);
	Show_Text("           *        * * *      * * *                ", 3);
	cout << endl;
	cout << endl;
	Show_Text("                           *       * * *     * * * *              ", 3);
	Show_Text("                          * *      *    *    *                    ", 3);
	Show_Text("                         * * *     * * *     * * *                ", 3);
	Show_Text("                        *     *    *    *    *                    ", 3);
	Show_Text("                       *       *   *     *   * * * *              ", 3);
	cout << endl;
	cout << endl;
	Show_Text("      			              *           * * *     * * * *     * * * *   * * *     |   |   |  ", 3);
	Show_Text("      			              *          *     *   *            *         *    *    |   |   |  ", 3);
	Show_Text("      			              *          *     *     * * * *    * * *     * * *     |   |   |  ", 3);
	Show_Text("      			              *          *     *            *   *         *    *               ", 3);
	Show_Text("      			              * * * *     * * *     * * * *     * * * *   *     *   *   *   *  ", 3);
}

void YouWinnerFunction() {
	system("cls");
	mysetcolor(3, 0);

	system("cls");
	Show_Text("        *     *     * * *     *     *               ", 3);
	Show_Text("         *   *     *     *    *     *               ", 3);
	Show_Text("           *       *     *    *     *               ", 3);
	Show_Text("           *       *     *    *     *               ", 3);
	Show_Text("           *        * * *      * * *                ", 3);
	cout << endl;
	cout << endl;
	Show_Text("                           *       * * *     * * * *              ", 3);
	Show_Text("                          * *      *    *    *                    ", 3);
	Show_Text("                         * * *     * * *     * * *                ", 3);
	Show_Text("                        *     *    *    *    *                    ", 3);
	Show_Text("                       *       *   *     *   * * * *              ", 3);
	cout << endl;
	cout << endl;
	Show_Text("      			              *       *       *   ***   *    *   *    *   * * * *   * * *     |   |   |  ", 3);
	Show_Text("      			               *     * *     *     *    * *  *   * *  *   *         *    *    |   |   |  ", 3);
	Show_Text("      			                *   *   *   *      *    *  * *   *  * *   * * *     * * *     |   |   |  ", 3);
	Show_Text("      			                 * *     * *       *    *   **   *   **   *         *    *               ", 3);
	Show_Text("      			                  *       *       ***   *    *   *    *   * * * *   *     *   *   *   *  ", 3);
}

void WordWelcome();
void AsciiBoat();
void FirstScreen();
void ShowMenu();

void ShowMyShips(int** arr, int size) {

	cout << "  " << endl;
	cout << "\t\tPLAYER" << endl;

	int counterbot = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (arr[i][j] == 1) {

				mysetcolor(2, 0);
				cout << char(2) << "   ";
				mysetcolor(7, 0);
			}
			else if (arr[i][j] == 9) {

				cout << char(240) << "   ";			//PACMAN
			}
			else if (arr[i][j] == 2) {

				mysetcolor(6, 0);
				cout << char(15) << "   ";			//BOMB SELECT
				mysetcolor(7, 0);
			}
			else if (arr[i][j] == 7) {
				mysetcolor(4, 0);
				cout << 'X' << "   ";         //DESTROYED SHIPS
				mysetcolor(7, 0);
				++counterbot;
			}
			else if (arr[i][j] == 0) {

				mysetcolor(3, 0);				// AREA
				cout << char(219) << "   ";
			}
			else if (arr[i][j] == 5) {

				mysetcolor(1, 0);
				cout << char(4) << "   ";	// SHIPS	
				mysetcolor(7, 0);
			}
		}
		cout << endl << endl;
		if (counterbot == 18) {
			system("cls");
			WordGameOver();
			Sleep(3000);
			bool b = PlaySound(TEXT("GTA-San-Andreas-Mission-Failed-sound.wav"), NULL, SND_ASYNC);
			system("cls");
			YouLoserFunction();
			Sleep(11000);
		}
	}
}

void ShowEnemyShips(int** arr, int size) {

	cout << "  " << endl;
	cout << "\t\tCPU" << endl;
	int counterplayer = 0;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			if (arr[i][j] == 3) {

				mysetcolor(6, 0);
				cout << char(15) << "   ";		//BOMB PACMAN 
			}
			else if (arr[i][j] == 0) {

				mysetcolor(3, 0);
				cout << char(219) << "   ";		//AREA
			}
			else if (arr[i][j] == 7) {
				mysetcolor(4, 0);
				cout << "X" << "   ";		    //BOMBED SHIPS
				mysetcolor(7, 0);
				++counterplayer;
			}
			else if (arr[i][j] == 2) {

				mysetcolor(5, 0);
				cout << char(219) << "   ";		//BOMBED AREA
				mysetcolor(7, 0);
			}
			else {
				mysetcolor(4, 0);
				cout << char(219) << "   ";
			}
		}
		cout << endl << endl;
		if (counterplayer == 18) {
			system("cls");
			WordGameOver();
			Sleep(3000);
			bool b = PlaySound(TEXT("GTA-San-Andreas-Mission-passed-sound.wav"), NULL, SND_ASYNC);
			system("cls");
			YouWinnerFunction();
			Sleep(11000);

		}
	}
}

bool IsEmpty(int** arr, int y, int x) {

	if (y == mySize || x == mySize) {
		return false;
	}
	if (y == -1 || x == -1) {
		return false;
	}
	if (arr[y][x] == 6 || arr[y][x] == 7 || arr[y][x] == 2) {
		return true;
	}
	if (arr[y][x] != 0 || y < 0 || y >= mySize || x < 0 || x >= mySize) {
		return false;
	}
	return true;
}


bool ManualFill(int** arr, int y, int x, Simvol s, int count) {

	bool hasSomething = false;
	int countCheck = 0;

	if (s == RIGHT) {

		for (size_t i = y; i < y + 1; i++)
		{
			for (size_t j = x; j < x + count; j++) {

				if (arr[i][j] != 0 || i < 0 || i >= mySize || j < 0 || j >= mySize || arr[i][j + 1] == 5
					|| arr[y + 1][x] == 5 || arr[y][x + 1] == 5 || arr[y][x - 1] == 5)
					countCheck++;

				if (y - 1 != -1) {

					if (arr[y - 1][x] == 5)
						++countCheck;
				}
			}
		}

		if (countCheck == 0) {

			for (size_t i = y; i < y + 1; i++)
			{
				for (size_t j = x; j < x + count; j++)
					arr[i][j] = 5;
			}

			hasSomething = false;
		}

		else
		{
			hasSomething = true;
			cout << "\a" << endl;
		}
	}

	else if (s == DOWN) {

		int i = 0, k = 0;

		for (i = y; i < y + count + 1; i++) {

			if (i > 10) {
				countCheck++;
				break;
			}

			for (k = x - 1; k < x + 2; k++) {

				if (k == -1) {
					k++;
				}
				if (arr[i][k] != 0 || k < 0 || k > mySize || i < 0 || i > mySize
					|| arr[y + 1][x] == 5 || arr[y][x + 1] == 5 || arr[y][x - 1] == 5)
					++countCheck;

			}

		}

		if (countCheck == 0) {

			for (size_t i = y; i < y + count; i++)
			{
				for (size_t j = x; j < x + 1; j++)
					arr[i][j] = 5;
			}

			hasSomething = false;
		}
		else
		{
			hasSomething = true;
			cout << "\a";
		}
	}
	return hasSomething;
}


void Reverse(int** arr, int y, int x, Simvol s, int count) {

	ManualFill(arr, pacman.y, pacman.x, s, count);
}


void ClearShip(int** arr, int y, int x, Simvol s, int count) {

	if (s == RIGHT) {

		for (size_t i = y; i < y + 1; i++)
		{
			for (size_t k = x; k < x + count + 1; k++)
				arr[i][k] = 0;
		}
	}

	else if (s == DOWN) {

		for (size_t i = y; i < y + count; i++)
		{
			if (i >= 10) break;
			for (size_t k = x; k < x + 1; k++)
				arr[i][k] = 0;
		}
	}
}


bool PutShipsWithPacman(int** arr, int y, int x, Simvol direction, int count) {

	bool result = ManualFill(arr, pacman.y, pacman.x, direction, count);
	char revers = ' ';

	do
	{
		system("cls");
		ShowMyShips(arr, mySize);

		int revers = 0;
		revers = _getch();

		if (revers == REVERS) {

			if (direction == RIGHT) {

				direction = DOWN;
				ClearShip(arr, pacman.y, pacman.x, RIGHT, count);
				Reverse(arr, pacman.y, pacman.x, DOWN, count);
			}

			else if (direction == DOWN)
			{
				direction = RIGHT;
				ClearShip(arr, pacman.y, pacman.x, DOWN, count);
				Reverse(arr, pacman.y, pacman.x, RIGHT, count);
			}
			ShowMyShips(arr, mySize);
		}

		if (revers == ENTER) {
			pacman.y = 0;
			pacman.x = 0;
			break;
		}

	} while (revers != ENTER);

	return result;
}


void PlacedShipManual(int** arr) {

	int counters[7] = { 4,3,3,2,2,2,2 };
	int index = 0;

	while (true) {

		system("cls");
		ShowMyShips(playerBoard, mySize);

		int direction = 0;
		direction = _getch();

		if (direction == 224) {

			direction = _getch();
			arr[pacman.y][pacman.x] = 0;

			if (direction == RIGHT) {

				if (IsEmpty(arr, pacman.y, pacman.x + 1))
					pacman.x++;
			}

			else if (direction == LEFT) {

				if (IsEmpty(arr, pacman.y, pacman.x - 1))
					pacman.x--;
			}

			else if (direction == UP) {

				if (IsEmpty(arr, pacman.y - 1, pacman.x))
					pacman.y--;
			}

			else if (direction == DOWN) {

				if (IsEmpty(arr, pacman.y + 1, pacman.x))
					pacman.y++;
			}

			arr[pacman.y][pacman.x] = 1;
		}

		else if (direction == ENTER) {

			arr[pacman.y][pacman.x] = 0;
			bool result = PutShipsWithPacman(arr, pacman.y, pacman.x, RIGHT, counters[index]);

			if (result == false)
				++index;

			pacman.y = 0;
			pacman.y = 0;
			arr[pacman.y][pacman.x] = 1;

			if (index == 7) {
				break;
			}
		}
	}

}


bool FillShipsRandom(int** arr, int y, int x, Simvol s, int count, int data) {


	bool hasSomething = false;
	int counterchecker = 0;

	if (s == RIGHT) {

		int i = 0, k = 0;

		for (int i = y - 1; i < y + 2; i++) {

			for (int k = x - 1; k < x + count + 1; k++) {

				if (arr[i][k] != 0)
					++counterchecker;
			}
			if (counterchecker > 0)
				break;
		}

		if (counterchecker == 0) {

			for (int i = y; i < y + 1; i++) {

				for (int k = x; k < x + count; k++) {

					arr[i][k] = data;
				}
			}

			hasSomething = false;
		}

		else { hasSomething = true; }
	}

	else if (s == DOWN) {

		int i = 0, k = 0;

		for (i = y - 1; i < y + count + 1; i++) {

			if (i >= 10) {
				counterchecker++;
				break;
			}

			for (k = x - 1; k < x + 2; k++) {

				if (arr[i][k] != 0 || k < 0 || k > mySize || i < 0 || i > mySize || arr[x - 1][y + 1] == 5)
					++counterchecker;
			}
		}

		if (counterchecker == 0) {

			for (size_t i = y; i < y + count; i++)
			{
				for (size_t j = x; j < x + 1; j++)
					arr[i][j] = data;
			}

			hasSomething = false;
		}
		else
		{
			hasSomething = true;
			cout << "\a";
		}
	}
	return hasSomething;
}


void FillSpecialFunction(int** arr, int count, int data) {

	srand(time(0));   //nullptr

	bool isNotOkay = false;

	do
	{
		int x = 2 + rand() % (11 - 2 + 1);
		int y = 1 + rand() % (9 - 1 + 1);

		isNotOkay = false;

		if (y % 2 == 0) {
			isNotOkay = FillShipsRandom(arr, y, x, RIGHT, count, data);
		}
		else {
			isNotOkay = FillShipsRandom(arr, y, x, DOWN, count, data);
		}

		if (isNotOkay == false)break;

	} while (isNotOkay == true); srand(81);
}


void FillSpecialFunctionEnemy(int** arr, int count, int data) {

	srand(time(nullptr));

	bool isNotOkay = false;

	do
	{
		int x = 1 + rand() % (11 - 1 + 1);
		int y = 1 + rand() % (8 - 1 + 1);

		isNotOkay = false;

		if (x % 2 == 0) {
			isNotOkay = FillShipsRandom(arr, y, x, RIGHT, count, data);
		}
		else {
			isNotOkay = FillShipsRandom(arr, y, x, DOWN, count, data);
		}

		if (isNotOkay == false)break;

	} while (isNotOkay == true); srand(43);
}


void PlacedShipRandomly(int** arr, int data) {

	srand(200);

	const int size = 7;
	int counters[size] = { 4,3,3,2,2,2,2 };

	for (size_t i = 0; i < size; i++)
		FillSpecialFunction(arr, counters[i], data);
}


void PlacedShipRandomlyEnemy(int** arr, int data) {

	srand(101);

	const int size = 7;
	int counters[size] = { 4,3,3,2,2,2,2 };

	for (size_t i = 0; i < size; i++)
		FillSpecialFunctionEnemy(arr, counters[i], data);
}


bool Battle(int** arr) {

	int old_y = -1;
	int old_x = -1;
	int simvol = -1;

	if (chekingIgnore == false) {

		cin.ignore();
		cin.clear();
		chekingIgnore = true;
	}


	while (true) {


		system("cls");
		ShowMyShips(playerBoard, mySize);
		ShowEnemyShips(arr, mySize);

		int direction = 0;
		direction = _getch();

		if (direction == 224) {

			direction = _getch();
			old_y = pacman.y;
			old_x = pacman.x;

			if (arr[pacman.y][pacman.x] == 3 && simvol != -1)
				arr[old_y][old_x] = simvol;

			if (direction == RIGHT) {

				if (IsEmpty(arr, pacman.y, pacman.x + 1)) {
					simvol = arr[pacman.y][pacman.x + 1];
					pacman.x++;
				}
			}

			else if (direction == LEFT) {

				if (IsEmpty(arr, pacman.y, pacman.x - 1)) {
					simvol = arr[pacman.y][pacman.x - 1];
					pacman.x--;
				}
			}

			else if (direction == UP) {

				if (IsEmpty(arr, pacman.y - 1, pacman.x)) {
					simvol = arr[pacman.y - 1][pacman.x];
					pacman.y--;
				}
			}

			else if (direction == DOWN) {

				if (IsEmpty(arr, pacman.y + 1, pacman.x)) {
					simvol = arr[pacman.y + 1][pacman.x];
					pacman.y++;
				}
			}
			arr[pacman.y][pacman.x] = 3;
		}

		else if (direction == ENTER) {


			if (simvol == 6) {

				arr[pacman.y][pacman.x] = 7;
				simvol = -1;
				continue;
			}

			else if (simvol == 0) {

				arr[pacman.y][pacman.x] = 2;
				return false;
			}

			else
				arr[pacman.y][pacman.x] = 0;

			pacman.y = 0;
			pacman.x = 0;
			return false;
		}
	}
}


void ShowFunctions() {

	system("cls");
	ShowMyShips(playerBoard, mySize);
	ShowEnemyShips(enemyBoard, mySize);
}


bool IsBoom(int** arr, int x, int y) {


	if (arr[y][x - 1] == 5 || arr[y][x + 1] == 5 || arr[y - 1][x] == 5 || arr[y + 1][x] == 5) {

		return false;
	}

	return true;
}

bool IsEmptyArea(int** arr, int x, int y) {

	if (arr[y][x - 1] == 7 || arr[y][x + 1] == 7 || arr[y - 1][x] == 7 || arr[y + 1][x] == 7) {

		return false;
	}
	return true;
}


void ClearStrike(Striked& strike) {
	strike.dowm = false;
	strike.dowm_Access = false;
	strike.left = false;
	strike.left_Access = false;
	strike.right = false;
	strike.right_Access = false;
	strike.striked = false;
	strike.striked_x = -1;
	strike.striked_y = -1;
}


void BattleRandom(int** arr)
{
	srand(time(0));

	bool isOkay = false;
	int x = 0;
	int y = 0;

	while (true) {

		do {

			x = rand() % 10;
			y = rand() % 10;
			Sleep(500);

		} while (arr[y][x] == 2 || arr[y][x] == 7);

		if (!strike.striked) {

			if (arr[y][x] == 5) {

				if (IsBoom(arr, x, y)) {

					cout << "\a\a\a";
					ClearStrike(strike);
					continue;
				}

				arr[y][x] = 7;

				strike.striked = true;
				strike.striked_x = x;
				strike.striked_y = y;

				system("cls");
				ShowMyShips(playerBoard, mySize);
				ShowEnemyShips(enemyBoard, mySize);
				Sleep(500);
				continue;
			}
		}

		else {

			if (!strike.left_Access) {

				if (strike.left == false) {

					x = strike.striked_x - 1;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.left_Access = true;
						continue;
					}

					if (IsEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {

						arr[y][x] = 7;
						strike.left = true;

						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
					}

					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.left == true) {

					x = strike.striked_x - 2;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.left_Access = true;
						continue;
					}
					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.left = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.left == true) {

					x = strike.striked_x - 3;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.left = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}
			}

			if (!strike.right_Access) {


				if (strike.right == false) {

					x = strike.striked_x + 1;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (IsEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}

					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.right == true) {

					x = strike.striked_x + 2;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.right == true) {

					x = strike.striked_x + 3;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}
			}

			if (!strike.dowm_Access) {

				if (strike.dowm == false) {

					x = strike.striked_x;
					y = strike.striked_y + 1;

					if (arr[y][x] == 2) {
						strike.dowm_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.dowm_Access = true;
						continue;
					}
					if (IsEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.dowm = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}

					else {
						arr[y][x] = 2;
						strike.dowm = false;
						strike.dowm_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.dowm == true) {

					x = strike.striked_x;
					y = strike.striked_y + 2;

					if (arr[y][x] == 2) {
						strike.dowm_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.dowm_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.dowm = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.dowm = false;
						strike.dowm_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.dowm == true) {

					x = strike.striked_x;
					y = strike.striked_y + 3;

					if (arr[y][x] == 2) {
						strike.dowm_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.dowm_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.dowm = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.dowm = false;
						strike.dowm_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}
			}

			if (!strike.up_Access) {


				if (strike.up == false) {

					x = strike.striked_x;
					y = strike.striked_y - 1;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.up_Access = true;
						continue;
					}
					if (IsEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}

					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}


				if (strike.up == true) {

					x = strike.striked_x;
					y = strike.striked_y - 2;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.up_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}

				if (strike.up == true) {

					x = strike.striked_x;
					y = strike.striked_y - 3;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mySize || y<0 || x>mySize || x < 0) {
						strike.up_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (IsBoom(arr, x, y)) {
							if (IsBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearStrike(strike);
								continue;
							}
						}
						Sleep(500);
						ShowFunctions();
					}
					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						ShowFunctions();
						break;
					}
				}
			}
		}

		if (arr[y][x] == 0) {

			arr[y][x] = 2;
			break;
		}
	}
}


void WordWelcome() {
	mysetcolor(3, 0);
	Show_Text("\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -", 10);
	Show_Text("\t\t\t -                     WELCOME TO BATTLESHIP!                    -", 10);
	Show_Text("\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -", 10);

}


void WordGameOver() {
	mysetcolor(3, 0);
	Show_Text("\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -", 10);
	Show_Text("\t\t\t -                          GAME OVER!                           -", 10);
	Show_Text("\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -", 10);

}


void AsciiBoat()
{
	Show_Text(R"(                             ~ ~                                                              ~ ~
                         __/___            		                                   __/___            
                   _____/______|           		                             _____/______|           
           _______/_____\_______\_____     		                      ______/_____\_______\_____     
           \      RANDOM[0]     < < < \    		                      \     MANUAL[1]     < < < \    
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ )", 10);
}


void RulesOfGames() {
	mysetcolor(3, 0);
	cout << "RULES OF THE GAME : " << endl;
	cout << endl;

	mysetcolor(5, 0);
	cout << "\t" << (char)219;
	mysetcolor(3, 0);
	cout << " -> Is place of miss ship" << endl;
	cout << endl;

	mysetcolor(4, 0);
	cout << "\t" << "X";
	mysetcolor(7, 0);
	mysetcolor(3, 0);
	cout << " -> Is place of burst ship" << endl;
	cout << endl;

	mysetcolor(1, 0);
	cout << "\t" << (char)4;
	mysetcolor(7, 0);
	mysetcolor(3, 0);
	cout << " -> Is place of unbrust ship" << endl;
	cout << endl;

	mysetcolor(1, 0);
	cout << "\t" << (char)219;
	mysetcolor(3, 0);
	cout << " -> Is place of user's area and of computer area   " << endl;
	cout << endl;

	mysetcolor(3, 0);
	cout << "\t1. This is a two player game." << endl;
	cout << "\t2. Player 1 is you and Player 2 is the computer." << endl;
	cout << "\t3. Player 1 will be prompted if user wants to manually placed\n\tFor the game board or have the computer randomly generate a game board." << endl;
	cout << "\t4. There are five types of ships to be placed by longest length to the\n\tshortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n\thas 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells" << endl;
	cout << "\t5. The computer randomly selects which player goes first" << endl;
	cout << "\t6. The game begins as each player tries to guess the location of theships\n\tof the opposing player's game board; [X] hit and miss is purple color." << endl;
	cout << "\t7. First player to guess the location of all ships wins." << endl;
	mysetcolor(7, 0);
	cout << endl;
}


void FirstScreen() {
	mysetcolor(3, 0);

	cout << "\n";

	Show_Text("      			 __________________________________________________________________", 10);
	Show_Text("      			| *****   ****  ****** ****** **     ******  ***** **  ** ** ***** |", 10);
	Show_Text("      			| **  *  **  **   **     **   **     **     **     **  ** ** **  * |", 10);
	Show_Text("      			| *****  **  **   **     **   **     ****    ****  ****** ** ***** |", 10);
	Show_Text("      			| **  *  ******   **     **   **     **         ** **  ** ** **    |", 10);
	Show_Text("      			| *****  **  **   **     **   ****** ****** *****  **  ** ** **    |", 10);
	Show_Text("      			|__________________________________________________________________|", 10);
	Show_Text("      			\n", 10);
}

void ShowMenu() {

	int select = 0;
	int e = 0;
	mysetcolor(3, 0);
	cout << "\n\n\t\t\t\t\t\t  ";
	while (e < 19)
	{
		cout << (char)196; ++e;
	}
	cout << endl;
	cout << "          \t\t\t\t\t " << (char)179 << "NEW GAME -> 1      " << (char)179 << endl;
	cout << "          \t\t\t\t\t " << (char)179 << "RULES OF GAME  -> 2" << (char)179 << endl;
	cout << "         \t\t\t\t\t " << (char)179 << "EXIT -> 0          " << (char)179 << endl;
	cout << "         \t\t\t\t\t  ";

	int e1 = 0;
	while (e1 < 19)
	{
		cout << (char)196; ++e1;
	}

	cout << "\n\t\t\t\t\t\t   ENTER SELECT ->";
	cin >> select;
	system("cls");

	while (true) {

		if (select == 1) {
			WordWelcome();
			cout << endl << endl;
			AsciiBoat();
			cout << "\t\t\t\t\t\tENTER SELECT -> ";
			cin >> select;
			if (select == 0) {

				PlacedShipRandomly(playerBoard, 5);

				system("cls");
				ShowMyShips(playerBoard, mySize);

				PlacedShipRandomlyEnemy(enemyBoard, 6);
				ShowEnemyShips(enemyBoard, mySize);

				while (true) {
					cout << endl << endl << endl;
					system("cls");
					Battle(enemyBoard);
					BattleRandom(playerBoard);
				}
			}
			else if (select == 1) {

				playerBoard[pacman.y][pacman.x] = 1;

				PlacedShipManual(playerBoard);
				PlacedShipRandomly(enemyBoard, 6);

				while (true) {
					Sleep(1000);
					system("cls");
					Battle(enemyBoard);
					BattleRandom(playerBoard);
				}
			}
			else {
				system("cls");
				ShowMenu();
			}
		}
		else if (select == 2) {
			system("cls");
			RulesOfGames();
			system("pause");
			system("cls");
			FirstScreen();
			ShowMenu();
		}
		else if (select == 0) {
			continue;
		}
		else {
			FirstScreen();
			ShowMenu();
		}
	}
}