#pragma once

/**************************************************
 **                 VALKORIA LIB                 **
 *************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <valkoria/type.h>

#ifndef VALKORIA_LIB_H
#define VALKORIA_LIB_H

/////////////////////////////////////////
///////////  File Operations  ///////////
/////////////////////////////////////////

/**
 * @brief Read file
 * @param filename: file name or path to file
 * @param buffer: buffer
 * @return 0 or 1
 */
int read_file(const char *filename, char *buffer, size_t buffer_size);

/**
 * @brief Get file size
 * @param filename: file name or path to file
 * @param fsize: file size pointer
 * @return 0 or 1
 */
int get_file_size(const char *filename, long *fsize);

/////////////////////////////////////////
//////////  Console Operations  /////////
/////////////////////////////////////////

int move_cursor(int x, int y);
int clear_line(void);
int clear_from(int line);
int clear_screen(void);

/**
 * @brief Console Class
 */
typedef struct Console
{
	int (*move_cursor)(int x, int y);
	int (*clear_line)(void);
	int (*clear_from)(int line);
	int (*clear)(void);
} ClassConsole;

// Global instance of Console
extern ClassConsole Console;

/**
 * @brief File Operations Class
 */
typedef struct FileProcessor
{
	int (*read)(const char *filename, char *buffer, size_t buffer_size);
	int (*write)(const char *filename, const char *data, size_t data_size);
	int (*getsize)(const char *filename, long *fsize);
} ClassFile;

// Global instance of File operations
extern ClassFile File;

/******************************************************************************
 *                             Utility Operations                             *
 ******************************************************************************/

char *generate_id(size_t length);

/**
 * @brief Utility Functions Class
 */
typedef struct Utility
{
	char *(*generate_id)(size_t length);
} ClassUtils;

// Global instance of Utils
extern ClassUtils Utils;

#endif // !VALKORIA_LIB_H
