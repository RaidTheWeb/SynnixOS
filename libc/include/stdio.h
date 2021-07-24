#pragma once
#ifndef _STDIO_H_
#define _STDIO_H_

#include <basic.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/types.h>

#define BUFSIZ 0x1000
#define _IONBF 1
#define _IOLBF 2
#define _IOFBF 3

#define L_tmpnam 50

/** @file
 * @brief Standard Input/Output 
 * 
 */

/**
 * @brief File types
 * 
 */
enum file_type {
    FT_CHARDEV,
    FT_TTY,
    FT_BUFFER,
    FT_SOCKET,
    FT_DIRECTORY,
    FT_PIPE,
    FT_PROC,
    FT_PROC_THREAD,
};

/**
 * @brief File modes
 * 
 */
enum file_mode {
    ALL_READ = 0004,
    ALL_WRITE = 0002,
    ALL_EXEC = 0001,
    GRP_READ = 0040,
    GRP_WRITE = 0020,
    GRP_EXEC = 0010,
    USR_READ = 0400,
    USR_WRITE = 0200,
    USR_EXEC = 0100,

    SUID = 01000,
    SGID = 02000,
};

/**
 * @brief Seek modes
 * 
 */
enum seek_modes {
    SEEK_SET,
    SEEK_CUR,
    SEEK_END,
};

/**
 * @brief Max filename length
 * 
 */
#define MAX_FILENAME 64

#ifndef __kernel__

/**
 * @brief End Of File macro
 * 
 */
#define EOF (-1)

/**
 * @brief _FILE struct
 * 
 */
struct _FILE;

/**
 * @brief Create typedef to common FILE pointer
 * 
 */
typedef struct _FILE FILE;

/**
 * @brief Standard Input
 * 
 */
extern FILE *stdin;

/**
 * @brief Standard Output
 * 
 */
extern FILE *stdout;

/**
 * @brief Standard Error
 * 
 */
extern FILE *stderr;
#endif

/**
 * @brief Print string to stdout including newline
 * 
 * @param str 
 * @return int 
 */
int puts(const char *str);

/**
 * @brief Write formatted data from variable argument list to sized buffer
 * 
 * @param buf 
 * @param len 
 * @param format 
 * @param args 
 * @return int 
 */
int vsnprintf(char *buf, size_t len, const char *format, va_list args);

/**
 * @brief Format to buffer using array
 * 
 * @param buf 
 * @param format 
 * @param args 
 * @return int 
 */
int vsprintf(char *buf, const char *format, va_list args);

/**
 * @brief Print formatted data from variable argument list to stdout
 * 
 * @param format 
 * @param args 
 * @return int 
 */
int vprintf(const char *format, va_list args);

/**
 * @brief Write formatted data to buffer
 * 
 * @param buf 
 * @param format 
 * @param ... 
 * @return int 
 */
int sprintf(char *buf, const char *format, ...);

/**
 * @brief Write formatted output to sized buffer
 * 
 * @param buf 
 * @param len 
 * @param format 
 * @param ... 
 * @return int 
 */
int snprintf(char *buf, size_t len, const char *format, ...);

/**
 * @brief Write formatted data to stdout
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int printf(const char *format, ...);

#ifndef __kernel__

/**
 * @brief Write formatted output to a file descriptor using list arguments
 * 
 * @param fd 
 * @param buf 
 * @param args 
 * @return int 
 */
int vdprintf(int fd, const char *buf, va_list args);

/**
 * @brief Print formatted string to file descriptor
 * 
 * @param fd 
 * @param format 
 * @param ... 
 * @return int 
 */
int dprintf(int fd, const char *format, ...);

/**
 * @brief Close file descriptor
 * 
 * @param fd 
 * @return int 
 */
int close(int fd);

/**
 * @brief Get character from stdin
 * 
 * @return int 
 */
int getchar(void);

/**
 * @brief Put character to stdout
 * 
 * @param c 
 * @return int 
 */
int putchar(int c);

/**
 * @brief Get character from stream
 * 
 * @param f 
 * @return int 
 */
int getc(FILE *f);

/**
 * @brief Get next character from stream add advances position
 * 
 * @param f 
 * @return int 
 */
int fgetc(FILE *f);

/**
 * @brief Unget character from stream
 * 
 * @param c 
 * @param f 
 * @return int 
 */
int ungetc(int c, FILE *f);

/**
 * @brief Put character to stream
 * 
 * @param c 
 * @param f 
 * @return int 
 */
int putc(int c, FILE *f);

/**
 * @brief Write character to stream and advance position
 * 
 * @param c 
 * @param f 
 * @return int 
 */
int fputc(int c, FILE *f);

