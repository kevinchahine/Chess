#include <iostream>
#include <iomanip>
#include <bitset>
#include <memory>

#include "../Chess/BitBoard.h"
#include "../Chess/Board.h"
#include "../Chess/TextDisplay.h"

using namespace std;

int main()
{
	crunch::Board board;

	unique_ptr<crunch::DisplayBase> pDisplay =
		make_unique<crunch::TextDisplay>();
	
	pDisplay->setLightCellColor(iocolor::LIGHTBLUE);
	pDisplay->setDarkCellColor(iocolor::BLUE);
	pDisplay->setLightPieceColor(iocolor::WHITE);
	pDisplay->setDarkPieceColor(iocolor::BLACK);

	pDisplay->show(board);

	cout << "Press any key to continue...\n";
	cin.get();
	return 0;
}