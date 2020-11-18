#pragma once

#include "dll_symbols.h"

#include "DisplayBase.h"

#include <iocolor/iocolor.h>

namespace crunch
{
	class CHESS_API TextDisplay : public DisplayBase
	{
	public:
		virtual void show(const Board& board) const override;

	private:
		void drawTopLines() const;

		void drawHorizontalRibbon(bool isTop) const;

		void drawUpperCell(int row) const;

		void drawMiddleCell(int row, const crunch::Board& board) const;

		void drawBottomLines() const;
	};
}
