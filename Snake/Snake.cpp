#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <windows.h>

class Snake {
	std::vector<int> lastX = {0};
	std::vector<int> lastY = {0};
	short int point = 1;
	char field[20][20];
	char symbol;
	int appleX, appleY;
	int x = 1, y = 1;

public:void menu() {
	symbol = 30;
	std::cout << "Use   " << symbol << "   to move.\n";
	symbol = 17;
	std::cout << "    " << symbol << " ";
	symbol = 31;
	std::cout << symbol << " ";
	symbol = 16;
	std::cout << symbol;
	_getch();
	field[x][y] = 88;
	field[appleX][appleY] = 253;
	process();
}

	  void painting() {
		  system("cls");
		  for (int i = 0; i < 20; ++i) {
			  for (int j = 0; j < 20; ++j) {
				  if (i != x || j != y) {
					  field[i][j] = ' ';
				  }
				  for (int i = 1; i < lastX.size(); i += 1) {
					  field[lastX.at(i)][lastY.at(i)] = '0';
				  }
				  if (appleX != x || appleY != y) {
					  field[appleX][appleY] = 253;
				  }
				  field[x][y] = 79;
				  if ((i == 0 || i == 19) || (j == 0 || j == 19)) {
					  field[i][j] = 219;
				  }
				  std::cout << field[i][j];
			  }
			  std::cout << '\n';
		  }
	  }

	  bool process() {
		  do {
			  lastX.at(0) = x;
			  lastY.at(0) = y;
			  painting();
			  //Sleep(80);
			  if (_kbhit()) {
				  symbol = _getch();
				  if (point == 72 || point == 80) {
					  switch (symbol) {
						case 75: point = 75; break;
						case 77: point = 77; break;
					  }
				  }
				  else if (point == 75 || point == 77) {
					  switch(symbol) {
						case 72: point = 72; break;
						case 80: point = 80; break;
					  }
				  }
			  }
			  switch (point) {
					case 75: y -= 1; break;
					case 77: y += 1; break;
					case 72: x -= 1; break;
					case 80: x += 1; break;
			  }
			  switch (x) {
			  case 0: x = 18; break;
			  case 19: x = 1; break;
			  }
			  switch (y) {
			  case 0: y = 18; break;
			  case 19: y = 1; break;
			  }
			  if (field[x][y] == '0') {
				  return 0;
			  }
			  if (appleX == x && appleY == y) {
				  lastX.push_back(0);
				  lastY.push_back(0);
				  Beep(300, 100);
				  do {
					  this->appleX = 1 + rand() % 16;
					  this->appleY = 1 + rand() % 16;
				  } while (field[appleX][appleY] != ' ');
			  }
			  for (int i = lastX.size() - 1; i > 0; i--) {
				  lastX.at(i) = lastX.at(i - 1);
				  lastY.at(i) = lastY.at(i - 1);
			  }
		  } while (true);
		  delete[] &lastX;
		  delete[] &lastY;
		  return 0;
	  }

	  Snake() {
		  lastX.reserve(324);
		  lastY.reserve(324);
		  this->x = 1;
		  this->y = 1;
		  this->appleX = 2 + rand() % 16;
		  this->appleY = 2 + rand() % 16;
		  this->point = 77;
		  menu();
	  }
};

int main() {
	srand(time(0));
	Snake fragment;
	std::cout << "\n\nYou are failed.";
	/*do {
		system("start https://www.youtube.com/watch?v=5xy4n73WOMM");
	} while (true);*/
}