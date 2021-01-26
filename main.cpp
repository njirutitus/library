#include <iostream>
# include<vector>
FILE *fp;
struct User{
	std::string name;
	int gender;
	std::string phone_number;
	std::string id_type;
	std::string id_no;
	unsigned int is_staff;
	unsigned int is_admin;
	char password[255];
};

struct Book {
	std::string title;
	std::string author;
	std::string ISBN;
	int copies;
};

User add_user();
Book add_book();
int main(int argc, char** argv) {
	User user;
	Book book;
	int choice {0};
	std::cout<<"\tCounty Library management system"<<std::endl;
	std::cout<<"1. Add User\n";
	std::cout<<"2. Add Book\n";
	std::cout<<"Your choice: ";
	std::cout<<"\tAdd user";
	switch(choice) {
		case 1:
			user = add_user();
			std::cout<<user.name<<" Successfully added"<<std::endl;
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

User add_user(){
	struct User user;
	int choice {0};
	std::cout<<"Enter name"<<std::endl;
	std::cin>>user.name;
	std::cout<<"Select gender"<<std::endl;
	std::cout<<"1. Male"<<std::endl;
	std::cout<<"2. Female"<<std::endl;
	std::cout<<"Your choice: "<<std::endl;
	std::cin>>choice;
	do{
		if(choice == 1){
			user.gender = 1;
		}
		else if(choice == 2){
			user.gender = 0;
		}
		else {
			std::cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2);
	std::cout<<"Select Identity type"<<std::endl;
	std::cout<<"1. National ID"<<std::endl;
	std::cout<<"2. Library No."<<std::endl;
	std::cout<<"Your choice: "<<std::endl;
	std::cin>>choice;
	do{
		if(choice == 1){
			user.id_type = "national";
		}
		else if(choice == 2){
			user.id_type = "library";
		}
		else {
			std::cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2);
	
	std::cout<<"ID no: ";
	std::cin>>user.id_no;
	std::cout<<"Select User type"<<std::endl;
	std::cout<<"1. Student"<<std::endl;
	std::cout<<"2. Staff"<<std::endl;
	std::cout<<"3. Admin"<<std::endl;
	std::cout<<"Your choice: "<<std::endl;
	std::cin>>choice;
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
			std::cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2 && choice!=2);
	std::cout<<"Enter Default password"<<std::endl;
	std::cin>>user.password;
	return user;
	
}

Book add_book(){
	Book book;
	std::cout<<"\t Add a new book\n";
	std::cout<<"Book title: ";
	std::cin>>book.title;
	std::cout<<"Book Author";
	std::cin>>book.author;
	std::cout<<"ISBN: ";
	std::cin>>book.ISBN;
	std::cout<<"Copies: ";
	std::cin>>book.copies;
	std::cout<<book.title<<" Successfully added\n";
}



