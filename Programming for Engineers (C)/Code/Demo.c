#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_ACCOUNTS 1000
#define NAME_LEN 60
#define LINE_LEN 256
#define DATA_FILE "accounts.txt"

typedef struct
{
  int accountNumber;
  char name[NAME_LEN];
  double balance;
} Account;

/* ---------- Utility: safe input ---------- */

static void trim_newline(char *s)
{
  size_t n = strlen(s);
  if (n > 0 && s[n - 1] == '\n')
    s[n - 1] = '\0';
}

static int read_line(const char *prompt, char *buf, size_t buflen)
{
  if (prompt)
    printf("%s", prompt);
  if (!fgets(buf, (int)buflen, stdin))
    return 0;
  trim_newline(buf);
  return 1;
}

/* Parse int with validation (reject letters, empty, overflow, etc.) */
static int parse_int_strict(const char *s, int *out)
{
  char *end = NULL;
  long v;

  errno = 0;
  v = strtol(s, &end, 10);
  if (errno != 0)
    return 0;
  if (end == s)
    return 0; // no digits
  while (*end)
  { // remaining must be spaces only
    if (!isspace((unsigned char)*end))
      return 0;
    end++;
  }
  if (v < 0 || v > 2147483647L)
    return 0;
  *out = (int)v;
  return 1;
}

/* Parse double with validation */
static int parse_double_strict(const char *s, double *out)
{
  char *end = NULL;
  double v;

  errno = 0;
  v = strtod(s, &end);
  if (errno != 0)
    return 0;
  if (end == s)
    return 0;
  while (*end)
  {
    if (!isspace((unsigned char)*end))
      return 0;
    end++;
  }
  *out = v;
  return 1;
}

/* ---------- Account helpers ---------- */

static int find_account_index(Account a[], int n, int accNo)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i].accountNumber == accNo)
      return i;
  }
  return -1;
}

static void list_accounts(const Account a[], int n)
{
  printf("\n--- Accounts (%d) ---\n", n);
  if (n == 0)
  {
    printf("No accounts found.\n");
    return;
  }
  printf("%-10s | %-30s | %12s\n", "AccNo", "Name", "Balance");
  printf("---------------------------------------------------------------\n");
  for (int i = 0; i < n; i++)
  {
    printf("%-10d | %-30s | %12.2f\n",
           a[i].accountNumber, a[i].name, a[i].balance);
  }
}

static int load_accounts(const char *filename, Account a[], int *n)
{
  FILE *fp = fopen(filename, "r");
  char line[LINE_LEN];
  int count = 0;

  if (!fp)
  {
    // If file doesn't exist yet, treat as empty database.
    *n = 0;
    return 1;
  }

  while (fgets(line, sizeof(line), fp))
  {
    trim_newline(line);
    if (line[0] == '\0')
      continue;

    // format: accNo|name|balance
    char *p1 = strtok(line, "|");
    char *p2 = strtok(NULL, "|");
    char *p3 = strtok(NULL, "|");

    if (!p1 || !p2 || !p3)
    {
      // skip malformed line (simple and safe)
      continue;
    }

    int accNo;
    double bal;
    if (!parse_int_strict(p1, &accNo))
      continue;
    if (!parse_double_strict(p3, &bal))
      continue;
    if (bal < 0)
      continue; // basic sanity

    if (count >= MAX_ACCOUNTS)
      break;

    a[count].accountNumber = accNo;
    strncpy(a[count].name, p2, NAME_LEN - 1);
    a[count].name[NAME_LEN - 1] = '\0';
    a[count].balance = bal;
    count++;
  }

  fclose(fp);
  *n = count;
  return 1;
}

static int save_accounts_overwrite(const char *filename, const Account a[], int n)
{
  FILE *fp = fopen(filename, "w");
  if (!fp)
    return 0;

  for (int i = 0; i < n; i++)
  {
    fprintf(fp, "%d|%s|%.2f\n", a[i].accountNumber, a[i].name, a[i].balance);
  }
  fclose(fp);
  return 1;
}

/* ---------- Operations ---------- */

