#include "BitBoard.h"

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
