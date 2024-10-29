#ifndef EXPENSETRACKER_H
#define EXPENSETRACKER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <map> 

struct Expense {
    int id;
    double amount;
    std::string category;
    std::string date;
    std::string description;
};

class ExpenseTracker {
private:
    std::vector<Expense> expenses;
    int nextId = 1;

public:
    void addExpense(double amount, const std::string& category, const std::string& date, const std::string& description);
    void viewExpenses();
    void deleteExpense(int id);
    void editExpense(int id, double amount, const std::string& category, const std::string& date, const std::string& description);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void displaySummary();
};

#endif 
