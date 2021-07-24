#pragma once
#ifndef _CTYPE_H_
#define _CTYPE_H_

/** @file
 * @brief C Types
 * 
 */

/**
 * @brief Check if character is alphanumeric
 * 
 * @param c 
 * @return int 
 */
int isalnum(int c);

/**
 * @brief Check if character is alphabetical
 * 
 * @param c 
 * @return int 
 */
int isalpha(int c);

/**
 * @brief Check if character is lowercase
 * 
 * @param c 
 * @return int 
 */
int islower(int c);

/**
 * @brief Check if character is uppercase
 * 
 * @param c 
 * @return int 
 */
int isupper(int c);

/**
 * @brief Check if character is a number
 * 
 * @param c 
 * @return int 
 */
int isdigit(int c);

/**
 * @brief Check if character is a valid hex number
 * 
 * @param c 
 * @return int 
 */
int isxdigit(int c);

/**
 * @brief Check if character is a control code
 * 
 * @param c 
 * @return int 
 */
int iscntrl(int c);

/**
 * @brief Check if character is a space
 * 
 * @param c 
 * @return int 
 */
int isspace(int c);

/**
 * @brief Check if character is blank
 * 
 * @param c 
 * @return int 
 */
int isblank(int c);

/**
 * @brief Check if character is printable
 * 
 * @param c 
 * @return int 
 */
int isprint(int c);

/**
 * @brief Check if character is graphical
 * 
 * @param c 
 * @return int 
 */
int isgraph(int c);

/**
 * @brief Check if character is punctuation
 * 
 * @param c 
 * @return int 
 */
int ispunct(int c);

/**
 * @brief Change character to uppercase
 * 
 * @param c 
 * @return int 
 */
int toupper(int c);

/**
 * @brief Change character to lowercase
 * 
 * @param c 
 * @return int 
 */
int tolower(int c);

#endif // _CTYPE_H_