/**
 * @brief Write string to stream
 * 
 * @param c 
 * @param f 
 * @return int 
 */
int fputs(const char *c, FILE *f);

/**
 * @brief Write all buffered data to stream
 * 
 * @param f 
 * @return int 
 */
int fflush(FILE *f);

/**
 * @brief Open file in mode
 * 
 * @param name 
 * @param mode 
 * @return FILE* 
 */
FILE *fopen(const char *name, const char *mode);

/**
 * @brief Reopen file in mode
 * 
 * @param name 
 * @param mode 
 * @param stream 
 * @return FILE* 
 */
FILE *freopen(const char *name, const char *mode, FILE *stream);

/**
 * @brief Print formatted string to file pointer via args list
 * 
 * @param file 
 * @param format 
 * @param args 
 * @return int 
 */
int vfprintf(FILE *file, const char *format, va_list args);
/**
 * @brief Print formatted string to FILE pointer
 * 
 * @param file 
 * @param format 
 * @param ... 
 * @return int 
 */
int fprintf(FILE *file, const char *format, ...);

/**
 * @brief Put string to stream
 * 
 * @param str 
 * @param stream 
 * @return int 
 */
int fputs(const char *str, FILE *stream);

/**
 * @brief Write string to file stream
 * 
 * @param s 
 * @param size 
 * @param len 
 * @param file 
 * @return int 
 */
int fwrite(const void *s, size_t size, size_t len, FILE *file);

/**
 * @brief Read string into buffer
 * 
 * @param s 
 * @param size 
 * @param len 
 * @param file 
 * @return size_t 
 */
size_t fread(void *s, size_t size, size_t len, FILE *file);

/**
 * @brief Get string of num charactes from stream and write buffer
 * 
 * @param str 
 * @param num 
 * @param stream 
 * @return char* 
 */
char *fgets(char *str, int num, FILE *stream);

/**
 * @brief Clear error indicators of stream
 * 
 * @param stream 
 */
void clearerr(FILE *stream);

/**
 * @brief Test file stream EOF
 * 
 * @param stream 
 * @return int 
 */
int feof(FILE *stream);

/**
 * @brief Check if error indicator of stream is set
 * 
 * @param stream 
 * @return int 
 */
int ferror(FILE *stream);

/**
 * @brief Get integer file descriptor
 * 
 * @param stream 
 * @return int 
 */
int fileno(FILE *stream);

/**
 * @brief Close file stream
 * 
 * @param stream 
 * @return int 
 */
int fclose(FILE *stream);

/**
 * @brief Get the c unlocked object
 * 
 * @param stream 
 * @return int 
 */
int getc_unlocked(FILE *stream);

/**
 * @brief Get the char unlocked object
 * 
 * @return int 
 */
int getchar_unlocked(void);

/**
 * @brief Put the char unlocked object into stream
 * 
 * @param c 
 * @param stream 
 * @return int 
 */
int putc_unlocked(int c, FILE *stream);

/**
 * @brief Put character unlocked into stdout
 * 
 * @param c 
 * @return int 
 */
int putchar_unlocked(int c);

/**
 * @brief Clear unlocked error indicators
 * 
 * @param stream 
 */
void clearerr_unlocked(FILE *stream);

/**
 * @brief Test EOF indicator from stream
 * 
 * @param stream 
 * @return int 
 */
int feof_unlocked(FILE *stream);
int ferror_unlocked(FILE *stream);
int fileno_unlocked(FILE *stream);
int fflush_unlocked(FILE *stream);
int fgetc_unlocked(FILE *stream);
int fputc_unlocked(int c, FILE *stream);
size_t fread_unlocked(void *ptr, size_t size, size_t n, FILE *stream);
size_t fwrite_unlocked(const void *ptr, size_t size, size_t n, FILE *stream);
char *fgets_unlocked(char *s, int n, FILE *stream);
int fputs_unlocked(const char *s, FILE *stream);

//TODO: #5 Below
FILE *popen(const char *command, const char *type);
int pclose(FILE *stream);
FILE *tmpfile(void);
char *tmpnam(char *s);
void flockfile(FILE *filehandle);
int ftrylockfile(FILE *filehandle);
void funlockfile(FILE *filehandle);
int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
int fseeko(FILE *stream, off_t offset, int whence);
off_t ftello(FILE *stream);
void setbuf(FILE *stream, char *buf);
void setbuffer(FILE *stream, char *buf, size_t size);
void setlinebuf(FILE *stream);
int setvbuf(FILE *stream, char *buf, int mode, size_t size);
int remove(const char *pathname);
int rename(const char *oldpath, const char *newpath);
int sscanf(const char *s, const char *format, ...);

#endif // ifndef __kernel__

#endif // _STDIO_H_
