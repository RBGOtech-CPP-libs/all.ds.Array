#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Appends all the values(pointers) of the incoming array
to the current one.

PARAMS:
	vpa		VPArray*
		The array to be appended to the this one.

RETURNS:	bool
● true		succes
● false		failure; insufficient memory.

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
bool VPArray::append(VPArray *vpa){

	Tu32 i, si=0, extlen = vpa->arrlen();//(1)

	void **_a = (void **)realloc(array, sizeof(void*) * (length + extlen));//(2)

	if(_a){//(3)

		i = length;//(4)
		length += extlen;
		array = _a;

		while(i < length)//(5)
			array[i++] = vpa->arrval(si++);

		return true;
	}

	return false;
}
/* COMMENTS: none
1. Init; get length of vpa.
2. Expand array to also fit vpa.
3. Succes!
4. Set index and update array refs.
5. Append/copy from vpa to array.
*/
}//ns
#endif//VPARRAY_COMPILE
