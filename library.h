#pragma once
#include<iostream>
#include<string>
using namespace std;
struct book {
	string title, author;       //title and author of book
	bool isBorrowed;            //state of book (borrowed/not)
	book* next;                 //pointer to the next book in list
	book(string t, string a);   //constructor declaration for book
};
class library {
private:
	book* head;
	int numberofbooks;
public:
	library();                  //library declaration constructor

	bool libraryisempty();           //checking if library has books
	void addBook(string t, string a); //adding book to the library
	void searchByTitle(string title);       //searching for book using title
	void searchByAuthor(string author);     //searching for book using author
	void borrowBook(string title);       //borrow a book by giving its title
	void returnBook(string title);       //return a book by giving its title
	void removeBook(string title);          //remove book from library
	void displaybooks();                //display all books in library
	void displayBorrowedBooks();       // returns all borrowed books in library
	void displayUnBorrowedBooks();       // returns available books for borrowing in library
	void Count();                 //returns number of books in library
};
