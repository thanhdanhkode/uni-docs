#pragma once

#ifndef VALKORIA_LOGGER_H
#define VALKORIA_LOGGER_H

/**************************************************
 **               VALKORIA LOGGER                **
 *************************************************/

typedef enum
{
	LOG_LEVEL_TRACE,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR
} LogLevel;

#define LOG_INFO(fmt, ...) logger_log(LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...) logger_log(LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) logger_log(LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)

// NOTE: Don't name this function to 'log' to avoid conflict with standard library
void logger_log(LogLevel level, const char *fmt, ...);

typedef struct Logger
{
	/// @brief Log message to console. See in ValkoriaLogger.h
	void (*log)(LogLevel level, const char *fmt, ...);
} ClassLogger;

// Global instance of Logger
extern ClassLogger Logger;

#endif // !VALKORIA_LOGGER_H
