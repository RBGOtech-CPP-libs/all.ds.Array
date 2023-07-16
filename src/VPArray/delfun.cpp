#include <rbgo-array.h>
#if VPARRAY_COMPILE

namespace rbgo {
/*
Resets the pointer at given index to zero,
while returning the value for the last time.

PARAMS:
	i		Tu32
		index of:
		+ the returned the pointer
		+ the reset slot

RETURNS:	void*

ASSERTS:
● Call defrag after done with sequence of delfun calls.

ERRORS:		none

NOTES:
● When planning bulk deletes, this is the fastest way to go.
*/
void* VPArray::delfun(Tu32 i){

	void *vp = array[i];//(1)

	array[i] = 0;//(2)

	return vp;//(3)
}
/* COMMENTS:
1. Get the pointer at [i].
2. Reset [i].
3. Return pointer.
*/
}//ns
#endif//VPARRAY_COMPILE
