#pragma once

#ifndef VALKORIA_CORE_H
#define VALKORIA_CORE_H

#include <ANSIColor.h>
#include <valkoria/db.h>
#include <valkoria/lib.h>
#include <stddef.h>

void show_logo(void);

void show_menu(void);

int deposit(const char *account_id, double amount, BankDB *bankDB);

int withdraw(const char *account_id, double amount, BankDB *bankDB);

int create_account(const char *account_name, BankDB *bankDB);

int close_account(const char *account_id, BankDB *bankDB);

int create_transaction(const char *from_account_id, const char *to_account_id, double amount, const char *message, BankDB *bankDB);

int get_choice(const char *prompt);

int get_account_id(const char *prompt, char *buffer, size_t buffer_size);

int get_account_name(const char *prompt, char *buffer, size_t buffer_size);

double get_amount(const char *prompt);

typedef struct Core
{
	void (*print_logo)(void);
	void (*print_menu)(void);
	int (*deposit)(const char *account_id, double amount, BankDB *bankDB);
	int (*withdraw)(const char *account_id, double amount, BankDB *bankDB);
	int (*create_account)(const char *account_name, BankDB *bankDB);
	int (*close_account)(const char *account_id, BankDB *bankDB);
	int (*get_choice)(const char *prompt);
	int (*get_account_id)(const char *prompt, char *buffer, size_t buffer_size);
	int (*get_account_name)(const char *prompt, char *buffer, size_t buffer_size);
	double (*get_amount)(const char *prompt);
} ClassCore;

// Global instance of Core
extern ClassCore Core;

#endif // VALKORIA_CORE_H
