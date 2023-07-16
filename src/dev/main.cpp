#if RBGOARRAY_DEVMAIN
#include <stdlib.h>//setbuf, system, exit, atoi
#include <stdio.h>//puts, printf, scanf

#include <dev/main.h>

#include <rbgo-time.h>
#include <rbgo-random.h>


#define MENU_LENGTH 17
const char* menuStrings[MENU_LENGTH] = {
	"0	quit",
	"1	menu",
	"2	clear screen",

	"3	vpa alloc: ",
	"4	vpa free: ",
	"5	vpa print: ",
	"6	vpa->reverse() : ",
	"7	vpa->delone(i) 100x random: ",
	"8	vpa->delfun(i) 100x random: ",
	"9	vpa->defrag(): ",

	"10	vpa2 alloc: ",
	"11	vpa2 free: ",
	"12	vpa2 print: ",
	"13	vpa2->reverse() : ",
	"14	vpa2->delone(i) 100x random: ",

	"15	vpa->push(vpa2->pop()) 100x: ",
	"16	vpa->append(vpa2): "
};

void delone_100x(rbgo::VPArray *vpa, rbgo::DsVpa *dsvpa){

	rbgo::Tu32 arrlen, i, ri;
	char** row;

	arrlen = vpa->arrlen();
	i=0;
	while(arrlen && i < 100){
		ri = rbgo::rnd32(0, arrlen-1);
		printf("%d ", ri);
		if(row = (char**)vpa->delone(ri))
			dsvpa->rowFree(row);
		arrlen = vpa->arrlen();
		i++;
	}
	puts("");
}

int main(){

	setbuf(stdout, NULL);

	rbgo::Sw64 *sw = new rbgo::Sw64();
	char input[16] = {0};
	rbgo::Tu32 mc=1;

	//---- Test case data alloc ----
//VPArray
	rbgo::DsVpa *dsvpa = new rbgo::DsVpa();
	rbgo::VPArray *vpa, *vpa2;
	rbgo::Tu32 i, ri, arrlen;
	char** row;
	void* vp;

	while(1){

		sw->start();//append, pop, push

		switch(mc){
		case 0: exit(0); goto break2;
		case 1: mc=0; while(mc < MENU_LENGTH) puts(menuStrings[mc++]); break;
		case 2: system("cls | clear"); break;

//VPArray (1)
		case 3: vpa = dsvpa->tableAlloc(); break;
		case 4: dsvpa->tableFree(vpa); break;
		case 5: dsvpa->printTable(vpa); break;
		case 6: vpa->reverse(); break;
		case 7: delone_100x(vpa, dsvpa); break;
		case 8:
			arrlen = vpa->arrlen();
			i=0;
			while(arrlen && i < 100){
				ri = rbgo::rnd32(0, arrlen-1);
				printf("%d ", ri);
				if(row = (char**)vpa->delfun(ri))
					dsvpa->rowFree(row);
				i++;
			}
			puts("");
		break;
		case 9: vpa->defrag(); break;

//VPArray (2)
		case 10: vpa2 = dsvpa->tableAlloc(); break;
		case 11: dsvpa->tableFree(vpa2); break;
		case 12: dsvpa->printTable(vpa2); break;
		case 13: vpa2->reverse(); break;
		case 14: delone_100x(vpa2, dsvpa); break;

//VPArray (1 <- 2)
		case 15:
			i = 0;
			while((i < 100) && (vp = vpa2->pop())){
				vpa->push(vp);
				i++;
			}
		break;
		case 16: vpa->append(vpa2); break;
		
		}//switch
		
		if(2 < mc && mc < MENU_LENGTH)
			sw->stopp(menuStrings[mc], "\n");

		printf("choice: ");
		scanf("%2s", input);
		mc = atoi(input);
	}
break2:
//---- Test case data FREE ----
	delete sw;
	delete dsvpa;
}
#endif//RBGOARRAY_DEVMAIN
