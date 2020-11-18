#include "TextDisplay.h"

#include <iocolor/iocolor.h>

#include "Line_Codes.h"

#include <iomanip>

using namespace std;

namespace utf = UNICODE_8;

void crunch::TextDisplay::show(const Board& board) const
{
	// Save current char color
	cout << iocolor::push();

	// Draw Top Boarder
	drawTopLines();

	drawHorizontalRibbon(true);

	for (int row = 0; row < 8; row++) {

		drawUpperCell(row);

		drawMiddleCell(row, board);

		drawUpperCell(row);
	}

	drawHorizontalRibbon(false);

	drawBottomLines();

	// Restore char color
	cout << iocolor::pop();
}

void crunch::TextDisplay::drawTopLines() const
{
	const char DOUBLE_HORIZONTAL = utf::LINES[utf::DOUBLE_LEFT | utf::DOUBLE_RIGHT];
	const char DOUBLE_VERTICAL = utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_DOWN];

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor)
		<< utf::LINES[utf::DOUBLE_DOWN | utf::DOUBLE_RIGHT]
		<< setfill(DOUBLE_HORIZONTAL)
		<< setw(8 * 5 + 3)
		<< utf::LINES[utf::DOUBLE_DOWN | utf::DOUBLE_LEFT]
		<< '\n';
}

void crunch::TextDisplay::drawHorizontalRibbon(bool isTop) const
{
	const char DOUBLE_HORIZONTAL = utf::LINES[utf::DOUBLE_LEFT | utf::DOUBLE_RIGHT];
	const char DOUBLE_VERTICAL = utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_DOWN];
	
	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor) << DOUBLE_VERTICAL;

	cout << iocolor::setcolor(
		isTop ? m_lightPieceColor : m_darkPieceColor,					// Forground color
		isTop ? m_lightCellColor : m_darkCellColor)						// Background color
		<< ' ';

	for (char col = 0; col < 8; col++) {
		cout << iocolor::setcolor(
			isTop == col % 2 ? m_lightPieceColor : m_darkPieceColor,	// Forground color
			isTop == col % 2 ? m_lightCellColor : m_darkCellColor);		// Background color

		cout << ' ' << ' ' << char('A' + col) << ' ' << ' ';
	}

	cout << iocolor::setcolor(
		!isTop ? m_lightPieceColor : m_darkPieceColor,					// Forground color
		!isTop ? m_lightCellColor : m_darkCellColor)					// Background color
		<< ' ';

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor) << DOUBLE_VERTICAL << '\n';
}

void crunch::TextDisplay::drawUpperCell(int row) const
{
	const char DOUBLE_HORIZONTAL = utf::LINES[utf::DOUBLE_LEFT | utf::DOUBLE_RIGHT];
	const char DOUBLE_VERTICAL = utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_DOWN];

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor) << DOUBLE_VERTICAL;
	
	cout << iocolor::setcolor(
		row % 2 == true ? m_lightPieceColor : m_darkPieceColor,		// Forground color
		row % 2 == true ? m_lightCellColor : m_darkCellColor)		// Background color
		<< ' ';

	for (int col = 0; col < 8; col++) {
		cout << iocolor::setbg(row % 2 == col % 2 ? m_lightCellColor : m_darkCellColor)	// Background color
			<< ' ' << ' ' << ' ' << ' ' << ' ';
	}

	cout << iocolor::setcolor(
		row % 2 == false ? m_lightPieceColor : m_darkPieceColor,	// Forground color
		row % 2 == false ? m_lightCellColor : m_darkCellColor)		// Background color
		<< ' ';

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor) << DOUBLE_VERTICAL << '\n';
}

void crunch::TextDisplay::drawMiddleCell(int row, const crunch::Board & board) const
{
	const char DOUBLE_VERTICAL = utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_DOWN];

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor) << DOUBLE_VERTICAL;

	cout << iocolor::setcolor(
		row % 2 == true ? m_lightPieceColor : m_darkPieceColor,		// Forground color
		row % 2 == true ? m_lightCellColor : m_darkCellColor)		// Background color
		<< 8 - row;

	for (int col = 0; col < 8; col++) {
		register int piece = board(row, col);

		cout << iocolor::setcolor(
			piece > 0 ? m_lightPieceColor : m_darkPieceColor,			// Forground color
			row % 2 == col % 2 ? m_lightCellColor : m_darkCellColor);	// Background color

		piece = abs(piece);

		cout << ' ' << ' ' << board.letters[piece] << ' ' << ' ';
	}

	cout << iocolor::setcolor(
		row % 2 == false ? m_lightPieceColor : m_darkPieceColor,		// Forground color
		row % 2 == false ? m_lightCellColor : m_darkCellColor)			// Background color
		<< 8 - row;

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor) << DOUBLE_VERTICAL << '\n';
}

void crunch::TextDisplay::drawBottomLines() const
{
	const char DOUBLE_HORIZONTAL = utf::LINES[utf::DOUBLE_LEFT | utf::DOUBLE_RIGHT];
	const char DOUBLE_VERTICAL = utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_DOWN];

	cout << iocolor::setcolor(m_lightPieceColor, m_darkPieceColor)
		<< utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_RIGHT]
		<< setfill(DOUBLE_HORIZONTAL)
		<< setw(8 * 5 + 3)
		<< utf::LINES[utf::DOUBLE_UP | utf::DOUBLE_LEFT]
		<< '\n';
}
