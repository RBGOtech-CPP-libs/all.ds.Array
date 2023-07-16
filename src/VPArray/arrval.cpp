#include <rbgo-array.h>
#if VPARRAY_COMPILE

namespace rbgo {
/*
____

PARAMS:
	i		Tu32
		Element value to be returned.

RETURNS:	void*
● Pointer at [i]

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
void* VPArray::arrval(Tu32 i){

	return array[i];
}
/* COMMENTS: none
*/
}//ns
#endif//VPARRAY_COMPILE
