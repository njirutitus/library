#include <iostream>
# include<vector>
using namespace std;
struct User{
	char name[200];
	string gender;
	char phone_number[15];
	char id_no[20];
	bool is_staff;
	bool is_admin;
	char password[255];
};

struct Book {
	char title[200];
	char author[200];
	char ISBN[20];
	int copies;
};

User add_user();
Book add_book();
int main(int argc, char** argv) {
	User user;
	Book book;
	int choice {0};
	cout<<"\tCounty Library management system"<<endl;
	cout<<"1. Add User\n";
	cout<<"2. Add Book\n";
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice) {
		case 1:
			user = add_user();
			cout<<user.name<<" Successfully added"<<endl;
			break;
		case 2:
			book = add_book();
			cout<<book.title<<" Successfully added"<<endl;
			break;
		default:
			cout<<"Invalid Choice\n";

	}
	
	return 0;
}

User add_user(){
	struct User user;
	int choice {0};
	cout<<"Enter name"<<endl;
	cin.getline(user.name,200);
	cout<<"Select gender"<<endl;
	cout<<"1. Male"<<endl;
	cout<<"2. Female"<<endl;
	cout<<"Your choice: "<<endl;
	cin>>choice;
	do{
		if(choice == 1){
			user.gender = 1;
		}
		else if(choice == 2){
			user.gender = 0;
		}
		else {
			cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2);
	
	cout<<"ID no: ";
	cin>>user.id_no;
	cout<<"Select User type"<<endl;
	cout<<"1. Student"<<endl;
	cout<<"2. Staff"<<endl;
	cout<<"3. Admin"<<endl;
	cout<<"Your choice: "<<endl;
	cin>>choice;
	do{
		if(choice == 1){
			user.is_admin = 0;
			user.is_staff = 0;
		}
		else if(choice == 2){
			user.is_admin = 0;
			user.is_staff = 1;
		}
		else if(choice == 3){
			user.is_admin = 1;
			user.is_staff = 0;
		}
		else {
			cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2 && choice!=2);
	cout<<"Enter Default password"<<endl;
	cin>>user.password;
	return user;
	
}

Book add_book(){
	Book book;
	cout<<"\t Add a new book\n";
	cout<<"Book title:";
	cin.getline(book.title,200,'*');
	cout<<"Book Author";
	cin.getline(book.author,200,'*');
	cout<<"ISBN: ";
	cin>>book.ISBN;
	cout<<"Copies: ";
	cin>>book.copies;

	return book;
}



