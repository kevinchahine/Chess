#pragma once

#ifdef CHESS_EXPORTS
#define CHESS_API __declspec(dllexport)
#else
#define CHESS_API __declspec(dllimport)
#endif
