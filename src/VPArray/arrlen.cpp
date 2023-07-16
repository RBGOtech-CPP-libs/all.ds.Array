#include <rbgo-array.h>
#if VPARRAY_COMPILE

namespace rbgo {
/*
Returns the length of the array.

PARAMS:		none

RETURNS:	Tu32
● length of the array

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
Tu32 VPArray::arrlen(){

	return length;
}
/* COMMENTS: none
*/
}//ns
#endif//VPARRAY_COMPILE