static void open_new_account(Account a[], int *n)
{
  if (*n >= MAX_ACCOUNTS)
  {
    printf("Account storage is full.\n");
    return;
  }

  char buf[LINE_LEN];
  int accNo;

  // account number
  while (1)
  {
    if (!read_line("Enter new account number (integer): ", buf, sizeof(buf)))
      return;
    if (!parse_int_strict(buf, &accNo))
    {
      printf("Invalid account number. Try again.\n");
      continue;
    }
    if (find_account_index(a, *n, accNo) != -1)
    {
      printf("Account number already exists. Try another.\n");
      continue;
    }
    break;
  }

  // name
  char name[NAME_LEN];
  while (1)
  {
    if (!read_line("Enter customer name: ", name, sizeof(name)))
      return;
    if (strlen(name) == 0)
    {
      printf("Name cannot be empty.\n");
      continue;
    }
    break;
  }

  // initial balance (optional: allow 0)
  double bal;
  while (1)
  {
    if (!read_line("Enter initial balance (>= 0): ", buf, sizeof(buf)))
      return;
    if (!parse_double_strict(buf, &bal) || bal < 0)
    {
      printf("Invalid balance. Try again.\n");
      continue;
    }
    break;
  }

  a[*n].accountNumber = accNo;
  strncpy(a[*n].name, name, NAME_LEN - 1);
  a[*n].name[NAME_LEN - 1] = '\0';
  a[*n].balance = bal;
  (*n)++;

  printf("New account created successfully.\n");
}

static void deposit(Account a[], int n)
{
  char buf[LINE_LEN];
  int accNo;
  double amount;

  if (!read_line("Enter account number: ", buf, sizeof(buf)))
    return;
  if (!parse_int_strict(buf, &accNo))
  {
    printf("Invalid account number.\n");
    return;
  }

  int idx = find_account_index(a, n, accNo);
  if (idx == -1)
  {
    printf("Account not found.\n");
    return;
  }

  if (!read_line("Enter deposit amount (> 0): ", buf, sizeof(buf)))
    return;
  if (!parse_double_strict(buf, &amount) || amount <= 0)
  {
    printf("Invalid amount.\n");
    return;
  }

  a[idx].balance += amount;
  printf("Deposit successful. New balance: %.2f\n", a[idx].balance);
}

static void withdraw(Account a[], int n)
{
  char buf[LINE_LEN];
  int accNo;
  double amount;

  if (!read_line("Enter account number: ", buf, sizeof(buf)))
    return;
  if (!parse_int_strict(buf, &accNo))
  {
    printf("Invalid account number.\n");
    return;
  }

  int idx = find_account_index(a, n, accNo);
  if (idx == -1)
  {
    printf("Account not found.\n");
    return;
  }

  if (!read_line("Enter withdraw amount (> 0): ", buf, sizeof(buf)))
    return;
  if (!parse_double_strict(buf, &amount) || amount <= 0)
  {
    printf("Invalid amount.\n");
    return;
  }

  if (a[idx].balance - amount < 0)
  {
    printf("Denied: insufficient funds. Current balance: %.2f\n", a[idx].balance);
    return;
  }

  a[idx].balance -= amount;
  printf("Withdrawal successful. New balance: %.2f\n", a[idx].balance);
}

/* ---------- Menu ---------- */

static int read_menu_choice(void)
{
  char buf[LINE_LEN];
  int choice;

  if (!read_line("\nChoose (1-5): ", buf, sizeof(buf)))
    return 5; // default exit on EOF
  if (!parse_int_strict(buf, &choice))
    return -1;
  return choice;
}

int main(void)
{
  Account accounts[MAX_ACCOUNTS];
  int n = 0;

  if (!load_accounts(DATA_FILE, accounts, &n))
  {
    printf("Failed to load data.\n");
    return 1;
  }

  printf("Bank Transaction Simulation (CLI)\n");
  printf("Loaded %d account(s) from %s\n", n, DATA_FILE);

  while (1)
  {
    printf("\n=== MENU ===\n");
    printf("1. List accounts\n");
    printf("2. Open new account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");

    int choice = read_menu_choice();
    switch (choice)
    {
    case 1:
      list_accounts(accounts, n);
      break;
    case 2:
      open_new_account(accounts, &n);
      break;
    case 3:
      deposit(accounts, n);
      break;
    case 4:
      withdraw(accounts, n);
      break;
    case 5:
      if (!save_accounts_overwrite(DATA_FILE, accounts, n))
      {
        printf("ERROR: could not save to %s\n", DATA_FILE);
        return 1;
      }
      printf("Saved %d account(s). Goodbye.\n", n);
      return 0;
    default:
      printf("Invalid choice. Please enter 1-5.\n");
      break;
    }
  }
}
