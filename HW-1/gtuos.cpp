#include <iostream>
#include <cinttypes>
#include <fstream>
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
	else if(cpu.state->a == 5){
		PRINT_STR(cpu);
	}
    else if(cpu.state->a == 6){
        READ_STR(cpu);
    }

	return 0;
}

void GTUOS::PRINT_B(const CPU8080 &cpu) {

	printf("System Call :PRINT_B\n");
    printf("Value of B : %d\n", cpu.state->b);
    cycleOfSystemCall +=10;
}

//if state a == 2 BC == adress
void GTUOS::PRINT_MEM(const CPU8080 &cpu) {
	uint16_t adress;
	//printf("B : %d  ",cpu.state->b);
	//printf("C : %d   \n",cpu.state->c );
	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);
	//printf("ADDR : %d \t ",adress);
	int res =(int) cpu.memory[adress];
    printf("System Call :PRINT_MEM\n");
    printf("Value of Memory : %d\n",res);

    cycleOfSystemCall +=10;

}

//if state a == 3 read int to regB
void GTUOS::READ_B(const CPU8080 &cpu) {
	int breg;
    printf("System Call :READ_B\n");
    printf("B reg value >>  ");
	cin>>breg;
	cpu.state->b = breg;

    cycleOfSystemCall +=10;
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
    printf("System Call :READ_MEM\n");
    printf("Memory Value >> ");
	cin>>inputNumber;

	cpu.memory[adress] = inputNumber;

    cycleOfSystemCall +=10;
}

//prints the str in memory address until \0
void GTUOS::PRINT_STR(const CPU8080 &cpu) {
	uint16_t  adress =0;
	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);

    printf("System Call :PRINT_STR\n");
    printf("Value of String  : ");
	while(cpu.memory[adress] != '\0'){
		printf("%c",cpu.memory[adress]);
		++adress;
	}
	printf("\n");

    cycleOfSystemCall +=100;
}

void GTUOS::READ_STR(const CPU8080 &cpu) {
	uint16_t  adress =0;

    adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);
    string inputStr;

    printf("System Call : READ_STR\n");
    printf("String Value >>");

	getline(cin,inputStr);

    for(int i= 0 ; i < inputStr.size(); ++i){
        cpu.memory[adress + i ] = inputStr[i];
    }

    cycleOfSystemCall +=100;
}

bool GTUOS::saveMemoryToFile(const CPU8080 &cpu) {
   /* ofstream outStream;

    outStream.open("memoryOut.txt");
    if(outStream.fail()){
        cerr <<"Output File can not open"<<endl;
        exit(1);
    }

    for(int i = 0 ; i< 10000; ++i){
        outStream <<"i: "<< i << "\t" <<"M: " <<cpu.memory[i]<<endl;
    }

    outStream.close();

    */

    FILE *filep;

    filep = fopen("memoryOut.txt","w");

    for(int i = 0; i< 10000; ++i){
        fprintf(filep,"%d\t%d\n",i,cpu.memory[i]);
    }

    fclose(filep);
}

int GTUOS::getNumOfSystemCalls() {
    return  cycleOfSystemCall;
}







