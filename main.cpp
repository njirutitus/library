#include <iostream>
#include<vector>
FILE *fp;
struct library_user{
	std::string name;
	int gender;
	std::string phone_number;
	std::string id_type;
	std::string id_no;
	unsigned int is_staff;
	unsigned int is_admin;
	char password[255];
};

library_user add_user();
int main(int argc, char** argv) {
    std::vector <int> marks{10,20,30};
    std::cout<<marks[1];
	std::cout<<"\tCounty Library management system"<<std::endl;
	std::cout<<"\tAdd user";
    add_user();
	
	return 0;
}

library_user add_user(){
	struct library_user user;
	int choice {0};
	std::cout<<"Enter name"<<std::endl;
	std::cin>>user.name;
	std::cout<<"Select gender"<<std::endl;
	std::cout<<"1. Male"<<std::endl;
	std::cout<<"2. Female"<<std::endl;
	do{
        std::cout<<"Your choice: "<<std::endl;
	    std::cin>>choice;
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
	std::cout<<user.name<<std::endl;
	return user;
	
}

