#import <Foundation/Foundation.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <zlib.h>
#include <stdarg.h>
#include <png.h>


#define foreach(A) id a = A; id object, e = [a objectEnumerator]; while ((object = [e nextObject]))


typedef unsigned int uint32;
typedef struct png_chunk_t {
	uint32 length;
	unsigned char *name;
	unsigned char *data;
	uint32 crc;
} png_chunk;


void read_chunks(unsigned char *);
void process_chunks(void);
void write_png(const char *);
unsigned long mycrc(unsigned char *, unsigned char *, int);


void read_png_file(char* file_name);
void process_file();
void write_png_file(char* file_name);