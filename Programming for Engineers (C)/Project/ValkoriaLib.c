#pragma warning(disable : 4996)

#include <valkoria/lib.h>
#include <conio.h>
#include <stdio.h>

// NOTE: For function documentation, see ValkoriaLib.h

int read_file(const char *filename, char *buffer, size_t buffer_size)
{
	FILE *file = fopen(filename, "rb");

	if (file == NULL)
		return -1;

	size_t bytes = fread(buffer, 1, buffer_size - 1, file);

	buffer[bytes] = '\0';

	fclose(file);

	return 0;
}

int get_file_size(const char *filename, long *fsize)
{
	FILE *file = fopen(filename, "rb");

	if (!file)
		return -1;

	fseek(file, 0, SEEK_END);

	*fsize = ftell(file);

	rewind(file);
	fclose(file);

	return 0;
}

int move_cursor(int x, int y)
{
	printf("\033[%d;%dH", y, x);
	return 0;
}

int clear_line(void)
{
	printf("\r\033[2K");
	return 0;
}

int clear_from(int line)
{
	printf("\033[%d;1H\033[J", line);
	return 0;
}

int clear_screen(void)
{
	printf("\033[2J\033[1;1H");
	return 0;
}

char *generate_id(size_t length)
{
	char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	size_t charset_size = strlen(charset);

	char *id = (char *)malloc(length + 1);

	if (length < 1)
	{
		return NULL;
	}

	for (size_t i = 0; i < length; i++)
	{
		size_t index = rand() % charset_size;
		id[i] = charset[index];
	}

	id[length] = '\0';

	return id;
}

ClassFile File = {
		.read = read_file,
		.getsize = get_file_size,
};

ClassConsole Console = {
		.move_cursor = move_cursor,
		.clear_line = clear_line,
		.clear_from = clear_from,
		.clear = clear_screen,
};

ClassUtils Utils = {
		.generate_id = generate_id,
};
