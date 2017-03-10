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
	else if(cpu.state->a == 4){
		READ_MEM(cpu);
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
	//printf("B : %d  ",cpu.state->b);
	//printf("C : %d   \n",cpu.state->c );
	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);
	//printf("ADDR : %d \t ",adress);
	int res =(int) cpu.memory[adress];
	printf("%d\n",res);
}

//if state a == 3 read int to regB
void GTUOS::READ_B(const CPU8080 &cpu) {
	int breg;
	cin>>breg;
	cpu.state->b = breg;
}

//if state a == 4 read int from keyboard
//puts the int to BC pointed memory loc.
void GTUOS::READ_MEM(const CPU8080 &cpu) {
	 uint16_t  adress =0;
	 int  inputNumber;
	//printf("B : %d  ",cpu.state->b);
	//printf("C : %d   \n",cpu.state->c );

	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);

	//printf("ADDR : %d",adress);
	cin>>inputNumber;

	cpu.memory[adress] = inputNumber;
}







