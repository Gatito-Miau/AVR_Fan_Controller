/* *************************************** */
/* Copyright © Dario Napole 2011, GPLv3+   */
/* *************************************** */

#include <cstdlib>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

#include "libgenutils.h"


//General Functions
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
  #include <windows.h>
  inline void delay( unsigned long ms )
    {Sleep( ms );}

#else  /* presume POSIX */
  #include <unistd.h>
  inline void delay( unsigned long ms )
    {usleep( ms * 1000 );}
#endif

bool IsDivisible (int a, int b){
    if (!a==0 && a % b == 0){return true;}else{return false;}
}
int dividir_int (int x, int y){
	int res = 0;
	while (x > y){res++; x-=y;}
return res;
}
void gotoxy(int x, int y) {
	/*
	** gotoxy() Implementation in the *nix environment
	**
	** Note: I've heard the curses library can be useful
	** when trying to implement the handy DOS-only tools of
	** gotoxy() and clrscr() using move() and initscr().
	** Though, there is a way to write your own gotoxy()
	** in the Linux environment. This topic isn't discussed
	** often, so I'd like to bring a few new ideas to the table.
	**
	** Concept: We will use two ANSI C standard functions
	** to accomplish our task. We will use specific
	** string manuvers, according to the man pages, that
	** will allow us to execute each part of the program.
	*/
        char essq[100];		/* String variable to hold the escape sequence */
        char xstr[100];		/* Strings to hold the x and y coordinates */
        char ystr[100];		/* Escape sequences must be built with characters */

        /*
        ** Convert the screen coordinates to strings
        */
        sprintf(xstr, "%d", x);
        sprintf(ystr, "%d", y);

        /*
        ** Build the escape sequence (vertical move)
        */
        essq[0] = '\0';
        strcat(essq, "\033[");
        strcat(essq, ystr);

        /*
        ** Described in man terminfo as vpa=\E[%p1%dd
        ** Vertical position absolute
        */
        strcat(essq, "d");

        /*
        ** Horizontal move
        ** Horizontal position absolute
        */
        strcat(essq, "\033[");
        strcat(essq, xstr);
        /* Described in man terminfo as hpa=\E[%p1%dG */
        strcat(essq, "G");

        /*
        ** Execute the escape sequence
        ** This will move the cursor to x, y
        */
        printf("%s", essq);
}
void gotox(int x) {
        char essq[100];
        char xstr[100];

        sprintf(xstr, "%d", x);
        essq[0] = '\0';

		strcat(essq, "\033[");
        strcat(essq, xstr);
        strcat(essq, "G");

        printf("%s", essq);
}
int findchar (char* str, char val, int skip){
	for (unsigned int i = 0; i < strlen(str); i++){
		if (str[i] == val){
			if(skip-- == 0){return i;}
		}
	}
return -1;
}


char* Address_GetName (char * Input){	//obtiene el nombre de una direccion de archivo o direcctorio, depende de fchar(char*)
ullong pos;
ullong len = strlen(Input);
char off = 1;
uint lmts = 0;
char* out = NULL;
char lmt [] = "\\/";	//limitantes \ y /

if (strlen (Input) <= 0){return NULL;}

for (int i = len -1; i > -1; i--){
	if (!((Input[i] == lmt[0] || Input[i] == lmt[1]) && i + lmts == len-1)){
		if ( Input[i] == lmt[0] || Input[i] == lmt[1] || i == 0){
			pos = i;
			if ( !(Input[i] == lmt[0] || Input[i] == lmt[1])){off = 0;} // si el primer caracter no es \ o /, reduce el offset (off) a 0 y devuelve todo el nombre
			out = new_char ((strlen((char*)&Input[pos+off])-lmts));
			memcpy(out, (char*)&Input[pos+off], len-(pos+off+lmts));	//copia desde donde empiesa, (longitud - posision + off + lmts) bytes (chars)

			i = -1;
		}
	}else{lmts++;}
}
return out;
}

