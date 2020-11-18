#pragma once

#include <iostream>
#include <algorithm>

namespace UNICODE_8
{
	void print();

	extern const unsigned char LINES[];
	
	extern const size_t LINES_SIZE;

	extern const unsigned char DOUBLE_UP;
	extern const unsigned char DOUBLE_DOWN;
	extern const unsigned char DOUBLE_LEFT;
	extern const unsigned char DOUBLE_RIGHT;
	extern const unsigned char UP;
	extern const unsigned char DOWN;
	extern const unsigned char LEFT;
	extern const unsigned char RIGHT;

	extern const unsigned char& DU;
	extern const unsigned char& DD;
	extern const unsigned char& DL;
	extern const unsigned char& DR;
	extern const unsigned char& U;
	extern const unsigned char& D;
	extern const unsigned char& L;
	extern const unsigned char& R;
}

/*
val	U	D	L	R	u	d	l	r
179	0	0	0	0	1	1	0	0
180	0	0	0	0	1	1	1	0
181	0	0	1	0	1	1	1	0
182	1	1	0	0	1	1	1	0
183	0	1	0	0	0	1	1	0
184	0	0	1	0	0	1	1	0
185	1	1	1	0	1	1	1	0
186	1	1	0	0	1	1	0	0
187	0	1	1	0	0	1	1	0
188	1	0	1	0	1	0	1	0
189	1	0	0	0	1	0	1	0
190	0	0	1	0	1	0	1	0
191	0	0	0	0	0	1	1	0
192	0	0	0	0	1	0	0	1
193	0	0	0	0	1	0	1	1
194	0	0	0	0	0	1	1	1
195	0	0	0	0	1	1	0	1
196	0	0	0	0	0	0	1	1
197	0	0	0	0	1	1	1	1
198	0	0	0	1	1	1	0	1
199	1	1	0	0	1	1	0	1
200	1	0	0	1	1	0	0	1
201	0	1	0	1	0	1	0	1
202	1	0	1	1	1	0	1	1
203	0	1	1	1	0	1	1	1
204	1	1	0	1	1	1	0	1
205	0	0	1	1	0	0	1	1
206	1	1	1	1	1	1	1	1
207	0	0	1	1	1	0	1	1
208	1	0	0	0	1	0	1	1
209	0	0	1	1	0	1	1	1
210	0	1	0	0	0	1	1	1
211	1	0	0	0	1	0	0	1
212	0	0	0	1	1	0	0	1
213	0	0	0	1	0	1	0	1
214	0	1	0	0	0	1	0	1
215	1	1	0	0	1	1	1	1
216	0	0	1	1	1	1	1	1
217	0	0	0	0	1	0	1	0
218	0	0	0	0	0	1	0	1


*/