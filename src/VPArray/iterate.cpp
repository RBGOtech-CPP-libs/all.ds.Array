#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Iterates the array [0...n], returning next value in array on each call.

PARAMS:
	init		bool
		true	reset the itr var; before starting iteration.
		false	start and continue iteration.

RETURNS:	void*
● value		allocated pointer
● 0			end of iteration

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
void* VPArray::iterate(bool init){

	if(!init){
		if(itr < length)
			return array[itr++];
	}else{
		itr = 0;
	}

	return 0;
}
/* COMMENTS: none
*/
}//ns
#endif//VPARRAY_COMPILE