char* Address_GetExt (char * Input){	//obtiene la extension de una direccion de archivo, depende de fchar(char*)
ullong pos;
ullong len = strlen(Input);
char off = 1;
uint lmts = 0;
char* out = NULL;
char lmt [] = "\\/.";	//limitantes .

if (strlen (Input) <= 0){return NULL;}

for (int i = len -1; i > -1; i--){
	if (!((Input[i] == lmt[0] || Input[i] == lmt[1] || Input[i] == lmt[2]) && i + lmts == len-1)){
		if ( Input[i] == lmt[2] || i == 0){
			pos = i;
			if ( !( Input[i] == lmt[0] || Input[i] == lmt[1] || Input[i] == lmt[2]  ) ){off = 0;} // si el primer caracter no es \, / o "." , reduce el offset (off) a 0 y devuelve todo el nombre

			out = new_char ((strlen((char*)&Input[pos+off])-lmts));
			memcpy(out, (char*)&Input[pos+off], len-(pos+off+lmts));	//copia desde donde empiesa, (longitud - posision + off + lmts) bytes (chars)
			i = -1;
		}
	}else{lmts++;}
}
return out;
}
bool CharIsFromGroup(char ch, char* grp){
	for(uint i = 0; i < strlen(grp); i++){
		if(ch == grp[i]){return 1;}
	}
return 0;
}

bool isLegible (char * Input, int len){	//comprueba es legible segun alphanum[], overload con longitud del string
    const char alphanum [] =
    "ABCDEFGHIJKLMNOPKRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "1234567890 -+=_.()[]{}¡!¿?\"#$%&/";
	int hit = 0;
	int hit_count = 0;
	if(len < 0){len = (signed)strlen(Input);}
    for (int i = 0; i < len; i++){ //por cada letra de la enrtada

		for (int j = 0; j < (signed)strlen(alphanum); j++){ 	//compara input[i] con alphanum[j]
			if (Input[i] == alphanum[j]){hit++;}
			if (hit > 0){
				j = (signed)strlen(alphanum);  //comprueba si coincidio alguna letra hasta ahora y si "si" termina el for actual
				hit = 0; hit_count++;}
		}

    }
	if (hit_count == len){return true;}
return false;
}
streamsize GetFileSize (ifstream* file ){ //devuelve el tamaño de un ifstream*
	streamsize i = file->tellg();
	file->seekg(0, ios::end);
	streamsize o = file->tellg();
	file->seekg(i);
return o;
}
streamsize GetFileSize (char* path ){ //devuelve el tamaño de un archivo
	ifstream file (path);
	streamsize i = file.tellg();
	file.seekg(0, ios::end);
	streamsize o = file.tellg();
	file.seekg(i);
return o;
}
char* Address_TrimSlashes (char* in){	//si termina con lmt[] los remueve y devuelve un char* corregido
ullong len = strlen(in);
uint lmts = 0;
char* out = new_char(len);
char* temp;
strcpy (out, in);
char lmt [] = "\\/";	//limitantes \ y /

for (int i = len -1; i > -1; i--){
	if (!((out[i] == lmt[0] || out[i] == lmt[1]) && i + lmts == len-1)){
		len = strlen(out);
		temp = new_char(len);
		strcpy (temp, out);
		free(out);

		out = new_char(len);
		strcpy (out, temp);
		free(temp);

		return out;
	}else{lmts++;out[i]=0;}
}
return out;
/*Address_TrimSlashes*/}
char* Fix_C_Name(char* in){

	if (strlen(in)==0){
	char* error = (char*)malloc(0);
	error[0] = 0;
	return error;
	}
    const char alphanum [] =
    "_ABCDEFGHIJKLMNOPKRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "1234567890";

    const char numbers [] =
    "0123456789";

	char reem = 95;	// 95 = "_"

    //char* out = (char*)malloc(strlen(in)+1); memset(out, 0, strlen(in)+1);
    char* out = in;

	int out_len = (signed)strlen(out);

	int hit_num_cnt = 0;
	int miss_aphnum = 0;

    for (int i = 0; i < out_len; i++){ //por cada letra de la entrada, i = indice para out
		miss_aphnum = 0;

		if (out_len + hit_num_cnt - i == out_len){ 			//Comprueba q los primeros caracteres no sean numeros, si son los reemplaza por "_"
			for (int k = 0; k < (signed)strlen(numbers);k++){
				if (out[i] == numbers[k]){out[i] = reem;hit_num_cnt++;k = (signed)strlen(numbers);}
			}
		}

		for (int j = 0; j < (signed)strlen(alphanum); j++){ 	//compara out[i] con alphanum[j]
			if (out[i] != alphanum[j]){miss_aphnum++;}	// Si coincide, aumenta miss_aphnum para demostrar q es algun caracter de alphanum
		}

		if ( miss_aphnum == (signed)strlen(alphanum)) { miss_aphnum = 0; out[i] = reem;}  // Si out[i] no es ningun caracter de alphanum entonces lo reemplaza por "_"
    }

    return out;

}
void strtoup(char* str){
	for (uint i = 0; i < strlen(str); i++){
		if( str[i]>= 0x61 && str[i] <= 0x7a){
			str[i] -= 0x20;
		}
	}
}
int strcnt(char* str, char* chain){
	int cnt = 0;
	int tmp = 0;
	int str_len = strlen(str), chain_len = strlen(chain);

	if (strlen(str) == 0){return 0;}

	for (int i = 0; i < str_len; i ++){

		if(str[i] == chain[0]){
			for (int j = 0; j < chain_len; j++){

				if(str[i+j] == chain[j]){
					tmp++;
				}else{
					j = chain_len;
					tmp = 0;
				}
				if (j == chain_len-1 && tmp == chain_len){ cnt++; tmp=0; i+=chain_len-1;}
			}
		}
	}
	return cnt;
}

