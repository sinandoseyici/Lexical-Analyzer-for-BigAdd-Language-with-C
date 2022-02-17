#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int lineCounter=1; // For exception handling 
// Control of each word. Is it equals to keyword or not.
int isKeyword(char* chr){
	char keywords [10][10] = {"int","move","to","loop","times","out","newline","add","sub","from"};
	int i, control=0;
	for (i=0; i<10; i++){
		if (strcmp(keywords[i], chr) == 0){
			control = 1;
			break;
		}
	}
	return control;
}

void control_byOneby(char chr,FILE* openedPointer, FILE* writtenPointer){
	int i=0;
	int bracketControl;
	bracketControl=0;
	if (!(isalnum(chr)) && chr!= '-')
		// In my opinion, using a switch-case form is the best way to control characters which is paranthesis, brackets, blocks etc. 
		// That's why I controled the characters with cases and then write to the file which is what. (If it's comment just pass)
		switch(chr){
			case'[':
				fprintf(writtenPointer,"Open Block \n");
				break;
			case']':
				fprintf(writtenPointer,"Close Block \n");
				break;
			case'.':
				fprintf(writtenPointer,"End Of Line \n");
				break;
			case ',':
				fprintf(writtenPointer,"Seperator \n");
				break;
			case '"':
				chr = fgetc(openedPointer);
				char* string = malloc(100);
				int length = 100;
				// adding each element untill see the ", because it's string 
				while (chr != '"' && i<= length && chr!= EOF){
					*(string+i)=chr;
					i++;
					chr= fgetc(openedPointer);
				}
				*(string+i) = '\0';
				if(i<100){
					if (chr!= EOF){
						fprintf(writtenPointer, "String constant '%s'\n", string);
					}
					else{
						printf("String quotes should close!");
					}
				}
				free(string);
				break;
			
			case '{':
				while (((chr = fgetc(openedPointer)) != '}') && chr!= EOF){
				/*
				I should not to do anything rigth there. Because;
				When the lexical analyzer sees the '{', it should pass untill see '}'.
				And when it sees, there is no need to throw exception. It's comment line.
				*/
				}
				if(chr == '}'){
					break; // so I break.
				}
				else{
					/* At this block, if curly bracket opens and doesn't close,
					After the open curly bracket,nothing is going to write to .lx file. Because, its LIKE comment but its not, so. */
					printf("When curly bracket open, it should close! Error at line:%d\n",lineCounter);
				}
			case '}':
				printf("I checked untill see end of the file and haven't seen the close curly bracket '}'. Should use close curly bracket! ");
				break;	
			
			case '-':case ' ':case'\t': break;
			case '\n':
				lineCounter++;
				break;
			
			// isalnum() is control for the unrecognized characters in the code. If it is like ( £ or $ ). It doesnt count for it.
			default:
				chr = fgetc(openedPointer);
				if (isalnum(chr)){
					printf("Invalid usage %s at line: %d\n",chr,lineCounter);
                	while(isalnum(chr) || chr=='_')
                    	chr=fgetc(openedPointer);
				}
				if (chr =='_'){
					// nothing. It could be identifier.
				}
				else{
					printf("Unrecognized character at line:%d \n",lineCounter);
				}
                if(chr!=EOF)
                    fseek(openedPointer,-1,SEEK_CUR);
			
		}
 
}
// It was for the controlling each character and if its float or something else,  throws exception.
// but I'm not sure about it's neccessary or not for the 1. project. So I kept it here.
int isEOForDigit(char* chr,FILE* openedPointer,FILE* writtenPointer){
	int eof, i;
	eof=0;
	i=0;
	while(chr[i]){
		if (isdigit(chr[i]) ==0){
			eof=1;
			control_byOneby(chr[i],openedPointer,writtenPointer);
			return 0;
		}
		i++;
	}
	return 1;
}

