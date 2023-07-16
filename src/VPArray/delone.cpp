#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Removes the element at given index,
while returning the value for the last time.

PARAMS:
	i		Tu32
		index of:
		+ the returned the pointer
		+ the removed slot

RETURNS:	void*

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
void* VPArray::delone(Tu32 i){

	void *vp = array[i];//(1)
	Tu32  j = i + 1;//(2)

	while(j < length)//(3)
		array[i++] = array[j++];

	length--;//(4)
	array = (void**)realloc(array, sizeof(void*) * length);//(4)

	return vp;//(5)
}
/* COMMENTS:
1. Save value to be returned.
2. With [j] one slot ahead...
3. copy down to [i], advancing in sync.
4. Shrink the array by one and reallocate.
5. Return pointer for the last time.
*/
}//ns
#endif//VPARRAY_COMPILE
