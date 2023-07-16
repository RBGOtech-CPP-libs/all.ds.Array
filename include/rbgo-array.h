#pragma once
#include <rbgo-types.h>

#define VPARRAY_COMPILE (!!(RTD_Ti32))

namespace rbgo {

#if VPARRAY_COMPILE
class VPArray {
	Tu32 length;
	void **array;
	Tu32 itr;
public:
	VPArray();
	~VPArray();
	bool append(VPArray *vpa);
	Tu32 arrlen();
	void* arrval(Tu32 i);
	void* iterate(bool init=false);
	void* delone(Tu32 i);
	void* delfun(Tu32 i);
	void defrag();
	bool push(void *vp);
	void* pop();
	void reverse();
	void reset();
};
#endif//VPARRAY_COMPILE

}//ns
