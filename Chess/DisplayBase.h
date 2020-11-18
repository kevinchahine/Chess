#pragma once

#include "dll_symbols.h"
#include "Board.h"

#include <iocolor/iocolor.h>

namespace crunch
{
	class CHESS_API DisplayBase
	{
	public:
		virtual void show(const Board & board) const = 0;

		uint8_t getLightCellColor() const { return m_lightCellColor; }
		void setLightCellColor(uint8_t color) { m_lightCellColor = color; }
		
		uint8_t getDarkCellColor() const { return m_darkCellColor; }
		void setDarkCellColor(uint8_t color) { m_darkCellColor = color; }
		
		uint8_t getLightPieceColor() const { return m_lightPieceColor; }
		void setLightPieceColor(uint8_t color) { m_lightPieceColor = color; }
		
		uint8_t getDarkPieceColor() const { return m_darkPieceColor; }
		void setDarkPieceColor(uint8_t color) { m_darkPieceColor = color; }

	protected:
		uint8_t m_lightCellColor = iocolor::GREEN;
		uint8_t m_darkCellColor = iocolor::GRAY;

		uint8_t m_lightPieceColor = iocolor::WHITE;
		uint8_t m_darkPieceColor = iocolor::BLACK;
	};
}
