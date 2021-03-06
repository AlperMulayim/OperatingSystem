#include <iostream>
#include <cinttypes>
#include <fstream>
#include <limits>
#include "8080emuCPP.h"
#include "gtuos.h"


using namespace std;

GTUOS::GTUOS(string fileName,OSMemory *mainMemory, CPU8080 &cpu) {


	setTotalEmulatorCycle(0);
	setCurrentEmulatorCycle(0);
	memory = mainMemory;
	ProcessTableEntry process(fileName);

    processTable.setWorkingPID(21);
	process.setParentPID(0);
	process.setPID(processTable.generatePID());
	process.setBaseRegister(0);

   // cout <<"EMULATOR in GTUOS : "<<getTotalEmulatorCycle() << "sys" << cycleOfSystemCall <<endl;
    process.setStartCycle(getTotalEmulatorCycle() + cycleOfSystemCall);
	process.setLimitRegister(0x4000);
	process.setStateOfProcess(1);
	process.setProcessCycle(0);
	process.setThePhysicalAdress(0);

    State8080 state8080 = *cpu.state;
	process.setChipRegisters(state8080);

	//process.printProcessEntry();

    processTable.addProcess(process);

	//processTable.addProcess(process);

    //processTable.addProcess(process);

   // processTable.printProcessTable();



 }

uint64_t GTUOS::handleCall(CPU8080 & cpu){

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
    else if(cpu.state->a == 7){
        FORK(cpu);
    }
    else if(cpu.state->a == 8){
        EXEC(cpu);
    }
    else if(cpu.state->a == 9){
        WAITPID(cpu);
    }

	return 0;
}

void GTUOS::PRINT_B(const CPU8080 &cpu) {

	printf("System Call :PRINT_B\n");
	printf("Value of B : %d\n", cpu.state->b);
	cycleOfSystemCall =10;
}

//if state a == 2 BC == adress
void GTUOS::PRINT_MEM(const CPU8080 &cpu) {
	uint16_t adress;
	//printf("B : %d  ",cpu.state->b);
	//printf("C : %d   \n",cpu.state->c );
	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);
	//printf("ADDR : %d \t ",adress);
	int res =(int) memory->at(adress);
	printf("System Call :PRINT_MEM\n");
	printf("Value of Memory : %d\n",res);

	cycleOfSystemCall =10;

}

//if state a == 3 read int to regB
void GTUOS::READ_B(const CPU8080 &cpu) {
	int breg;
	printf("System Call :READ_B\n");
	printf("B reg value >>  ");
	cin>>breg;
	getchar();
	cpu.state->b = breg;

	cycleOfSystemCall =10;
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
	getchar();

	memory->at(adress) = (uint8_t) inputNumber;

	cycleOfSystemCall =10;
}

//prints the str in memory address until \0
void GTUOS::PRINT_STR(const CPU8080 &cpu) {
	uint16_t  adress =0;
	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);

	printf("System Call :PRINT_STR\n");
	printf("Value of String  : ");
	while(memory->at(adress) != '\0'){
		printf("%c",memory->at( adress));
		++adress;
	}
	printf("\n");

	cycleOfSystemCall =100;
}

void GTUOS::READ_STR(const CPU8080 &cpu) {
	uint16_t  adress =0;

	adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);
	string inputStr;

	printf("System Call : READ_STR\n");
	printf("String Value >>");

	getline(cin,inputStr);

	for(int i= 0 ; i < inputStr.size(); ++i){
		memory->at((uint32_t) (adress + i)) = (uint8_t) inputStr[i];
	}

	cycleOfSystemCall =100;
}

bool GTUOS::saveMemoryToFile(string filename,const CPU8080 &cpu) {

	FILE *filep;
	string newFileName = filename;
	string addStr = ".mem";
	string fileName =  newFileName.replace(newFileName.begin()+ newFileName.find(".") ,newFileName.end(),addStr);

	filep = fopen(fileName.c_str(),"w");

	for(int i = 0; i< 65536; ++i) {
		if ((i % 16) == 0) {
			fprintf(filep, "\n%04x\t%02x", i, memory->physicalAt(i) );
		}
		else {
			fprintf(filep, "\t%02x", memory->physicalAt(i));
		}
	}

	fclose(filep);

}

int GTUOS::getNumOfSystemCalls() {
	return  cycleOfSystemCall;
}

