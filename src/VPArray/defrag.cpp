#include <rbgo-array.h>
#if VPARRAY_COMPILE

#include <malloc.h>

namespace rbgo {
/*
Defragments the array after multiple deletes with delfin(),
which merely resets the elements to zero, fragmentingthe array with empty slots.

PARAMS:		none

RETURNS:	void

ASSERTS:	none

ERRORS:		none

NOTES:		none
*/
void VPArray::defrag(){

	Tu32 i, j=0;

	while(j < length){//(1)

		if(array[j]){
			j++;
			continue;
		}
		
		break;
	}

	if(j == length)//(2)
		return;

	i = j;//(3)

	while(j < length){

		if(!array[j]){//(4)
			j++;
			continue;
		}

		while(j < length){//(5)

			if(array[j]){//(6)

				array[i++] = array[j++];//(7)
				continue;
			}

			break;//(8)
		}
	}

	length = i;//(9)
	array =	(void**)realloc(array, sizeof(void*) * length);
}
/* COMMENTS:
1. Find first empty slot.
2. There is no empty slot; done!
3. Save that slot; prep for next find.
4. Shortcut loop for all adjacent empty slots.
5. [j] arrived is value slot...
6. while this continues to be...
7. copy those values to [i] while advancing in sync.
8. [j] arrived at empty slot; goto (4)
9. New length is known; shrink array to minimal size.
*/
}//ns
#endif//VPARRAY_COMPILE
