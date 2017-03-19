# OperatingSystem
### Operating System Lecture Homeworks <br />
HW-1 implementing GTUOS (special Operating System for lecture ) for some  System Calls  on Intel 8080 processor emulator in C++
<br/> [Intel 8080] https://en.wikipedia.org/wiki/Intel_8080
<br/> [.asm file to .com file] http://asdasd.rpg.fi/~svo/i8080/  Assemby code should be convert to .com from website
#### ./GTUOS file.com  DEBUGMODE
DEBUGMODE :
<br/> 0. run the code and show output only 
<br/> 1. run the code and show output with CPU status 
<br/> 2. wait for an from the keyboard and it will continue for the next instruction
<br/> All modes prints the number of cycles at the end of execution

### System Calls for HW-1 
<br/>1. PRINT_B  : print the value in register B (reg A : 1) (10 cycle )
<br/> 2. PRINT_MEM : print the content of memory pointed registers B and C (reg A : 2) (10 cycle)
<br/> 3. READ_B : reads value int keyboard and pust the register B (reg A : 3) (10 cycle)
<br/> 4. READ_MEM : reads an int from keyboard and put it pointed memory adress of B an C (regA :4) (10 cycle)
<br/> 5. PRINT_STR: print the string pointed  by regB and regC ( reg A: 5)(100 cycle)
<br/> 6. READ_STR : gets a string from keyboard and puts the memory started at pointed by regB and regC (regA : 6) (100 cycle)
![Test Output](https://cloud.githubusercontent.com/assets/12942688/24079802/de35b7f0-0c99-11e7-9aa1-5c59e89eca83.PNG)