void memshft(void* ptr, int val, int size, bool zero){
	if (val >= size) { val = size % val;}
	if (val < 1) { return;}

	char* tmp = new char[val];

	memcpy(tmp, ptr, val);
	memmove(ptr, (uchar*)ptr+val, size-val);

	if (zero){
		memset ((uchar*)ptr+(size-val), 0, val);
	}else{
		memcpy((uchar*)ptr+(size-val), tmp, val);
	}

	delete [] tmp;
}

bool getbit(void* val, int size, int bit)
{
	if ( ((bit/8) + ((bit%8) > 0 ? 1 : 0)) > size )
	{
		return false;
	}
	
	unsigned char* buf= (unsigned char*)val;
	
	while (bit > 7)
	{
		buf += 1*(bit/8);
		bit -= 8*(bit/8);
	}
	
    return ((*buf & (1 << bit)) == (1 << bit) );
}

void shift_adress(void* ptr, int val, int size, bool zero){
	printf("shift_adress() is deprecated, use memshft() instead\n");
		memshft(ptr, val, size, zero);
}
bool FileExists(char* strFilename) {
  struct stat stFileInfo;
  bool blnReturn;
  int intStat;

  intStat = stat(strFilename,&stFileInfo);
  if(intStat == 0) {
    blnReturn = true;
  } else {
    blnReturn = false;
  }

  return(blnReturn);
}
void ceroalaizq (uint num, uint len, char* out){
	char* tmp2 = new_char(len);
	char* tmp3 = new_char(len);

	sprintf(tmp2, "%u", num);
		while( strlen(tmp2) < uint(len) ){
			sprintf(tmp3, "0%s", tmp2);
			strcpy(tmp2, tmp3);
	}

	sprintf(out, "%s",  tmp2);

	delete tmp2; delete tmp3;
}
uint GetTicks(){
	timeval tval; double ret = 0;
    gettimeofday(&tval, NULL);
    ret = tval.tv_sec;
    ret += tval.tv_usec / 1000000.0;
    ret = ret * 1000.0;
    return uint(ret);
}
double GetTicks_usec()
{
    timeval tval; double ret = 0;
    gettimeofday(&tval, NULL);
    ret = tval.tv_sec * 1000000.0;
    ret += tval.tv_usec;
    return ret;
}
void strchrnk(char* &data){
char* tmp = new_char(strlen(data));
strcpy(tmp, data);
delete [] data;
data = tmp;
}

void ResizeNewUCharPointer(uchar* &data, uint data_size, uint new_size){
if(data_size > new_size){data_size = new_size;}
uchar* tmp = new_uchar(new_size);
memcpy(tmp, data, data_size);
delete [] data;
data = tmp;
}

bool IsNumeric(char* str, unsigned int len)
{
	if (!strlen(str)){return false;}
	if (len == 0) { len = strlen(str);}

	bool rc = true;
	for (uint i = 0; i < len; i++)
	{
		rc &= (str[i] >= 48 && str[i] <= 57);
		if (!rc){return rc;}
	}
	return rc;
}

