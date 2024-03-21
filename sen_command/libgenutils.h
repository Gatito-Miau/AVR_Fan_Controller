/* *************************************** */
/* Copyright © Dario Napole 2011, GPLv3+   */
/* *************************************** */

#ifndef GEN_FUNCTIONS_H
#define GEN_FUNCTIONS_H
#include <fstream>

typedef unsigned int 		Uint32;
typedef unsigned long long 	ullong;
typedef unsigned int 		uint;
typedef unsigned char 		uchar;
typedef const char 			cchar;

using namespace std;

const char alphanum [] =
    "_ABCDEFGHIJKLMNOPKRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "1234567890";

// Manipulacion de arrays
int     findchar	(char*, char, int = 0);
char*   new_char	(ullong);				// Crea un array de chars, inicializados a \0 y con un bytes \0 extra para evitar confuciones o "+1" en los tamaños
uchar*  new_uchar	(ullong);
char**  new_char2D	(ullong, ullong);
void delete_char2D	(char** &,ullong);
char*** new_char3D	(ullong, ullong, ullong);
void delete_char3D	(char*** &,ullong, ullong);
int*    new_int		(ullong);
int**   new_int2D	(ullong, ullong);
void delete_int2D	(int** &, ullong);
uint*   new_uint	(ullong);
uint**  new_uint2D	(ullong, ullong);
void delete_uint2D	(uint** &, ullong);
void strchrnk		(char* &);
void ResizeNewUCharPointer(uchar* &, uint, uint);


// Strings
bool CharIsFromGroup(char, char*);
bool isLegible (char*, int = -1);	//comprueba es legible segun alphanum[], overload con longitud del string
char* Fix_C_Name(char*);
void strtoup(char*);							// String to UpperCase
int strcnt(char* str, char* chain);						// Count the ammount of repetitions of a certain string
int strfnd(char* str, char* chain, bool backward = false, bool at_end = false, uint skip = 0);
int chrfnd(char* str, char* chars, bool backward = false, bool at_end = false, uint skip = 0);
int ctoi (char);
void GenRandomKey(char *s, const uint len, const char* char_set, const uint char_set_len = 0);


// Memoria
void shift_adress(void* ptr, int val, int size, bool zero = false)__attribute__ ((deprecated));
void memshft(void* ptr, int val, int size, bool zero = false);
bool getbit	(void* val, int size, int bit);


// Ejecucion
void forker(char*, bool = true);
char* GetSystemOutput(char*);


// Buffers
class ByteBuffer;  // Incompleta


// Direcciones y URLs
char* Address_GetName (char*);
char* Address_GetExt (char*);
char* Address_TrimSlashes (char*);	//si termina con lmt[] los remueve y devuelve un char* corregido
void ceroalaizq (uint, uint, char*);
class DirPath;


// Matematica
bool IsNumeric(char* str, unsigned int len = 0);
double dint (double);
double decimals (double);
int dtoi(double);
int maxnumbydigits(int );
int high(int, int);
int low(int, int);

class average // Genera un promedio X de Y cantidad de valores
{
private:
	double *numbers;
	Uint32 count, max, current;
	bool fill, random;
public:
	Uint32 avg;
	double davg;

	void add(double num);
	average (Uint32 cnt, bool feel = false, double with = 0, bool randomize = false);
	~average();
};

// Internet
int ping (char* url);


// Consola
void gotoxy(int, int);
void gotox(int);
void flushSTDs();


// Archivos
int GetFileCnt(char* path);
streamsize GetFileSize (ifstream*); //devuelve el tamaño de un ifstream*
streamsize GetFileSize (char*); //devuelve el tamaño de un archivo
bool FileExists (char*);


// Tiempo
#define GEN_GetTicks() GetTicks()
uint GetTicks();                    // Tiempo en ms
double GetTicks_usec();             // Tiempo en µs
#define gen_fps_wait FPS_Limiter
class FPS_Limiter
{
	private:
		average *ms_avg;
		Uint32 	starttick, lasttick, frames, tmp;
		double nexttick;
	public:
		double 	ms, fps;

	void Change_FPS_Wait(double fps_in,Uint32 fps_prec=1);
	FPS_Limiter(double fps_in = 60,Uint32 fps_prec = 1);
	~FPS_Limiter();
	void init(double fps_in,Uint32 fps_prec);
	void Wait_Next();
	double GetAvgFPS();
};


// Depuración
namespace debug{
class FPS_Counter{
		public:
		average *avg1;
		Uint32 last;
		Uint32 now;
		FPS_Counter(Uint32 presicion);
		~FPS_Counter();

		void Count();
		void Count_lite();
	};
	void DumpMem (void* Addr, int pre, int post, int mark, int jump);
	void DumpMemASCII (void* Addr, int pre, int post, int mark, int jump);
	void DumpMemToDisk(char* path, char* data, unsigned int size);
}
#endif
