#pragma once

#ifndef VALKORIA_DB_H
#define VALKORIA_DB_H

#include <stddef.h>

typedef enum
{
	SECTION_NONE,
	SECTION_ACCOUNT,
	SECTION_TRANSACTION
} Section;

#define DB_NAME_LENGTH 128

#define ACCOUNT_ID_LENGTH 8
#define ACCOUNT_NAME_LENGTH 128
#define TRANSACTION_ID_LENGTH 8
#define TRANSACTION_MESSAGE_LENGTH 256

typedef enum
{
	TRANSACTION_DEPOSIT,
	TRANSACTION_WITHDRAW,
	TRANSACTION_TRANSFER
} TransactionType;

typedef struct
{
	char id[ACCOUNT_ID_LENGTH];
	char name[ACCOUNT_NAME_LENGTH];
	double balance;
} Account;

typedef struct
{
	char id[TRANSACTION_ID_LENGTH];
	char from_id[ACCOUNT_ID_LENGTH];
	char to_id[ACCOUNT_ID_LENGTH];
	double amount;
	char message[TRANSACTION_MESSAGE_LENGTH];
	TransactionType type;
} Transaction;

typedef struct
{
	size_t num_account;
	size_t num_transaction;
	Account *accounts;
	Transaction *transactions;
} BankDB;

int connect_database(const char *filename);
int load_database(const char *filename, BankDB *bankDB);
int save_database(const char *filename, const BankDB *bankDB);

typedef struct DBController
{
	int (*connect)(const char *filename);
	int (*load)(const char *filename, BankDB *bankDB);
	int (*save)(const char *filename, const BankDB *bankDB);
} ClassDB;

extern ClassDB DBC;

#endif // !VALKORIA_DB_H
