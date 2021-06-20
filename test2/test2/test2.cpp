#include <iostream>
#include <conio.h>

int main() {
	int* lastX = new int;
	std::cout << "a=";
	std::cin >> lastX[0];
	for (int i = 9; i >=0; --i) {
		lastX[i] = lastX[i - 1];
	}
	for (int i = 0; i < 10; ++i) {
		std::cout << i << " = " << lastX[i] << '\n';
	}
}