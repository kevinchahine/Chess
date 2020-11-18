#pragma once

#include "dll_symbols.h"

#include <iostream>

namespace crunch
{
	class CHESS_API Board
	{
	public:
		// --- Enumerate Cell Values ---
		static const int8_t EMPTY = 0;
		static const int8_t WHITE_PAWN = 1;
		static const int8_t WHITE_KNIGHT = 2;
		static const int8_t WHITE_BISHOP = 3;
		static const int8_t WHITE_ROOK = 4;
		static const int8_t WHITE_QUEEN = 5;
		static const int8_t WHITE_KING = 6;
		static const int8_t BLACK_PAWN = -WHITE_PAWN;
		static const int8_t BLACK_KNIGHT = -WHITE_KNIGHT;
		static const int8_t BLACK_BISHOP = -WHITE_BISHOP;
		static const int8_t BLACK_ROOK = -WHITE_ROOK;
		static const int8_t BLACK_QUEEN = -WHITE_QUEEN;
		static const int8_t BLACK_KING = -WHITE_KING;

		// Lookup table to convert piece value to a printable character
		const char letters[7] = {
			' ',	// 0 - EMPTY
			'p',	// 1 - PAWN
			'N',	// 2 - KNIGHT
			'B',	// 3 - BISHOP
			'R',	// 4 - ROOK
			'Q',	// 5 - QUEEN
			'K'		// 6 - KING
		};

	public:

		// Basic print method 
		void print(std::ostream& os = std::cout) const;

		int8_t& operator()(uint8_t row, uint8_t col) { return cells[row][col]; }
		const int8_t& operator()(uint8_t row, uint8_t col) const { return cells[row][col]; }

	private:
		// contains each cell on the chess board
		int8_t cells[8][8] = {
			{BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
			{BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN },
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN },
			{WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK},
		};
	};
}
