#include <rbgo-array.h>
#if VPARRAY_COMPILE

namespace rbgo {
/*
Reverses the order of the array.

PARAMS:		none

RETURNS:	void

ASSERTS:
● length >= 2

ERRORS:		none

NOTES:		none
*/
void VPArray::reverse(){

	Tu32 i=0, j=length-1;//(1)
	void *vp;

	while(i < j){//(2)
		vp = array[i];
		array[i++] = array[j];
		array[j--] = vp;
	}
}
/* COMMENTS: none
1. Init [i] at start and [j] at end of array.
2. Swap their values until they crossed eachother.
*/
}//ns
#endif//VPARRAY_COMPILE
