#pragma warning(disable : 4996)

#include <valkoria/core.h>
#include <extend/string.h>
#include <valkoria/logger.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 *                                  Deposit                                   *
 ******************************************************************************/

int deposit(const char *account_id, double amount, BankDB *bankDB)
{
	if (amount <= 0)
	{
		Logger.log(LOG_LEVEL_ERROR, " Invalid deposit amount: %.2f. Amount must be positive.\n", amount);
		return -1;
	}

	for (size_t i = 0; i < bankDB->num_account; i++)
	{
		if (streq(bankDB->accounts[i].id, account_id))
		{
			bankDB->accounts[i].balance += amount;
			Logger.log(LOG_LEVEL_INFO, " Deposited %.2f to account ID: %s. New balance: %.2f\n", amount, account_id, bankDB->accounts[i].balance);
			return 0;
		}
	}

	return -1;
}

/******************************************************************************
 *                                  Withdraw                                  *
 ******************************************************************************/

int withdraw(const char *account_id, double amount, BankDB *bankDB)
{
	for (size_t i = 0; i < bankDB->num_account; i++)
	{
		if (streq(bankDB->accounts[i].id, account_id))
		{
			if (bankDB->accounts[i].balance >= amount)
			{
				bankDB->accounts[i].balance -= amount;
				Logger.log(LOG_LEVEL_INFO, " Withdrew %.2f from account ID: %s. New balance: %.2f\n", amount, account_id, bankDB->accounts[i].balance);
				return 0;
			}
			else
			{
				Logger.log(LOG_LEVEL_ERROR, " Insufficient funds for withdrawal from account ID: %s. Current balance: %.2f\n", account_id, bankDB->accounts[i].balance);
				return -1;
			}
		}
	}

	return -1;
}

/******************************************************************************
 *                                  Account                                   *
 ******************************************************************************/

int create_account(const char *account_name, BankDB *bankDB)
{
	char *new_account_id = generate_id(8);

	for (size_t i = 0; i < bankDB->num_account; i++)
	{
		if (streq(new_account_id, bankDB->accounts[i].id))
		{
			Logger.log(LOG_LEVEL_ERROR, " Account ID collision occurred. Please try again.\n");
			free(new_account_id);
			return -1;
		}
	}

	Account *new_account = (Account *)malloc(sizeof(Account));
	if (!new_account)
	{
		Logger.log(LOG_LEVEL_ERROR, " Memory allocation failed when creating account.\n");
		free(new_account_id);
		return -1;
	}

	strncpy_s(new_account->id, ACCOUNT_ID_LENGTH, new_account_id, ACCOUNT_ID_LENGTH - 1);
	new_account->id[ACCOUNT_ID_LENGTH - 1] = '\0';
	strncpy_s(new_account->name, ACCOUNT_NAME_LENGTH, account_name, ACCOUNT_NAME_LENGTH - 1);
	new_account->name[ACCOUNT_NAME_LENGTH - 1] = '\0';
	new_account->balance = 0.0;

	Account *resized = (Account *)realloc(bankDB->accounts, sizeof(Account) * (bankDB->num_account + 1));
	if (!resized)
	{
		Logger.log(LOG_LEVEL_ERROR, " Memory allocation failed when adding account to DB.\n");
		free(new_account);
		free(new_account_id);
		return -1;
	}
	bankDB->accounts = resized;
	bankDB->accounts[bankDB->num_account] = *new_account;
	bankDB->num_account++;

	Logger.log(LOG_LEVEL_INFO, " Account created successfully! ID: %s, Name: %s\n", new_account->id, new_account->name);

	free(new_account);
	free(new_account_id);
	return 0;
}

