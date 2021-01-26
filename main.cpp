#include <iostream>
# include<vector>
FILE *fp;
struct User{
	char name[200];
	int gender;
	char phone_number[15];
	char id_no[20];
	unsigned int is_staff;
	unsigned int is_admin;
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
	std::cout<<"\tCounty Library management system"<<std::endl;
	std::cout<<"1. Add User\n";
	std::cout<<"2. Add Book\n";
	std::cout<<"Your choice: ";
	std::cin>>choice;
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
	std::cin.getline(user.name,200);
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