double dint (double in){
	return int(in);
}
double decimals (double in){
	if (in > 0){
		return in - double(int(in));
	}else if (in < 0){
		return -(int(in) - in);
	}
	return 0;
}
int strfnd(char* str, char* chain, bool backward, bool at_end, uint skip){
	int tmp = 0;
	int str_len = strlen(str), chain_len = strlen(chain);

	if (strlen(str) == 0){return -1;}

	switch(backward){
		case 1:
			for (int i = str_len-1; i > 0; i--){

				if(str[i] == chain[0]){
					for (int j = 0; j < chain_len; j++){

						if(str[i+j] == chain[j]){
							tmp++;
						}else{
							j = chain_len;
							tmp = 0;
						}
						if (j == chain_len-1 && tmp == chain_len){
							if(skip > 0){
								skip--;
							}else{
								if(at_end){
									return i + strlen(chain);
								}else{
									return i;
								}
							}
						}
					}
				}
			}
			break;

		case 0:
			for (int i = 0; i < str_len; i ++){

				if(str[i] == chain[0]){
					for (int j = 0; j < chain_len; j++){

						if(str[i+j] == chain[j]){
							tmp++;
						}else{
							j = chain_len;
							tmp = 0;
						}
						if (j == chain_len-1 && tmp == chain_len){
							if(skip > 0){
								skip--;
							}else{
								if(at_end){
									return i + strlen(chain);
								}else{
									return i;
								}
							}
						}
					}
				}
			}
			break;
	}

	return -1;
}
int chrfnd(char* str, char* chars, bool backward, bool at_end, uint skip)
{
	int tmp = 0;
	int inicio = -1, final = -1;
	
	
	int str_len = strlen(str), chars_len = strlen(chars);

	if (strlen(str) == 0){return -1;}

	switch(backward){
		case 1:
			for (int i = str_len-1; i >= 0; i --)
			{
				tmp = 0;
				for (int j = 0; j < chars_len; j++)
				{
					if (str[i]==chars[j])
					{
						if (final < 0){ final = i+1;}
						tmp = 1;
						break;
					}
				}
				if (tmp == 0 && final != -1)
				{
					inicio = i+1;
					if (skip > 0){skip --; final=-1; inicio=-1;}
					else{
						return (at_end == true ? final : inicio);
					}
				}
			}
			if ( final != -1 && inicio == -1)
			{
				if (skip > 0){skip --;}
				else{
					return (at_end == true ? final : 0);
				}
			}
			break;
		case 0:
			for (int i = 0; i < str_len; i ++)
			{
				tmp = 0;
				for (int j = 0; j < chars_len; j++)
				{
					if (str[i]==chars[j])
					{
						if (inicio < 0) { inicio = i; }
						tmp = 1;
						break;
					}
				}
				if (tmp == 0 && inicio != -1)
				{
					final = i;
					if (skip > 0){skip --; inicio=-1; final=-1;}
					else{
						return (at_end == true ? final : inicio);
					}
				}
			}
			if (inicio != -1 && final == -1)
			{
				return (at_end == true ? str_len : inicio);
			}
			break;
	}

	return -1;
}
int dtoi(double d){

	double tmp = d;
		int r = 0;

	if ( d > INT_MAX){r = INT_MAX; return r;}
	if ( d < INT_MIN){r = INT_MIN; return r;}

	r = int(tmp);
	tmp = tmp - double(r);
	if (tmp >= 0.500000){ r++;}
	if (tmp <= -0.500000 ){ r--;}

	return r;
}

