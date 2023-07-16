#if RBGOARRAY_DEVMAIN
#include <dev/main.h>
#include <malloc.h>
#include <string.h>

namespace rbgo {

DsVpa::DsVpa(){

	ds = new TstDsTblEspPs();
	cCols = ds->colCount();
	fms = ds->rowFms();
}

DsVpa::~DsVpa(){
	delete ds;
}

VPArray* DsVpa::tableAlloc(){

	VPArray *vpa = new VPArray();
	const char** _row;
	char** row;
	Tu32 ci;

	ds->iterate(true);
	while(_row = ds->iterate()){

		row = (char**)malloc(sizeof(char*) * cCols);

		ci = 0;
		while(ci < cCols){
			row[ci] = (char*)malloc(sizeof(char) * (strlen(_row[ci]) + 1));
			strcpy(row[ci], _row[ci]);
			ci++;
		}

		vpa->push((void*)row);
	}

	return vpa;
}

void DsVpa::tableFree(VPArray *vpa){

	char** row;
	Tu32 ci;

	vpa->iterate(true);
	while(row = (char**)vpa->iterate())
		rowFree(row);

	vpa->reset();
	delete vpa;
}

void DsVpa::rowFree(char** row){

	Tu32 ci = 0;

	while(ci < cCols)
		free(row[ci++]);

	free(row);
}

void DsVpa::printTable(VPArray *vpa){

	const char** row;
	Tu32 i = 0, length=vpa->arrlen();

	printDim(length);
	printSep();
	printHead();
	printSep();

	if(length){
		while(i < length){
			row = (const char**)vpa->arrval(i++);
			printRow(row);
		}
	}else{
		puts("[ empty table ]");
	}

	printSep();
}

//--- private

void DsVpa::printDim(Tu32 cRows){

	printf("rows=%d, cols=%d\n", cRows, cCols);
}

void DsVpa::printSep(){

	puts(ds->rowSep());
}

void DsVpa::printHead(){

	printRow(ds->colNames());
}

void DsVpa::printRow(const char** row){

	Tu32 ci = 0;
	if(row){
		while(ci < cCols){
			printf(fms[ci], row[ci]);
			ci++;
		}
		puts("");
	}else{
		puts("[ empty row ]");
	}
}

}//ns
#endif//RBGOARRAY_DEVMAIN
