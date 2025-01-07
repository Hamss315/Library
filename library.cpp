#include<iostream>
#include<string>
#include"library.h"
using namespace std;
book::book(string t, string a) : title(t), author(a), isBorrowed(false), next(nullptr) {}  //book constructor definition

library::library() : head(nullptr),numberofbooks(0) {}   //library constructor definition

bool library::libraryisempty() {   //checking if library has books or not
	return(library::head == nullptr);  
}

void library::addBook(string t, string a) {   //add books to the library
    book* b = new book(t,a);   //create a new "book" object dynamically
	if (library::libraryisempty()) { 
		b->next = nullptr;    //pointer to book object points to NULL if library is empty
	}
	else {
		b->next = head;     //pointer to book object points to the book object the head was pointing to
	}
	head = b;   //assuming both cases ; the new book added will be the head
	numberofbooks++; //number of books in library increase by one
	cout << "Book Added Successfully :)" << endl;
}

void library::searchByTitle(string title) {  //searching for book using title
	book* temp;  //creating temporary pointer to access books in my library list
	temp = head;  //without moving the head
	bool found = false;
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl; 
		return;  //if library is empty end function
	}
	else {
		while (temp != nullptr) {  //while temp doesn't reach the end of library list
			if (temp->title == title) {  //if title of book the temp is pointing to is the 
				found = true;          //same as the title of searched book
				cout << "Found \n Title : " << temp->title << "\n Author : " << temp->author << "\n State : " << (temp->isBorrowed ? "borrowed" : "available") << endl;
				break; // end loop and stop searching
			}
			temp = temp->next;  //else ; continue searching for the book
		}
		if (found == false) {  //if found is not true ;then
			cout << "Not Found" << endl; //this means book isn't found
		}
	}
}

void library::searchByAuthor(string author) { //searching for book using author
	book* temp;   //creating temporary pointer to access books in my library list
	temp = head;    //without moving the head
	bool found = false;
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
		return;  //if library is empty end function
	}
	else {
		while (temp != nullptr) {  //while temp doesn't reach the end of library list
			if (temp->author == author) { //if author of book the temp is pointing to is the 
				found = true;   //same as the author of searched book
				cout << "Found \n Title : " << temp->title << "\n Author : " << temp->author << "\n State : " << (temp->isBorrowed ? "borrowed" : "available") << endl;
				cout << endl;
				//we wouldn't end loop here ; bec. one author can have many books
				//so, the loop continues to display all the books for the searched author
			}
			temp = temp->next; //else ; continue searching for the book (author)
		}
		if (found == false) {  //if found is not true ;then
			cout << "Not Found" << endl; //this means book isn't found
		}
	}
}

void library::borrowBook(string title) { //borrow a book by giving its title
	book* temp;   //creating temporary pointer to access books in my library list
	temp = head;   //without moving the head
	bool found = false;
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
		return;  //if library is empty end function
	}
	else {
		while (temp != nullptr) {  //while temp doesn't reach the end of library list
			if (temp->title == title && temp->isBorrowed == false) { 
				//if title of book the temp is pointing to is the same as the title of searched book and the book isn't already borrowed 
				found = true;                    
				temp->isBorrowed = true;  //change book state to "borrowed" ;so that no one else can borrow
				cout << "Book Borrowed Successfully :)" << endl;
				break;
			}
			temp = temp->next;  //else ; continue searching for the book 
		}
		if (found == false) { //if book is already borrowed or isn't added to the library from the beginning
			cout << "Book isn't available for borrowing :(" << endl; 
		}
	}
}

void library::returnBook(string title) {  //return a book by giving its title
	book* temp;   //creating temporary pointer to access books in my library list
	temp = head;  //without moving the head
	bool found = false;  
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
		return;  //if library is empty end function
	}
	else {
		while (temp != nullptr) {  //while temp doesn't reach the end of library list
	//if title of book the temp is pointing to is the same as the title of searched book and the book is borrowed 
			if (temp->title == title && temp->isBorrowed == true) {
				found = true;
				temp->isBorrowed = false; //change book state to "borrowed" ;so others can finally borrow
				cout << "Book Returned Successfully :)" << endl;
				break;
			}
			temp = temp->next; //else ; continue searching for the book 
		}
		if (found == false) { //if book is already not borrowed or isn't added to the library from the beginning
			cout << "Book was not borrowed..." << endl;
		}
	}
}

void library::removeBook(string title) {
	book* prev = nullptr;  //creating pointer moving one step before the pointer used to access the book we want to delete
	book* delptr=head;    //creating pointer to access the book we want to delete
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
		return;       //if library is empty end function
	}
	if (head->title == title) {  //if the book we're searching for is the first we access
		head = head->next;  //make head point to the book after it
		delete delptr;     // delete book
		numberofbooks--;   // Decrement the book count
		return;  //end function
	}
		while (delptr != nullptr && delptr->title != title) { //while delptr doesn't reach the end of library list & the book (title) isn't found yet
			prev = delptr;  //move prev pointer to delptr 
			delptr = delptr->next;  //move delptr to next book
		}
		if (delptr == nullptr) {  //if delptr reaches the end of list
			cout << "Book not found" << endl; //display that book isn't found
			return; //end function
		}
		prev->next = delptr->next; //assign prev pointer to point to what delptr was pointing to "instead of delptr itself"
		delete delptr;
		numberofbooks--;
		cout << "Book deleted successfully" << endl;
}

void library::displaybooks() {
	int count = 1;
	book* temp;  
	temp = head;  
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
	}
	else {
		cout << "There ia a total of " << numberofbooks << " books in the library." << endl; 
		while (temp != nullptr) {
			cout << count <<")\n Title : " << temp->title << "\n Author : " << temp->author << "\n State : " << (temp->isBorrowed?"borrowed":"available") << endl;
			temp = temp->next;
			count++;
		}
	}
}

void library::displayBorrowedBooks(){
	book* temp = head; 
	int nbb = 0;
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
	}
	else {
		while (temp!= nullptr) {
			if (temp->isBorrowed == true) {
				nbb++;
				cout << "Borrowed Books are : " << endl;
				cout << nbb << ")\n Title : " << temp->title << "\n Author : " << temp->author << endl;
			}
			temp = temp->next;
		}
	}
	if (nbb == 0) {
		cout << "No Borrowed books " << endl;
	}
}

void library::displayUnBorrowedBooks() {
	book* temp = head;
	int nubb = 0;
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
	}
	else {
		while (temp != nullptr) {
			if (temp->isBorrowed == false) {
				nubb++;
				cout << "UnBorrowed Books are : " << endl;
				cout << nubb << ")\n Title : " << temp->title << "\n Author : " << temp->author << endl;
			}
			temp = temp->next;
		}
	}
	if (nubb == 0) {
		cout << "No Books Available to Borrow :(( " << endl;
	}
}

void library::Count() {
	book* temp; // creating temporary pointer to access books in my library list
	temp = head;  // without moving the head
	int count = 0; //initializing count
	if (library::libraryisempty()) {
		cout << "Library is empty" << endl;
		}
	else {
		while (temp != nullptr) {  // while temp doesn't reach the end of my library list
			count++;   //increment count by 1
			temp = temp->next;
		}
	}
	cout << "There is a total of " << count << " books in the library." << endl;
}

