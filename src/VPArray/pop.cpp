#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Pops the last value of the array,
to be returned to caller,
while shrinking the array by one.

PARAMS:		none

RETURNS:	void*
● >0		Pointer value at last element.
● zero		Empty array.

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
void* VPArray::pop(){

	void *vp;
	
	if(length){//(1)

		vp = array[--length];//(2)

		array = (void**)realloc(array, sizeof(void*) * length);//(3)

		return vp;//(4)
	}

	return 0;//(5)
}
/* COMMENTS: none
1. Array with content.
2. Get last value, decrease length.
3. Shrink array.
4. Return pointer value.
5. Empty array; return zero.
*/
}//ns
#endif//VPARRAY_COMPILE
