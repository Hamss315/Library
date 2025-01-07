#include<iostream>
#include<string>
#include"library.h"
using namespace std;
int main() {
	library l;
	int choice;
	std:: string title, author;
	do{
	cout << endl <<"How can we help you ? " << endl;
	cout << "1.Add Book " << endl;
	cout << "2.Search for Book by title " << endl;
	cout << "3.Search for Book by author " << endl;
	cout << "4.Borrow Book " << endl;
	cout << "5.Return Book " << endl;
	cout << "6.Remove Book " << endl;
	cout << "7.Display All Books " << endl;
	cout << "8.Display Borrowed Books " << endl;
	cout << "9.Display UnBorrowed Books " << endl;
	cout << "10.Display Number of Books " << endl;
	cout << "11.Exit " << endl << endl;
	cout << "Enter your choice " << endl;
	cin >> choice;
	cin.ignore(); 
		switch (choice) {
		case 1: cout << "Enter Title : ";
				getline(cin,title);
				cout << "Enter Author Name : ";
				getline(cin, author);
				l.addBook(title, author);
				break;
		case 2:	cout << "Enter Title : ";
			    getline(cin, title);
				l.searchByTitle(title);
				break;
		case 3:cout << "Enter Author Name : ";
			   getline(cin, author);
			   l.searchByAuthor(author);
			    break;
		case 4: cout << "Enter Title : ";
			    getline(cin, title);
				l.borrowBook(title);
				break;
		case 5: cout << "Enter Title : ";
			    getline(cin, title);
			    l.returnBook(title);
				break;
		case 6: cout << "Enter Title : ";
			    getline(cin, title);
			    l.removeBook(title);
			    break;
		case 7: l.displaybooks();
			    break;
		case 8: l.displayBorrowedBooks();
			    break;
		case 9: l.displayUnBorrowedBooks();
			    break;
		case 10:l.Count();
			    break;
		case 11: std::cout << "Exiting..." << endl;
			    break;
		default: std::cout << "Invalid choice! Please try again." << endl;
			    break;
		}
	} while (choice != 11);
	return 0;
}