#include "BitBoard.h"

using namespace std;

inline bool BitBoard::isOccupied(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return this->occupied & (mask == mask);
}

inline bool BitBoard::isWhite(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return this->white & (mask == mask);
}

inline bool BitBoard::isPawn(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == 0) && ((this->b1 & mask) == 0);
}

inline bool BitBoard::isPawnUnpushed(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == 0) && ((this->b1 & mask) == 0) && ((this->b2 & mask) == mask);
}

inline bool BitBoard::isPawnPushed(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == 0) && ((this->b1 & mask) == 0) && ((this->b2 & mask) == 0);
}

inline bool BitBoard::isRook(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == 0) && ((this->b1 & mask) == mask);
}

inline bool BitBoard::isRookUncastleable(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == 0) && ((this->b1 & mask) == mask) && ((this->b2 & mask) == 0);
}

inline bool BitBoard::isRookCastleable(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == 0) && ((this->b1 & mask) == mask) && ((this->b2 & mask) == mask);
}

inline bool BitBoard::isNight(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == mask) && ((this->b1 & mask) == 0) && ((this->b2 & mask) == 0);
}

inline bool BitBoard::isBishop(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == mask) && ((this->b1 & mask) == 0) && ((this->b2 & mask) == mask);
}

inline bool BitBoard::isQueen(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == mask) && ((this->b1 & mask) == mask) && ((this->b2 & mask) == 0);
}

inline bool BitBoard::isKing(uint8_t position) const
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return ((this->b0 & mask) == mask) && (((this->b1 & mask)) == mask) && ((this->b2 & mask) == mask);
}

inline void BitBoard::removePiece(uint8_t position)
{
	register uint64_t mask = ~(static_cast<uint64_t>(1) << position);

	this->occupied = this->occupied & mask;
}

inline bool BitBoard::getColor(uint8_t position)
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	return (this->white & mask) == mask;
}

inline void BitBoard::setColor(uint64_t colorMask)
{
	this->white = (this->white & ~colorMask) | colorMask;
}

inline void BitBoard::setColorToWhite(uint8_t position)
{
	register uint64_t mask = static_cast<uint64_t>(1) << position;

	this->white = this->white | mask;
}

inline void BitBoard::setColorToBlack(uint8_t position)
{
	register uint64_t mask = ~(static_cast<uint64_t>(1) << position);

	this->white = this->white & mask;
}

inline void BitBoard::movePawn(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	removePiece(from);
	
	// Set 'to' bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 & ~mask);			// 0 set as unpushed pawn 
	this->b1 = (this->b1 & ~mask);			// 0 
	this->b2 = (this->b2 & ~mask);			// 0 
}

inline void BitBoard::pushPawn(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	removePiece(from);

	// Set 'to' bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 & ~mask);			// 0 set as pushed pawn 
	this->b1 = (this->b1 & ~mask);			// 0 
	this->b2 = (this->b2 | mask);			// 1 
}

inline void BitBoard::moveRook(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	removePiece(from);

	// Set 'to'bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 & ~mask);			// 0 set as uncastleable rook
	this->b1 = (this->b1 | mask);			// 1 
	this->b2 = (this->b2 & ~mask);			// 0 
}

inline void BitBoard::moveNight(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	removePiece(from);

	// Set 'to'bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 | mask);			// 1 set as Night
	this->b1 = (this->b1 & ~mask);			// 0 
	this->b2 = (this->b2 & ~mask);			// 0 
}

inline void BitBoard::moveBishop(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	removePiece(from);

	// Set 'to'bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 | mask);			// 1 set as Bishop
	this->b1 = (this->b1 & ~mask);			// 0 
	this->b2 = (this->b2 | mask);			// 1 
}

inline void BitBoard::moveQueen(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	removePiece(from);

	// Set 'to' bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 | mask);			// 1 set as Queen
	this->b1 = (this->b1 | mask);			// 1 
	this->b2 = (this->b2 & ~mask);			// 0 
}

inline void BitBoard::moveKing(uint8_t from, uint8_t to)
{
	register uint64_t mask = static_cast<uint64_t>(1) << to;
	register uint64_t colorMask = static_cast<uint64_t>(getColor(from)) << to;

	// Are we moveing the White or Black King?
	register uint64_t rowPos = calcRowPosition(from);
	if (colorMask > 0) {
		// We are moving White King

		// Is one rook in corner?
		if (isRook(0)) {
			register const uint64_t rookMask = static_cast<uint64_t>(1) << 0;

			// Yes, set as uncastleable
			b2 = b2 & ~rookMask;
		}
		// How about the other one?
		if (isRook(7)) {
			register const uint64_t rookMask = static_cast<uint64_t>(1) << 7;

			// Yes, set as uncastleable
			b2 = b2 & ~rookMask;
		}
	}
	else {
		// We are moving Black King

		// Is one rook in corner?
		if (isRook(56)) {
			register const uint64_t rookMask = static_cast<uint64_t>(1) << 56;

			// Yes, set as uncastleable
			b2 = b2 & ~rookMask;
		}
		// How about the other one?
		if (isRook(63)) {
			register const uint64_t rookMask = static_cast<uint64_t>(1) << 63;

			// Yes, set as uncastleable
			b2 = b2 & ~rookMask;
		}
	}

	removePiece(from);
	
	// Set 'to' bits
	this->occupied = this->occupied | mask;	// 1 set as occupied
	setColor(colorMask);					// c set as same color as was 'from'
	this->b0 = (this->b0 | mask);			// 1 set as King
	this->b1 = (this->b1 | mask);			// 1 
	this->b2 = (this->b2 | mask);			// 1 
}

inline void BitBoard::castleQueenSide(uint8_t from, uint8_t to)
{
	// Which castling on White or Black?
	register const uint64_t rowPos = calcRowPosition(from);

	if (rowPos == 0) {
		// White side
		moveRook(0, 3);
		moveKing(4, 2);
	}
	else if (rowPos == 7) {
		// Black side
		moveRook(56, 59);
		moveKing(60, 58);
	}
	else {
		cout << "error: " << __FUNCTION__ << " from = " << from << " to = " << to << '\n';
	}
}

inline void BitBoard::castleKingSide(uint8_t from, uint8_t to)
{
	// Which castling on White or Black?
	register const uint64_t rowPos = calcRowPosition(from);

	if (rowPos == 0) {
		// White side
		moveRook(7, 5);
		moveKing(4, 6);
	}
	else if (rowPos == 7) {
		// Black side
		moveRook(63, 61);
		moveKing(60, 62);
	}
	else {
		cout << "error: " << __FUNCTION__ << " from = " << from << " to = " << to << '\n';
	}
}

inline uint8_t BitBoard::calcPosition(uint8_t rowPos, uint8_t colPos)
{
	return (rowPos << 3) + colPos;
}

inline uint8_t BitBoard::calcRowPosition(uint8_t position)
{
	return position >> 3;
}

inline uint8_t BitBoard::calcColPosition(uint8_t position)
{
	return position % 8;
}
