#include "ExpenseTracker.h"

int main() {
    ExpenseTracker tracker;

    tracker.loadFromFile("expenses.txt");

    int choice;
    while (true) {
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Delete Expense\n";
        std::cout << "4. Edit Expense\n";
        std::cout << "5. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                std::string category, date, description;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cin.ignore();  // Clear the buffer
                std::cout << "Enter category: ";
                std::getline(std::cin, category);
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);
                tracker.addExpense(amount, category, date, description);
                break;
            }
            case 2:
                tracker.viewExpenses();
                break;
            case 3: {
                int id;
                std::cout << "Enter expense ID to delete: ";
                std::cin >> id;
                tracker.deleteExpense(id);
                break;
            }
            case 4: {
                int id;
                double amount;
                std::string category, date, description;
                std::cout << "Enter expense ID to edit: ";
                std::cin >> id;
                std::cout << "Enter new amount: ";
                std::cin >> amount;
                std::cin.ignore();  // Clear the buffer
                std::cout << "Enter new category: ";
                std::getline(std::cin, category);
                std::cout << "Enter new date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                std::cout << "Enter new description: ";
                std::getline(std::cin, description);
                tracker.editExpense(id, amount, category, date, description);
                break;
            }
            case 5:
                // Save the expenses to "expenses.txt"
                tracker.saveToFile("expenses.txt");
                std::cout << "Expenses saved. Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
