# Expense Tracker

This is a C++ command-line application to track personal expenses. Users can add, view, edit, and delete expenses, with options to save the data to a file for future reference. This application can be useful for anyone looking to manage and categorize their expenses.

## Features

- **Add Expense**: Add a new expense with amount, category, date, and description.
- **View Expenses**: View a list of all recorded expenses.
- **Edit Expense**: Update the details of an existing expense.
- **Delete Expense**: Remove an expense from the list.
- **Summary**: View total expenses and category-wise totals.
- **Save and Load from File**: Persist expenses by saving them to `expenses.txt`.

## Getting Started

### Prerequisites

- C++ compiler (e.g., `g++`)
- Terminal or command prompt access

### Compiling the Program

To compile the program, use the following command in your terminal:

```bash
g++ main.cpp ExpenseTracker.cpp -o ExpenseTrackerApp
