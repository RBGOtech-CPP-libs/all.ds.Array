#include <rbgo-array.h>
#if VPARRAY_COMPILE

namespace rbgo {
/*
Destructor VPArray.
Resets the array. 

PARAMS:		none

RETURNS: void

ASSERTS:
● Free all allocated memory before this time.

ERRORS:	none

NOTES:	none
*/
VPArray::~VPArray(){

	reset();
}
/* COMMENTS:	none
*/
}//ns
#endif//VPARRAY_COMPILE