int isIntegerConstant(char* chr,int isMinus,FILE* openedPointer,FILE* writtenPointer){
	int digit = strlen(chr);
	int control;
	control=1;
	if (digit > 100){  // An integer can be as big as 100 decimal digits.
		printf("An integer can not be more than 100 decimal digits ! Error at line:%d\n",lineCounter);
		control=0;
		
	}
	else{
		// Controlling int constant and also controlling minus int constant 
		if(isEOForDigit(chr,openedPointer,writtenPointer)){
			if(isMinus ==1){
				fprintf(writtenPointer,"Int constant %s\n",chr-1);
			}
			else{
				fprintf(writtenPointer,"Int constant %s\n",chr);
			}
		}
		int i;
		for(i=0;i<digit;i++){
			if( !(isdigit(chr[i]) || chr[i] == '-') ){
				control=0;
			}
			break;
		}
 	}
	return control;
}
int wordControl(char* str, FILE* file, FILE* fwritten){
	int check;
	check=0;
	int length;
	if(isdigit(*str)||*str=='-')
    {
        if(*str=='-')
            if(isdigit(*(str+1)))
                isIntegerConstant(str+1,1,file,fwritten);
            else
            {
            	// controlling double minus operator. If it is, throw excepiton.
                int oneMore=0;
                while(str[oneMore]){
					char t = str[oneMore];
                    if(str[oneMore]=='-')
                    {
                        printf("Invalid  minus sign usage. Analyzer need once, you used twice '%c' at line : %d\n",str[oneMore],lineCounter);
                        break;
                    }
                    else
                    {
                        control_byOneby(str[oneMore], file, fwritten);
                    }
                    oneMore++;
                }
            }
        
        else{
        	isIntegerConstant(str,0,file,fwritten);
		}
    }
        
	else{
		length = strlen(str);
		// controlling keywords and keyword size.
		if (isKeyword(str) == 1 && (length<20)){
			fprintf(fwritten,"keyword %s\n",str);
			check=1;
		
		}
		if(!check){ // If it's not keyword and starts with the number.
			if (isdigit(str[0]) || str[0] =='_'){
				printf("Identifier must start with letter, word: %s ! Error at line: %d\n",str,lineCounter);
				return 0;
			}
			else{
				// If it's not keyword and starts with the letter.
				if(length<20){
					fprintf(fwritten,"Identifier %s\n",str);
				}
				else{
					printf("Identifier can not be more than 20 digits! Error at line: %d\n",lineCounter);
				}
			}
		}
	}

}

int main(int argc, char *argv[]) {
	FILE* file; // Opened file.
	FILE* fwritten; // Written file.
	
	// char* filenameCheck = "myscript.ba"; // Name of file.
	// For controlling other myscript1.ba myscript2.ba or etc.
	// I turned into input format.
	
	char* filename = malloc(100);
	fflush(stdin); // Reset.
	printf("Enter file name: ");
	gets(filename); // Taking file name from user.
	
	// Comparing filename with filenamecheck. Are they equal to each other or not?
	// And some exception handling.
	// if( (strcmp(filename,filenameCheck) == 1) || (strcmp(filename,filenameCheck) == -1)){
	
	file = fopen(filename,"r");
	int size=0;
	if (file == NULL){ // Control of existing file.
		printf("There is no File with the name of: %s\n",filename);
	}
	else{
		fwritten = fopen("myscript.lx","w");
	}
	char chr;
	int charPointer;
	charPointer =0;
	// Taking a character from file untill the end of file.
	while((chr=fgetc(file)) != EOF){
		/* I should give parameters that
			-which character I want to control/compare. --> chr
			-what is going to be the next character/word & from where? --> file, pointer
			-what will my lexical analyzer write? --> writtenPointer,from file to .lx
		*/
		
		control_byOneby(chr,file,fwritten);
		charPointer =0;
		if (isalnum(chr)|| chr =='-'){
			char* wordPointer = malloc(100);
			charPointer=0;
			while( chr!= ' '&& chr!= '\n'&& chr!= '\t' && chr!= ',' && chr != '.'){
				// adding each element to pointer, if it's not equal to end of line or tab or blanks or endoflineCharacter or comma.
				*(wordPointer+charPointer) = chr;
				charPointer++;
				chr = fgetc(file);
				if (chr ==EOF){
					break;
				}
			}
			fseek(file,-1,SEEK_CUR);
			// adding /0 for understanding end of string.
			*(wordPointer+charPointer)='\0';
			
			wordControl(wordPointer,file,fwritten);
			free(wordPointer);
			
		}
	}
	
	fclose(file);
	fclose(fwritten);
	return 0;
}
