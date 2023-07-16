#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Frees the memory referred to by the stored pointers,
and then frees the memory for the array, shrinking it to zero.

PARAMS:
	cpp		bool
		true
			use "delete" to free array[i]
		false
			use "free()" to free array[i]

RETURNS:	void

ASSERTS:
● Be sure to first free any pointers the data structures pointers
stored in this array.
● Do not reference the pointers after being freed.

ERRORS:		none

NOTES:
● See; delfun(...); to delete an entry
*/
void VPArray::reset(){

	void *vp;

	if(array){

		free(array);//(1)
		array = 0;
		length = 0;
	}
}
/* COMMENTS:
1. Free the void pointer array and set to 0
*/
}//ns
#endif//VPARRAY_COMPILE
