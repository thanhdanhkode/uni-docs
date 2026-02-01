#define DATABASE_NAME "DB.valkoria"

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <valkoria/core.h>
#include <valkoria/db.h>
#include <valkoria/lib.h>
#include <valkoria/logger.h>
#include <time.h>
#include <stdlib.h>

void print_process_desc(const char *title, const int size);

int main(int argc, char **argv)
{
	srand(time(NULL));
	BankDB bankDB;

	Core.print_logo();
	Logger.log(LOG_LEVEL_INFO, "[Valkoria] Initializing...");

	if (!DBC.connect(DATABASE_NAME))
		Logger.log(LOG_LEVEL_INFO, "[ValkoriaDB] Connected to database successfully.");
	else
	{
		Logger.log(LOG_LEVEL_ERROR, "[ValkoriaDB] Failed to connect to database.");
		return 1;
	}

	DBC.load(DATABASE_NAME, &bankDB);
	DBC.save("DB1.valkoria", &bankDB);

	Console.clear();
	Core.print_logo();
	Core.print_menu();

	while (1)
	{

		int choice = Core.get_choice("\n>>> Enter your choice: ");
		char *account_id = (char *)malloc(ACCOUNT_ID_LENGTH);
		char *account_name = (char *)malloc(ACCOUNT_NAME_LENGTH);
		double amount;

		switch (choice)
		{
		case 0:
			Logger.log(LOG_LEVEL_TRACE, "[Valkoria] Exiting. Have a nice day!");
			exit(0);
			break;

		case 1:
			print_process_desc("[ List Accounts in DB ]", 70);

			for (size_t i = 0; i < bankDB.num_account; i++)
			{
				Logger.log(LOG_LEVEL_TRACE, "ID: %s | Name: %s | Balance: %.2f", bankDB.accounts[i].id, bankDB.accounts[i].name, bankDB.accounts[i].balance);
			}

			print_process_desc("", 70);

			break;

		case 2:
			print_process_desc(" Create Account ", 70);

			Core.get_account_name(">>> Enter Account Name: ", account_name, ACCOUNT_NAME_LENGTH);

			Core.create_account(account_name, &bankDB);
			break;

		case 3:
			print_process_desc(" Delete Account ", 70);

			Core.get_account_id(">>> Enter Account ID: ", account_id, ACCOUNT_ID_LENGTH);

			Core.close_account(account_id, &bankDB);
			break;

		case 4:
			print_process_desc("Deposit", 70);

			Core.get_account_id(">>> Enter Account ID: ", account_id, ACCOUNT_ID_LENGTH);
			amount = Core.get_amount(">>> Enter Amount to Deposit: ");

			Core.deposit(account_id, amount, &bankDB);
			break;

		case 5:
			print_process_desc("Withdraw", 70);

			Core.get_account_id(">>> Enter Account ID: ", account_id, ACCOUNT_ID_LENGTH);
			amount = Core.get_amount(">>> Enter Amount to Deposit: ");

			Core.withdraw(account_id, amount, &bankDB);
			break;

		case 6:
			print_process_desc("Save Database to file", 70);

			DBC.save("DB.valkoria", &bankDB);

			Logger.log(LOG_LEVEL_INFO, "[ValkoriaDB] Database saved successfully.");

			break;

		default:
			Console.clear_from(17);
			Console.move_cursor(1, 17);

			Logger.log(LOG_LEVEL_ERROR, "[Valkoria] Invalid choice. Please try again.");
			break;
		}
	}

	return 0;
}

void print_process_desc(const char *title, const int size)
{
	int title_length = (int)strlen(title);
	int is_printed = 0;

	fprintf(stdout, "\n");
	for (int i = 1; i <= size; i++)
	{
		if ((i > (size - 1) / 2 - title_length / 2) && (i < (size - 1) / 2 - title_length / 2 + title_length))
		{
			if (!is_printed)
			{
				fprintf(stdout, "%s", title);
				is_printed = 1;
			}
		}
		else if (i == size)
		{
			fprintf(stdout, "\n");
		}
		else
		{
			fprintf(stdout, "=");
		}
	}
}
