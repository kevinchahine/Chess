#pragma once
#include <iostream>

// Represents chess board as a bitmap
// | b0 | b1 | b2 |
// +----+----+----+
// |  0 |  0 |  0 |		Pawn  (unpushed) (can't be captures by enpassant)
// |  0 |  0 |  1 |		Pawn  (pushed)	(can be captured by enpassant)
// |  0 |  1 |  0 |		Rook  (not castleable)
// |  0 |  1 |  1 |		Rook  (castleable)
// |  1 |  0 |  0 |		Night
// |  1 |  0 |  1 |		Bishop
// |  1 |  1 |  0 |		Queen
// |  1 |  1 |  1 |		King
// +----+----+----+

//	  +---+---+---+---+---+---+---+---+ 
//  7 | 56| 57| 58| 59| 60| 61| 62| 63| 
//    +---+---+---+---+---+---+---+---+ 
//  6 | 48| 49| 50| 51| 52| 53| 54| 55| 
//    +---+---+---+---+---+---+---+---+ 
//  5 | 40| 41| 42| 43| 44| 45| 46| 47| 
//    +---+---+---+---+---+---+---+---+ 
//  4 | 32| 33| 34| 35| 36| 37| 38| 39| 
//    +---+---+---+---+---+---+---+---+ 
//  3 | 24| 25| 26| 27| 28| 29| 30| 31| 
//    +---+---+---+---+---+---+---+---+ 
//  2 | 16| 17| 18| 19| 20| 21| 22| 23| 
//    +---+---+---+---+---+---+---+---+ 
//  1 | 8 | 9 | 10| 11| 12| 13| 14| 15| 
//	  +---+---+---+---+---+---+---+---+ 
//	0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
//    +---+---+---+---+---+---+---+---+ 
//      0   1   2   3   4   5   6   7
//
// position = rowPos * 8 + colPos
// rowPos = position / 8
// colPos = position % 8
class BitBoard
{
public:
	inline bool isOccupied(uint8_t position) const;
	inline bool isWhite(uint8_t position) const;

	inline bool isPawn(uint8_t position) const;
	inline bool isPawnUnpushed(uint8_t position) const;
	inline bool isPawnPushed(uint8_t position) const;
	
	inline bool isRook(uint8_t position) const;
	inline bool isRookUncastleable(uint8_t position) const;
	inline bool isRookCastleable(uint8_t position) const;

	inline bool isNight(uint8_t position) const;

	inline bool isBishop(uint8_t position) const;

	inline bool isQueen(uint8_t position) const;

	inline bool isKing(uint8_t position) const;

	inline void removePiece(uint8_t position);
		   
	inline void setColorToWhite(uint8_t position);
	inline void setColorToBlack(uint8_t position);
	
	inline void movePawn(uint8_t from, uint8_t to);
	inline void moveRook(uint8_t from, uint8_t to);
	inline void moveNight(uint8_t from, uint8_t to);
	inline void moveBishop(uint8_t from, uint8_t to);
	inline void moveQueen(uint8_t from, uint8_t to);
	inline void moveKing(uint8_t from, uint8_t to);

	static inline uint8_t calcPosition(uint8_t rowPos, uint8_t colPos);
	static inline uint8_t calcRowPosition(uint8_t position);
	static inline uint8_t calcColPosition(uint8_t position);

protected:
	const uint64_t IS_OCCUPIED_INIT = 0xFFFF'0000'0000'FFFF;
	const uint64_t IS_WHITE_INIT = 0x0000'0000'0000'FFFF;
	const uint64_t B0_INIT = 0x7E00'0000'0000'00E7;
	const uint64_t B1_INIT = 0x9900'0000'0000'0099;
	const uint64_t B2_INIT = 0xB500'0000'0000'005B;

	uint64_t occupied = IS_OCCUPIED_INIT;
	uint64_t white = IS_WHITE_INIT;
	uint64_t b0 = B0_INIT;
	uint64_t b1 = B1_INIT;
	uint64_t b2 = B2_INIT;
};

