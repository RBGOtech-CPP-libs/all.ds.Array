#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Push a given pointer onto the array.
The array is reallocated to fit a new pointer in the last new slot.

PARAMS:
	vp		void*
		pointer to the new object that being pushed onto the array.

RETURNS:	bool
● true		operation succeeded
● false		operation failed; out of memory.

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
bool VPArray::push(void *vp){

	Tu32 i = length++;//(1)

	void **_a = (void**)realloc(array, sizeof(void*) * length); //(2)

	if(_a != 0){//(3)
		array = _a;
		array[i] = vp;
		return true;
	}

	length--;//(4)
	return false;
}
/* COMMENTS:
1. Increment length while getting last index.
2. Realloc the size to new length; _a may be NULL or new location.
3. _a is valid; assign to array, store new  pointer, return succes.
4. Correct premature length increment.
*/
}//ns
#endif//VPARRAY_COMPILE
