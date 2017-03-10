#include <iostream>
#include <cinttypes>
#include "8080emuCPP.h"
#include "gtuos.h"

using namespace std;
uint64_t GTUOS::handleCall(const CPU8080 & cpu){


	if(cpu.state->a == 1){
		PRINT_B(cpu);
	}
	else if(cpu.state->a == 2){
		PRINT_MEM(cpu);
	}
	else if(cpu.state->a == 3){
		READ_B(cpu);
	}

	return 0;
}

void GTUOS::PRINT_B(const CPU8080 &cpu) {

	//cout <<"HELLOOO " << cpu.state->b<<"    ALPER";
	if(cpu.state->a == 1) {
		printf("%d\n", cpu.state->b);
	}
}

//if state a == 2 BC == adress
void GTUOS::PRINT_MEM(const CPU8080 &cpu) {
	uint16_t adress;
	//printf("%d",cpu.state->b);
	adress = (cpu.state->b) << 4;
	adress += (cpu.state->c);
	//printf("%" PRIu16 "\n",adress); adress
	printf("%d\t",cpu.memory[adress]);
}
//if state a == 3 read int to regB
void GTUOS::READ_B(const CPU8080 &cpu) {
	uint8_t breg;
	cin>>breg;
	cpu.state->b = breg;
}

//if state a == 4 read int from keyboard
//puts the int to BC pointed memory loc.
void GTUOS::READ_MEM(const CPU8080 &cpu) {
	 // to do make here
}







