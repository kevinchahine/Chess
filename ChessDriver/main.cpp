#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

#include "../Chess/BitBoard.h"

int main()
{
	BitBoard b1;
	BitBoard b2;

	uint64_t a1 = reinterpret_cast<uint64_t>(&b1);
	uint64_t a2 = reinterpret_cast<uint64_t>(&b2);

	cout << sizeof(b1) << '\n';
	cout << a1 << '\n';
	cout << a2 << '\n';
	cout << a1 - a2 << '\n';
	
	cout << "Press any key to continue...\n";
	cin.get();
	return 0;
}