int close_account(const char *account_id, BankDB *bankDB)
{
	for (size_t i = 0; i < bankDB->num_account; i++)
	{
		if (streq(bankDB->accounts[i].id, account_id))
		{
			// Shift accounts to fill the gap
			for (size_t j = i; j < bankDB->num_account - 1; j++)
			{
				bankDB->accounts[j] = bankDB->accounts[j + 1];
			}
			bankDB->num_account--;
			bankDB->accounts = (Account *)realloc(bankDB->accounts, sizeof(Account) * bankDB->num_account);
			Logger.log(LOG_LEVEL_INFO, " Account ID: %s closed successfully.\n", account_id);
			return 0;
		}
	}

	return -1;
}

/******************************************************************************
 *                                Transaction                                 *
 ******************************************************************************/

int create_transaction(const char *from_account_id, const char *to_account_id, double amount, const char *message, BankDB *bankDB)
{
	return 0;
}

/******************************************************************************
 *                                   Stuff                                    *
 ******************************************************************************/

void show_logo(void)
{
	puts("=====================================================================");
	puts("|" FG_B_CYAN "  __      __   _ _              _         ____              _      " RESET_COLOR "|");
	puts("|" FG_B_CYAN "  \\ \\    / /  | | |            (_)       |  _ \\            | |     " RESET_COLOR "|");
	puts("|" FG_B_CYAN "   \\ \\  / /_ _| | | _____  _ __ _  __ _  | |_) | __ _ _ __ | | __  " RESET_COLOR "|");
	puts("|" FG_B_CYAN "    \\ \\/ / _` | | |/ / _ \\| '__| |/ _` | |  _ < / _` | '_ \\| |/ /  " RESET_COLOR "|");
	puts("|" FG_B_CYAN "     \\  / (_| | |   < (_) | |  | | (_| | | |_) | (_| | | | |   <   " RESET_COLOR "|");
	puts("|" FG_B_CYAN "      \\/ \\__,_|_|_|\\_\\___/|_|  |_|\\__,_| |____/ \\__,_|_| |_|_|\\_\\  " RESET_COLOR "|");
	puts("|                                                                   " RESET_COLOR "|");
	puts("=====================================================================");
}

void show_menu(void)
{
	puts("|   [1]. List Accounts             [5]. Withdraw                    |");
	puts("|   [2]. Create Account            [6]. Save Database to file       |");
	puts("|   [3]. Delete Account            [7].                             |");
	puts("|   [4]. Deposit                   [0]. Exit                        |");
	puts("=====================================================================");
}

int get_choice(const char *prompt)
{
	fprintf(stdout, prompt);
	int buffer;
	fscanf(stdin, "%d", &buffer);
	return buffer;
}

int get_account_id(const char *prompt, char *buffer, size_t buffer_size)
{
	/* Print prompt safely and ensure stdout is flushed */
	fprintf(stdout, "%s", prompt);
	fflush(stdout);

	/* Read a non-empty line (skip a leftover newline from previous input) */
	while (1)
	{
		if (!fgets(buffer, buffer_size, stdin))
			return 0;

		/* If the line is just a newline, continue to read the next line */
		if (buffer[0] == '\n' && buffer[1] == '\0')
			continue;

		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		return 1;
	}
}

int get_account_name(const char *prompt, char *buffer, size_t buffer_size)
{
	fprintf(stdout, "%s", prompt);
	fflush(stdout);

	while (1)
	{
		if (!fgets(buffer, buffer_size, stdin))
			return 0;

		if (buffer[0] == '\n' && buffer[1] == '\0')
			continue;

		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		return 1;
	}
}

double get_amount(const char *prompt)
{
	fprintf(stdout, prompt);
	double amount = 0.0;
	fscanf(stdin, "%lf", &amount);
	return amount;
}

ClassCore Core = {
		.print_logo = show_logo,
		.print_menu = show_menu,
		.deposit = deposit,
		.withdraw = withdraw,
		.create_account = create_account,
		.close_account = close_account,
		.get_choice = get_choice,
		.get_account_id = get_account_id,
		.get_account_name = get_account_name,
		.get_amount = get_amount,
};
