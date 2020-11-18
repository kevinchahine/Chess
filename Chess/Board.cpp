#include "Board.h"

#include <iocolor/iocolor.h>

#include <algorithm>

using namespace std;

void crunch::Board::print(std::ostream& os) const
{
	// Save current char color
	os << iocolor::push();

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			register int piece = cells[row][col];

			os << iocolor::setcolor(
					piece > 0 ? iocolor::WHITE : iocolor::BLACK,			// Forground color
					row % 2 == col % 2 ? iocolor::GREEN : iocolor::GRAY);	// Background color
				
			piece = abs(piece);

			os << letters[piece];
		}
		os << '\n';
	}
	os << '\n';

	// Restore char color
	os << iocolor::pop();
}

