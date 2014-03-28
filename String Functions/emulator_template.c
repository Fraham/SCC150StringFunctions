#include "mystring.h" /* use of your implementation of string.h, see practical week 20 */

#include <stdio.h>
#include <stdlib.h>


#define MAX_PROG_LEN 10	/* The maximum length (in lines) a program can have */
#define MAX_LINE_LEN 20 /* The maximum length of a program line (in characters) */
#define MAX_OPCODE   10 /* The maximum number of opcodes (such as ADD or SUB) that are supported (used as length for opcode_str and opcode_func */
#define MAX_REGISTER 4  /* The maximum number of registers (minus INSP) (used as length for register_str and register_ptr) */

/* function pointer definition for opcodes */
typedef int (*opcode_function)(char*, char*, char*);

/* The Program */
char prog[MAX_PROG_LEN][MAX_LINE_LEN]; /* Contains the program after reading it from file */
int prog_len=0; /*The length of the loaded program in lines */

/* Registers */
unsigned int REGA=0; /* General purpose register */
unsigned int REGB=0; /* General purpose register */
unsigned int REGC=0; /* General purpose register */
unsigned int REGX=0; /* Special register, used by JMP */
unsigned int INSP=0; /* Special register, the instruction pointer pointing to the next program line to be executed */

/* arrays to allow generic access to registers, may or may not be used in the program */ 
const char *register_str[] = {"REGA", "REGB", "REGC", "REGX"};
int *register_ptr[]={&REGA, &REGB, &REGC, &REGX};

/* NOP execution */ 
int opcode_nop(char* opcode, char *arg1, char *arg2){
	INSP++; /* NOP does not do anything except movin the instruction pointer to the next instruction */
	return (0); 
}

/* Additional functions for remaining opcodes are required here */


/* Execution of PRT, printing content of registers */
int opcode_prt(char* opcode, char *arg1, char *arg2){
	if(!mystrcmp(arg1,"REGA")) printf("REGA = %d\n",REGA);
	else if(!mystrcmp(arg1,"REGB")) printf("REGB = %d\n",REGB);
	else if(!mystrcmp(arg1,"REGC")) printf("REGC = %d\n",REGC);
	else if(!mystrcmp(arg1,"REGX")) printf("REGX = %d\n",REGX);
	else if(!mystrcmp(arg1,"REGX")) printf("REGX = %d\n",REGX);
	else printf("     = %d\n",atoi(arg1));
	INSP++;
	return(0);
}

/* arrays to allow generic access to functions for opcode execution */
const char *opcode_str[] = {"NOP", "SET", "AND", "OR", "ADD", "SUB", "SHL", "SHR", "JMP", "PRT"};
/* a function may be a NULL pointer if not yet implemented, replace the NULL pointers when implementing opcode functionality */
opcode_function opcode_func[] = {&opcode_nop,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&opcode_prt};

/* this function executes one line of program code. The function will 
   return 0 if execution could be completed and -1 if an error occured.
   Depending on the instruction the instruction pointer INSP is modified  
   (JMP will modify the INSP different than other opcodes)
*/ 
int exec_instruction(char *instruction){
	/* the line below may be useful for debugging to see the current instruction*/
    /*printf("executing line: %s", instruction);*/
    
    /* three variables could be used to extract opcode and 
     arguments from the variable instruction
    char opcode[20];
    char arg1[20];
    char arg2[20];
    */
     
    /* we need here some functionality to extract opcode, 
     arg1 and arg2 from the string instruction*/
    
    /* Now we have to call the right function corresponding 
     to the right opcode For example: 
    (*opcode_func[i])(opcode,arg1,arg2);
    */
    
    /* for demonstration purpose we execute NOP independent of input
     this line must go in your implementation */
    (*opcode_func[0])("NOP",NULL,NULL);
    
    /* return value should be 0 if execution was ok otherwise -1*/
	return(0);
}

/* Executes the program. Instructions will be executed until the instruction pointer INSP points 
   to an invalid address (i.e. INSP has moved beyond prog_len). Execution will also stop if an
   instruction causes an error (e.g. a program line contains an unknown or wrong formated instruction)
*/ 
int exec_program(){
        INSP=0;
       	printf("RUNNING PROGRAM ...\n");
        while(INSP<prog_len){
            if(exec_instruction(&prog[INSP][0])<0){ /* the instruction indicated by INSP is executed */ 
       			printf("EXECUTION ERROR\n");
       			return(-1);
            }	
            /*the line below may be useful for debugging to see the register contents after each instruction*/
       		/*printf("REGS: %d %d %d %d %d\n", REGA, REGB, REGC, REGX, INSP);*/
       	}
       	printf("... DONE!\n");
       	return(0);
}

/* Open the file with name prog.txt and read it into memory. The program will be loaded 
   line by line and at this point no syntax check will be carried out. The program will be placed
   in the variable prog[][] and prog_len will indicate how long the program is 
*/
int load_program(){
       int j=0;
       FILE *f;

       /* read the program file */
       f = fopen ("prog.txt", "r");
       if (f==NULL) {
           printf("FILE OPEN ERROR\n");
           return(-1);
       }
       while(fgets(&prog[prog_len][0], MAX_LINE_LEN, f) != NULL) {
               prog_len++;
       }

       /* print program content for verification*/
       printf("PROGRAM:\n");
       for (j=0;j<prog_len;j++){
               printf("%d: %s",j, &prog[j][0]);
       }

       return(0);
}

/* The main routine of the program. */ 
int main(){
       if (load_program()<0) return(-1); /* load a program from file into memory */
       if (exec_program()<0) return(-1); /* execute program */
       return(0);
}