int maxnumbydigits(int cnt){
	if ( !(cnt > 0) ){return 0;}

	int ret = 9;
		for(int i = 1; i < cnt; i++){
			ret += 9 * pow(10, i);
		}

	return ret;
}
int ctoi (char s){
int num;
switch (s){
	case '0':
		num = 0;
		return num;
		break;
	case '1':
		num = 1;
		return num;
		break;
	case '2':
		num = 2;
		return num;
		break;
	case '3':
		num = 3;
		return num;
		break;
	case '4':
		num = 4;
		return num;
		break;
	case '5':
		num = 5;
		return num;
		break;
	case '6':
		num = 6;
		return num;
		break;
	case '7':
		num = 7;
		return num;
		break;
	case '8':
		num = 8;
		return num;
		break;
	case '9':
		num = 9;
		return num;
		break;
	default:
		return -1;
	}
}
char* GetSystemOutput(char* cmd){
	int tries = 0;
	int buff_size = 32;
    char* buff = new_char(buff_size);
	char* ret = NULL;
	string str = "";

    int fd[2];// rc = pipe(fd);

	//flushSTDs();
	int pid = fork();

	switch(pid){
		case 0:
			close(fd[0]);
			close(STDOUT_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			exit(system(cmd));
			break;
		case -1:
			printf("GetSystemOutput(): Error, fork() returned -1\n");
			switch(errno){
				case EAGAIN:
					printf("errno = %i / rc = -1\n", errno);
					printf("fd is not a valid file descriptor or is not open for reading.\n");
					break;
				case ENOMEM:
					printf("errno = %i / rc = -1\n", errno);
					printf("fork() failed to allocate the necessary kernel structures because memory is tight.\n");
					break;

			}
			exit(1);
		default:
			close(fd[1]);

			for (int rc = 1; rc > 0;){
				pEAGAIN:
				rc = read(fd[0], buff, buff_size);

				if ( ( errno == EAGAIN || errno == EIO ) && rc < 1 && tries < 5){
					tries++; usleep(0.1*1000*1000); goto pEAGAIN;}

				if (errno > 0  || rc < 0) {
					switch(errno){
						case EBADF:
							printf("GetSystemOutput(): Error, errno = %i / rc = %i\n", errno, rc); errno = 0;
							printf("fd is not a valid file descriptor or is not open for reading.\n");
							//exit(errno);
							break;
						case EFAULT:
							printf("GetSystemOutput(): Error, errno = %i / rc = %i\n", errno, rc); errno = 0;
							printf("buf is outside your accessible address space.\n");
							//exit(errno);
							break;
						case EINTR:
							printf("GetSystemOutput(): Error, errno = %i / rc = %i\n", errno, rc); errno = 0;
							printf("The call was interrupted by a signal before any data was read.\n");
							//exit(errno);
							break;
						case EINVAL:
							printf("GetSystemOutput(): Error, errno = %i / rc = %i\n", errno, rc); errno = 0;
							printf("fd is attached to an object which is unsuitable for reading; or the file was opened with the O_DIRECT flag, and either the address specified in buf, the value specified in count, or the current file offset is not suitably aligned. \n");
							//exit(errno);
							break;
						case EISDIR:
							printf("GetSystemOutput(): Error, errno = %i / rc = %i\n", errno, rc); errno = 0;
							printf("fd refers to a directory.\n");
							//exit(errno);
							break;
						default:
							break;
					}
				}
					//rc = 0;//exit(1);}
				str.append(buff, rc);
			}

			ret = new_char (strlen((char*)str.c_str()));

			strcpy(ret, (char*)str.c_str());


			close(fd[0]);
	}
	waitpid(pid, NULL, 0);
	delete [] buff;

    return ret;
}

void forker(char* cmd, bool wait){
	char* cmdline = NULL;

	int aaa = fork();
	switch(aaa){
		case -1:
			printf("forker(char*): Error, fork() returned %i, errono %i", aaa, errno);
			exit(errno);
		case  0:

//			FILE* rc = 0;
//			rc = freopen ("/dev/null","wa",stdout);
//				if(!rc){printf("forker(): error redirecting stdout to /dev/null\n");}
//			rc = freopen ("/dev/null","wa",stderr);
//				if(!rc){printf("forker(): error redirecting stderr to /dev/null\n");}
//			rc = freopen ("/dev/null","r",stdin);
//				if(!rc){printf("forker(): error redirecting stdin to /dev/null\n");}
			int bbb = fork();
			switch(bbb){
				case -1:
					printf("forker(char*): Error, fork() returned %i, errono %i", aaa, errno);
					exit(errno);
				case  0:
				execvp (cmd, &cmdline);
			}
			//printf("forker(char*): Error, fork() returned %i, errono %i", aaa, errno);
			//system(cmd);
			exit(aaa);
	}
//	if (wait) {
		waitpid(aaa, NULL, 0);
		//close(fd);
//		}
	return;
}
void flushSTDs(){
	fflush( stdin );
	fflush( stdout );
	fflush( stderr );
}
int high(int num1, int num2){
	if(num1 >= num2){return num1;}else{return num2;}
}
int low(int num1, int num2){
	if(num1 <= num2){return num1;}else{return num2;}
}

void GenRandomKey(char *s, const uint len, const char* char_set, const uint char_set_len) {
	static int y = 0;
	uint csl = char_set_len;

	if (!csl) csl = strlen(char_set);

	if (y==0){y = 1; srand(GetTicks());}

	for (uint i = 0; i < len; i++) {
		s[i] = char_set[rand() % (csl)];
	}
}

char* new_char (unsigned long long size){
	char* temp = new char [size +1];
	memset (temp, 0, size+1);
	return temp;
}
uchar* new_uchar (unsigned long long size){
	uchar* temp = new uchar [size +1];
	memset (temp, 0, size+1);
	return temp;
}
char** new_char2D (unsigned long long x, unsigned long long y){
	char** temp = new char* [x];
	for(uint i = 0; i < x; i++){
		temp[i] =new char[y+1];
		memset(temp[i], 0, y+1);
	}
	return temp;
}
void delete_char2D (char** &ptr,unsigned long long x){
	for(uint i = 0; i < x; i++){
		delete [] ptr[i];
	}
	delete [] ptr; ptr = NULL;
}
char*** new_char3D (unsigned long long x, unsigned long long y, unsigned long long z){
	char*** temp = new char** [x];
	for(uint i = 0; i < x; i++){
		temp[i] = new char* [y];
		for(uint j = 0; j < y; j++){
			temp[i][j] = new char[z+1];
			memset(temp[i][j], 0, z+1);
		}
	}
	return temp;
}
void delete_char3D (char*** &ptr,unsigned long long x, unsigned long long y){
	for(uint i = 0; i < x; i++){
		for(uint j = 0; j < y; j++){
			delete [] ptr[i][j];
		}
		delete [] ptr[i];
	}
	delete [] ptr; ptr = NULL;
}
int* new_int (unsigned long long size){
	int* temp = new int [size];
	memset (temp, 0, size*sizeof(int) );
	return temp;
}
int** new_int2D (unsigned long long x, unsigned long long y){
	int** temp = new int* [x];
	for(uint i = 0; i < x; i++){
		temp[i] =new int[y];
		memset(temp[i], 0, y*sizeof(int));
	}
	return temp;
}
void delete_int2D (int** &ptn, unsigned long long x){
	for(uint i = 0; i < x; i++){
		delete [] ptn[i];
	}
	delete [] ptn; ptn = NULL;
}
uint* new_uint (unsigned long long size){
	uint* temp = new uint [size];
	memset (temp, 0, size*sizeof(uint) );
	return temp;
}
uint** new_uint2D (unsigned long long x, unsigned long long y){
	uint** temp = new uint* [x];
	for(uint i = 0; i < x; i++){
		temp[i] =new uint[y];
		memset(temp[i], 0, y*sizeof(uint));
	}
	return temp;
}
void delete_uint2D (uint** &ptn, unsigned long long x){
	for(uint i = 0; i < x; i++){
		delete [] ptn[i];
	}
	delete [] ptn; ptn = NULL;
}

/* ************* */
/* Class average */
/* ************* */
void average::add(double num)
{
		if (count>=max && random){
			numbers[rand()%max] = num;
		}else{
		numbers[current] = num;
		}
		if(++current > max-1){current=0;}
		if( !(count >= max) ){count++;}
		avg=0;
		davg=0;
		for (Uint32 i = 0; i < count; i++){
			//avg += numbers[i];
			davg += numbers[i];
		}

		davg = davg / double(count);
		avg = round(davg);

	}
average::average (Uint32 cnt, bool feel, double with, bool randomize)
{
	numbers = new double [cnt];
	current = 0;
	count = 0;
	max = cnt;
	avg = 0;
	davg = 0;
	fill = feel;
	if (fill){for(Uint32 i = 0; i < max;i++){add(with);}}
	random = randomize;
}
average::~average()
{
	delete numbers;
}
/* ************* */

class DirPath{
  private:
	char lmt [3]; //Limitantes \ y /
	//bool UseSlashAtEnd;	//defaults to false '\000'
	//bool UseSlashAtBegining;
	char* CurPath;
	char* temp;		//siempre hay q dejarla liberada
  public:
	int Address_len;
	int Name_len;
	char* q_barra;


  public:
	DirPath(char* Address){				//Constructor
		strcpy((char*)&lmt, "\\/");						// Copya \ y / a lmt[]

		/*
		if (Address[0]==lmt[0] || Address[0]==lmt[1]){	//Comprueba si Address empiesa con alguna barra
		UseSlashAtBegining = true;
		}else{UseSlashAtBegining = false;}

		if(Address[strlen(Address)-1]==lmt[0] || Address[strlen(Address)-1]==lmt[1]){	//comprueba si Address termina en alguna barra
		UseSlashAtEnd = true;
		}else{UseSlashAtEnd = false;}
		UseSlashAtEnd = false;
		*/

		CurPath = Address_TrimSlashes(Address);			//CurPath es Address filtrado de las barras terminantes
		Address_len = strlen(CurPath);					//Longitud de CurPath

		Name_len = 0;									//Longitud de Name para ChangeDir()
		#ifdef __linux__						//variable segun el OS en el q se compile
		q_barra = (char*)&"/\0";
		#else
		q_barra = (char*)&"\\\0";
		#endif

		}
	~DirPath(){							//Destructor
	free(CurPath);
		}

	void ChangeDir (char* Name){	//Cambia de directorio basado en una direccion en char[], Depende de isLegible
		Name_len = strlen(Name);

		/*
		**	En caso de q sea ".." vuelve atras un direcctorio
		*/
		if (strcmp(Name, "..")==0){
			if (Address_len==0){return;}
			int a = 0;	//coreccion por si empiesa con alguna barrra y se hace .. q quede la barra en ves de vacio
			for (int i=Address_len -1; i > -1; i--){
				//cout << CurPath[i] << "\t" << (CurPath[i] == lmt[0]) << "\t" << (CurPath[i] == lmt[1]) << endl;

				if(((CurPath[i] == lmt[0] || CurPath[i] == lmt[1]) || i == 0) && i!=Address_len -1 ){
					if (((CurPath[i] == lmt[0] || CurPath[i] == lmt[1]) && i == 0) /*|| UseSlashAtEnd*/){		//si la barra esta en el principio Y i==0 ..
					a=1;
					temp = (char*)malloc(i+a+1); memset(temp,0,i+a+1);
					memcpy (temp, CurPath, i+a);
					free (CurPath);
					}else{																//sino...
					temp = (char*)malloc(i+a+1); memset(temp,0,i+a+1);
					memcpy (temp, CurPath, i);
					free (CurPath);
					}

					CurPath = (char*)malloc(i+a+1); memset(CurPath,0,i+a+1);
					strcpy (CurPath,temp);
					free (temp);

					i=0;
					Address_len = strlen(CurPath);
				}
			}
		}

		/*
		**	Si "." no hace nada
		*/
		else if(strcmp(Name, ".")==0){return;}

		/*
		**	Para nombre comun siempre y cuando sea legible
		*/
		else if(isLegible(Name)){
			char* Name2 = Address_TrimSlashes(Name);
			Name_len = strlen(Name2);
				bool barra = true;
				int a = 2;

			if (Address_len==0 || (CurPath[Address_len-1] == lmt[0] || CurPath[Address_len-1] == lmt[1]) || (Name2[0] == lmt[0] || Name2[0] == lmt[1])){
				barra = false;a=1;}

			temp = (char*)malloc(Address_len+Name_len+a); memset(temp, 0, Address_len+Name_len+a);
			strcpy (temp, CurPath);
			if(barra){strcat (temp, q_barra);}
			strcat (temp, Name2);
			free (CurPath);

			CurPath = (char*)malloc(Address_len+Name_len+a); memset(CurPath, 0, Address_len+Name_len+a);
			strcpy (CurPath,temp);
			free (temp);

			Address_len = strlen(CurPath);
		}
	}

	char* GetPath(){
		return CurPath;
	}

};//Fin de DirPath

// class FPS_Limiter{
void FPS_Limiter::Change_FPS_Wait(double fps_in,Uint32 fps_prec){delete ms_avg; init(fps_in, fps_prec);}
FPS_Limiter::FPS_Limiter(double fps_in,Uint32 fps_prec){init(fps_in, fps_prec);}
FPS_Limiter::~FPS_Limiter(){delete ms_avg;}
void FPS_Limiter::init(double fps_in,Uint32 fps_prec){
	ms = 1000.0/fps_in;fps = fps_in;

	starttick = GetTicks();
	nexttick = tmp = frames = 0;

	int i = fps*fps_prec; if(i < 15){i = 15;}
	ms_avg = new average(i,true,ms,false);
	lasttick = starttick - ms;
}
void FPS_Limiter::Wait_Next(){
	frames++;
	tmp = GetTicks();
	ms_avg->add(tmp - lasttick);
	lasttick = tmp;

	nexttick = (starttick+(frames*ms)) - tmp;

	if ( nexttick > 0 ){ usleep (int(nexttick)*1000);}
	else{ starttick+=-int(nexttick);}
}
double FPS_Limiter::GetAvgFPS(){ return 1000/ms_avg->davg;}
//////////////////////////////////////

class ByteBuffer{
	private:
		size_t buffer_size;
		size_t buffer_read_pointer_position;
		size_t buffer_write_pointer_position;

		uchar *buffer;
		uchar *tmp_buffer;

	public:
		ByteBuffer(size_t size){
			buffer = new uchar[size];
				memset(buffer, 0, size);
			tmp_buffer = new uchar[size];
				memset(tmp_buffer, 0, size);

			buffer_size = size;
			buffer_read_pointer_position = 0;
			buffer_write_pointer_position = 0;
		}
		~ByteBuffer(){delete [] buffer;}

		int Write(void* inbuf, size_t len){
//			size_t point = 0;
//			size_t imp = 0;
//
//			uchar* p = (uchar*)inbuf;
//

			return 0;
		}

};

int GetFileCnt(char* path)
{
	int rc = -1;
	int i = 0;

	char* tmp_path = new char [strlen(path) + 1000];

	struct stat filestats;	struct dirent *dp;
	DIR *dir = opendir(path);
		if (!dir){ printf("Error, can't open %s\n", path); return rc;}

	while ((dp=readdir(dir)) != NULL) {
		strcpy(tmp_path, path);
			if (tmp_path[strlen(tmp_path)-1] != '/') strcat(tmp_path, "/");
			strcat(tmp_path, dp->d_name);

		lstat(tmp_path, &filestats);
		if( S_ISREG(filestats.st_mode) && strcmp(dp->d_name, "..") && strcmp(dp->d_name, ".") ){
			i++;}


	}closedir(dir);

	delete [] tmp_path;
	rc = i;

	return rc;
}

int ping (char* url)
{
	int rc;
	char* aaa = new char [1000];

	strcpy (aaa, "ping -c 1 -q ");
	strcat (aaa, url);
	strcat (aaa,  " > /dev/null");

	rc = system (aaa);
	delete [] aaa;

	return rc;
}

/* ********************************************************************** */
/* ************************* == DEBUG == ******************************** */
/* ********************************************************************** */
namespace debug{

/////////////////////////////////////////////////////
FPS_Counter::FPS_Counter(Uint32 presicion){
	avg1 = new average(presicion);
	now = last = GetTicks();
}
FPS_Counter::~FPS_Counter(){delete avg1;}
void FPS_Counter::Count(){
	now = GetTicks();
	avg1->add(now - last);
	printf("now: %u | last: %u | diff: %u | DiffAvg: %f | FPS: %f\n", now, last , now-last, avg1->davg, 1000.0/avg1->davg);
	last = now;
}
void FPS_Counter::Count_lite(){
	now = GetTicks();
	avg1->add(now - last);
	printf("FPS: %f\n", 1000.0/avg1->davg);
	last = now;
}
/////////////////////////////////////////////////////

void DumpMem (void* Addr, int pre, int post, int mark, int jump){	//Addr= (char*) a la direccion, len= mostrar post-Addr, pre= mostrar pre-Addr,
																	//mark= longitud de la variable para resaltar esa seccion, jump= cada cuantos bytes el salto de linea
	cout << "\nDumping from " << (hex) << (uint)(char*)Addr << " to " << (uint)(char*)Addr + mark <<  " - " << (dec) << mark << " Bytes" <<  " - " << mark*8 << " Bits" << endl << (hex);
	bool a = 0;
	bool b = 0;
	int offset;	//if(pre<8){offset=pre+8;}else{offset=pre;}
		offset=pre;

	for (int i = 0; i < post + mark + offset; i++)
		{
		if(!a){if(i >= offset){cout << "\x1b[1m";a++;}}
		if(!b){if(i >= mark +offset){cout<<"\x1b[m";b++;}}
		if (i != 0 && i%jump==0){cout<<endl;}
		
		gotox( ((i%jump)*4)+(i%jump/4)*1 );
		
		uchar uc;
		memcpy((uchar*)&uc, (char*)Addr+(i-offset),1);
		if ((uint)uc < 16){cout << "0";}
		cout << (uint)uc ;
		}
	cout << (dec) << endl;
	cout<<"\x1b[m";
}
void DumpMemASCII (void* Addr, int pre, int post, int mark, int jump){	//Addr= (char*) a la direccion, len= mostrar post-Addr, pre= mostrar pre-Addr,
																	//mark= longitud de la variable para resaltar esa seccion, jump= cada cuantos bytes el salto de linea
	cout << "\nDumping from " << (hex) << (uint)(char*)Addr << " to " << (uint)(char*)Addr + mark <<  " - " << (dec) << mark << " Bytes" <<  " - " << mark*8 << " Bits" << endl << (hex);
	bool a = 0;
	bool b = 0;
	int offset;	//if(pre<8){offset=pre+8;}else{offset=pre;}
		offset=pre;

	for (int i = 0; i < post + mark + offset; i++){
		if(!a){if(i >= offset){cout << "\x1b[1m";a++;}}
		if(!b){if(i >= mark +offset){cout<<"\x1b[m";b++;}}
		if (i != 0 && i%jump==0){cout<<endl;}
		
		gotox( ((i%jump)*4)+(i%jump/4)*1 );

		uchar uc;
		memcpy((uchar*)&uc, (char*)Addr+(i-offset),1);

		cout << (char)uc ;

			}
	cout << (dec) << endl;
	cout<<"\x1b[m";
}
void DumpMemToDisk(char* path, char* data, unsigned int size){
	ofstream outfile( path, ios::binary);
	outfile.write (data, size);
	outfile.flush();
	outfile.close();
}

}
