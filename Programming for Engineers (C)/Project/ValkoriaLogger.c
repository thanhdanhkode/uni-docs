#include <ANSIColor.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include <valkoria/logger.h>

// NOTE: For function documentation, see ValkoriaLogger.h

static void vlog(FILE *fp, LogLevel level, const char *fmt, const char *file, va_list args)
{
	switch (level)
	{
	case LOG_LEVEL_INFO:
		fprintf(fp, FG_GREEN "[INFO]");
		break;
	case LOG_LEVEL_WARNING:
		fprintf(fp, FG_YELLOW "[WARNING]");
		break;
	case LOG_LEVEL_ERROR:
		fprintf(fp, FG_RED "[ERROR]");
		break;
	case LOG_LEVEL_TRACE:
	default:
		break;
	}
	vfprintf(fp, fmt, args);
	fprintf(stdout, RESET_COLOR);
}

void logger_log(LogLevel level, const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	vlog(stdout, level, fmt, NULL, args);
	fprintf(stdout, "\n");

	va_end(args);
}

ClassLogger Logger = {
		.log = logger_log,
};
