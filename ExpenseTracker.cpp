#include "ExpenseTracker.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip> 
#include <algorithm>

void ExpenseTracker::addExpense(double amount, const std::string& category, const std::string& date, const std::string& description) {
    Expense exp;
    exp.id = nextId++;
    exp.amount = amount;
    exp.category = category;
    exp.date = date;
    exp.description = description;
    expenses.push_back(exp);
    std::cout << "Expense added successfully.\n";
}

void ExpenseTracker::viewExpenses() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "ID\tAmount\tCategory\tDate\t\tDescription\n";
    for (const auto& exp : expenses) {
        std::cout << exp.id << "\t" << exp.amount << "\t" << exp.category << "\t\t" 
                  << exp.date << "\t" << exp.description << "\n";
    }
}

void ExpenseTracker::deleteExpense(int id) {
    auto it = std::remove_if(expenses.begin(), expenses.end(), [id](Expense& exp) { return exp.id == id; });
    if (it != expenses.end()) {
        expenses.erase(it, expenses.end());
        std::cout << "Expense deleted successfully.\n";
    } else {
        std::cout << "Expense ID not found.\n";
    }
}

void ExpenseTracker::editExpense(int id, double amount, const std::string& category, const std::string& date, const std::string& description) {
    for (auto& exp : expenses) {
        if (exp.id == id) {
            exp.amount = amount;
            exp.category = category;
            exp.date = date;
            exp.description = description;
            std::cout << "Expense edited successfully.\n";
            return;
        }
    }
    std::cout << "Expense ID not found.\n";
}

void ExpenseTracker::saveToFile(const std::string& filename) {
    std::ofstream file(filename);  // Try opening the file for writing
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for writing.\n";
        return;  // Exit the function if the file cannot be opened
    }
    
    std::cout << "Saving data to '" << filename << "'...\n";  // Debugging output

    // Loop through the expenses vector and write each expense to the file
    for (const auto& exp : expenses) {
        file << exp.id << " "
             << exp.amount << " "
             << exp.category << " "
             << exp.date << " "
             << exp.description << "\n";
    }

    file.close();  // Close the file
    std::cout << "Expenses saved successfully to '" << filename << "'.\n";
}

void ExpenseTracker::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        Expense exp;
        while (file >> exp.id >> exp.amount >> exp.category >> exp.date) {
            std::getline(file, exp.description); // Read the rest of the line as description
            expenses.push_back(exp);
            if (exp.id >= nextId) {
                nextId = exp.id + 1; // Update nextId if necessary
            }
        }
        file.close();
        std::cout << "Expenses loaded from file successfully.\n";
    } else {
        std::cout << "Error opening file for reading.\n";
    }
}

void ExpenseTracker::displaySummary() {
    double total = 0;
    std::map<std::string, double> categoryTotals;

    for (const auto& exp : expenses) {
        total += exp.amount;
        categoryTotals[exp.category] += exp.amount;
    }

    std::cout << "Total Expenses : $" << total << "\n";
    std::cout << "Category-wise Expenses:\n";
    for (const auto& pair : categoryTotals) {
        std::cout << pair.first << ": $" << pair.second << "\n";
    }
}