void GTUOS::FORK(const CPU8080 &cpu) {
    printf("FORK operations\n");


    ProcessTableEntry currentProc = processTable.getProcessByID(processTable.getWorkingPID());

    ProcessTableEntry newProc(currentProc.getFilename());

    newProc.setPID(processTable.generatePID());
    newProc.setParentPID(currentProc.getPID());
    newProc.setBaseRegister(processTable.getGivenBaseRegister());
    newProc.setLimitRegister(processTable.getGivenLimitRegister());
    newProc.setProcessCycle(30);
    newProc.setStartCycle(getNumOfSystemCalls());
    State8080 state8080 = currentProc.getChipRegisters();
    newProc.setStateOfProcess(6);
    newProc.setThePhysicalAdress(newProc.getBaseRegister());

    //set parent B;
    state8080.b = (uint8_t) newProc.getPID();
    processTable.getProcessByID(newProc.getParentPID()).setChipRegisters(state8080);

    //set child B;
    State8080 state80801 = state8080;
    state80801.b = 0;
    newProc.setChipRegisters(state80801);


    newProc.setStartCycle(getTotalEmulatorCycle() + cycleOfSystemCall);
   // cout <<"EMULATOR in FORK : "<<getTotalEmulatorCycle() << "sys : " << cycleOfSystemCall <<endl;

    state80801.pc +=1;

    processTable.removeTheProcess(currentProc);

    currentProc.setChipRegisters(state80801);

    processTable.addProcess(currentProc);

    newProc.getChipRegisters().pc += 1;

    processTable.addProcess(newProc);



     processTable.setWorkingPID(newProc.getPID());
    copyMemory(cpu, (uint32_t) currentProc.getBaseRegister(), (uint32_t) currentProc.getLimitRegister(),
               (uint32_t) newProc.getBaseRegister());
    cycleOfSystemCall = 50;

    //TODO: Gercek CPUya schedularda eklenecek state
}

void GTUOS::copyMemory(const CPU8080 &cpu,uint32_t startAdr,uint32_t startLimitAdr, uint32_t endAdr) {
    while(startAdr < startLimitAdr){
        memory->physicalAt(endAdr) = memory->physicalAt(startAdr);
        ++startAdr;
        ++endAdr;
    }
}


void GTUOS::EXEC( CPU8080 &cpu) {
    printf("EXEC operation\n");

    uint16_t  adress = 0;
	char fileName[30];
	int i = 0;
    adress = (((uint16_t)cpu.state->b << 8) | cpu.state->c);

    printf("FileName  : ");
    while(memory->at(adress) != '\0'){
        printf("%c",memory->at( adress));
		fileName[i] = memory->at(adress);
		++i;
        ++adress;
    }
	fileName[i] = '\0';
    printf("\n");

	//cout <<"File :: :::: :" <<fileName<<"::::::"<<endl;

    //set the process
	cpu.ReadFileIntoMemoryAt(fileName,
                             (uint32_t) processTable.getProcessByID(processTable.getWorkingPID()).getBaseRegister());

    cpu.state->pc = (uint16_t) processTable.getProcessByID(processTable.getWorkingPID()).getBaseRegister();
    string name = fileName;
   // cout <<"FILENAME : "<<name<<processTable.getWorkingPID();


    processTable.getProcessByID(processTable.getWorkingPID()).setFilename(name);

	cycleOfSystemCall = 80;

}

void GTUOS::WAITPID(const CPU8080 &cpu) {
    printf("WAITPID operation\n");

    cycleOfSystemCall = 80;

}

int GTUOS::getTotalEmulatorCycle() const {
	return totalEmulatorCycle;
}

void GTUOS::setTotalEmulatorCycle(int totalEmulatorCycleV) {
	totalEmulatorCycle = totalEmulatorCycleV;
}

int GTUOS::getCurrentEmulatorCycle() const {
	return currentEmulatorCycle;
}

void GTUOS::setCurrentEmulatorCycle(int currentEmulatorCycleV) {
	currentEmulatorCycle = currentEmulatorCycleV - totalEmulatorCycle;
	totalEmulatorCycle = currentEmulatorCycleV;
}

void GTUOS::roundRobinAlgorithm(CPU8080 &cpu) {
    //TODO: get process

        quantumOSCycle += getNumOfSystemCalls() + getCurrentEmulatorCycle();

        //initilize the working process
        processTable.getProcessByID(processTable.getWorkingPID()).setChipRegisters(*cpu.state);

        ProcessTableEntry currentProcess = processTable.getNextProcess();

        if(quantumOSCycle >= 100) {
            processTable.setWorkingPID(currentProcess.getPID());

            //TODO : SWTCH pid
            processTable.removeTheProcess(currentProcess);
            memory->setBaseRegister(currentProcess.getBaseRegister());
            memory->setLimitRegister(currentProcess.getLimitRegister());

            *cpu.state = currentProcess.getChipRegisters();

            processTable.addProcess(currentProcess);

            printf("SWITCH  %d,\n", currentProcess.getPID());
            quantumOSCycle = 0;
        }

        if(cpu.isHalted()){
            processTable.removeTheProcess(currentProcess);
        }



    /*

        ProcessTableEntry workingProcess = processTable.getNextProcess();

        *cpu.state = workingProcess.getChipRegisters();

        cpu.state->pc = (uint16_t) workingProcess.getBaseRegister();
        memory->setBaseRegister(workingProcess.getBaseRegister());
        memory->setLimitRegister(workingProcess.getLimitRegister());
      //  workingProcess.printProcessEntry();

        processTable.removeTheProcess(workingProcess);
        processTable.setWorkingPID(workingProcess.getPID());
        processTable.addProcess(workingProcess);


        if(cpu.isHalted()){
            cout << "HALTED \n"<<endl;
            processTable.removeTheProcess(workingProcess);
            exit(0);
        }
    */


   // cout <<processTable.getWorkingPID()<<endl;
}
















