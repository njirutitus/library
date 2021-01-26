#include <iostream>
# include<vector>

struct Book {
	char title[200];
	char author[200];
	char ISBN[20];
	int copies;
};

Book add_book();
int main(int argc, char** argv) {
	Book book;
	User user;
	char name[200];
	int choice {0};
	std::cout<<"\tCounty Library management system"<<std::endl;
	std::cout<<"1. Add User\n";
	std::cout<<"2. Add Book\n";
	std::cout<<"Your choice: ";
	std::cin>>choice;
	switch(choice) {
		case 1:
			user.add_user();
			std::cout<<"User Successfully added"<<std::endl;
			break;
		case 2:
			book = add_book();
			std::cout<<book.title<<" Successfully added"<<std::endl;
			break;
		default:
			std::cout<<"Invalid Choice\n";

	}
	
	return 0;
}

Book add_book(){
	Book book;
	std::cout<<"\t Add a new book\n";
	std::cout<<"Book title:";
	std::cin.getline(book.title,200,'*');
	std::cout<<"Book Author";
	std::cin.getline(book.author,200,'*');
	std::cout<<"ISBN: ";
	std::cin>>book.ISBN;
	std::cout<<"Copies: ";
	std::cin>>book.copies;

	return book;
}

class User{
	char name[200];
	int gender;
	char phone_number[15];
	char id_no[20];
	unsigned int is_staff;
	unsigned int is_admin;
	char password[255];
public:
	void add_user();
};

void User::add_user(){
	int choice {0};
	std::cout<<"Enter name"<<std::endl;
	std::cin.getline(name,200);
	std::cout<<"Select gender"<<std::endl;
	std::cout<<"1. Male"<<std::endl;
	std::cout<<"2. Female"<<std::endl;
	std::cout<<"Your choice: "<<std::endl;
	std::cin>>choice;
	do{
		if(choice == 1){
			gender = 1;
		}
		else if(choice == 2){
			gender = 0;
		}
		else {
			std::cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2);
	
	std::cout<<"ID no: ";
	std::cin>>id_no;
	std::cout<<"Select User type"<<std::endl;
	std::cout<<"1. Student"<<std::endl;
	std::cout<<"2. Staff"<<std::endl;
	std::cout<<"3. Admin"<<std::endl;
	std::cout<<"Your choice: "<<std::endl;
	std::cin>>choice;
	do{
		if(choice == 1){
			is_admin = 0;
			is_staff = 0;
		}
		else if(choice == 2){
			is_admin = 0;
			is_staff = 1;
		}
		else if(choice == 3){
			is_admin = 1;
			is_staff = 0;
		}
		else {
			std::cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2 && choice!=2);
	std::cout<<"Enter Default password"<<std::endl;
	std::cin>>password;
	
}



