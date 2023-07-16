#if RBGOARRAY_DEVMAIN
#pragma once

#include <rbgo-types.h>
#include <rbgo-testdata.h>
#include <rbgo-array.h>

namespace rbgo {

/*
DsVpa
Loads VPArrays with DataSource data, displays and frees it,
so VPtest cases are more concentrated on testing.
Kind of bridge between 
*/
class DsVpa {
	TstDsTblEspPs *ds;
	Tu32 cCols;
	const char** fms;
public:
	DsVpa();
	~DsVpa();
	VPArray* tableAlloc();
	void tableFree(VPArray *vpa);
	void rowFree(char** row);
	void printTable(VPArray *vpa);
private:
	void printDim(Tu32 cRows);
	void printSep();
	void printHead();
	void printRow(const char** row);
};

}//ns
#endif//RBGOARRAY_DEVMAIN
