#include <iostream>
# include<vector>
class Book{
	char title[200];
	char author[200];
	char ISBN[20];
	int copies;
public:
	void add_book();
};

class User{
	char name[200];
	std::string gender;
	char phone_number[15];
	char id_no[20];
	bool is_staff;
	bool is_admin;
	char password[255];
public:
	void add_user();
};

class Calendar {
	int year;
	int month;
	int day;
public:
	void print_header(const int year, const int month);
	bool valid_date(int year, int month, int day);
	void print_calendar(int year, int month);
	int day_of_the_week(int year, int month, int day);
};

void Book::add_book(){
	std::cout<<"\t Add a new book\n";
	std::cout<<"Book title:";
	std::cin.getline(title,200,'*');
	std::cout<<"Book Author";
	std::cin.getline(author,200,'*');
	std::cout<<"ISBN: ";
	std::cin>>ISBN;
	std::cout<<"Copies: ";
	std::cin>>copies;

}

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
			gender = "male";
		}
		else if(choice == 2){
			gender = "female";
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
			is_staff = 1;
		}
		else {
			std::cout<<"Invalid choice. Try again";
		}
	}while(choice!=1 && choice!=2 && choice!=3);
	std::cout<<"Enter Default password"<<std::endl;
	std::cin>>password;
}

void Calendar::print_header(const int year, const int month) {
  if (month == 1) {
    printf("====January %d====\n", year);
  } else if (month == 2) {
    printf("===February %d====\n", year);
  } else if (month == 3) {
    printf("=====March %d=====\n", year);
  } else if (month == 4) {
    printf("=====April %d=====\n", year);
  } else if (month == 5) {
    printf("======May %d======\n", year);
  } else if (month == 6) {
    printf("=====June %d======\n", year);
  } else if (month == 7) {
    printf("=====July %d======\n", year);
  }else if (month == 8) {
    printf("====August %d=====\n", year);
  } else if (month == 9) {
    printf("===September %d===\n", year);
  } else if (month == 10) {
    printf("====October %d====\n", year);
  } else if (month == 11) {
    printf("===November %d====\n", year);
  } else if (month == 12) {
    printf("===December %d====\n", year);
  }
  printf("Su Mo Tu We Th Fr Sa\n");
}

bool Calendar::valid_date(int year, int month, int day) {
  int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}, leap = 0;
  if (month > 12 || month < 1) return false;
  if (day < 1) return false;
  if (year > 2999 || year < 1589) return false;

  // check if leap year
  if(year % 100 == 0)  
  {  
      if(year % 400 == 0)  
      {  
          leap = 1;  
      }  
  }  
  else  
  {  
      if(year % 4 == 0)  
      {  
          leap = 1;  
      }  
  }  

  if (month ==2 && day == 29 ){
    if(!leap) return false;
  }
  else if(day > days_in_month[month-1]) {
    return false;
  }
  return true;
}

int Calendar::day_of_the_week(int year, int month, int day) {
  int ref_year = 1589, leap = 0, diff, total_days = 0, day_num = 0,days=0; 
    int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    int i;

    // count days for the current year
    for(i=1;i<month;i++){

      if(i == 2 && (year% 4 == 0 && year%100 != 0 || year%400 == 0)){
        days += 29;
        continue;
      }
      days += days_in_month[i];

    }

    days += day;
  
    diff = year - ref_year;  

    // count days for previous years  
    while(ref_year < year)  
    {  
        if(ref_year % 100 == 0)  
        {  
            if(ref_year % 400 == 0)  
            {  
                leap++;  
            }  
        }  
        else  
        {  
            if(ref_year % 4 == 0)  
            {  
                leap++;  
            }  
        }  
        ref_year++;  
    }  
  
    total_days = (diff - leap) * 365 + leap * 366 + days - 1;  
    day_num = total_days % 7;  
  
    return day_num;
}

void Calendar::print_calendar(int year, int month) {
  Calendar calendar;
  calendar.print_header(year,month);
  int day, first_day = calendar.day_of_the_week(year,month,1);
  int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

  // Determine if leap year
  if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
	{
		days_in_month[2] = 29;
	}
	else
	{
		days_in_month[2] = 28;
	}
  // Correct the position for the first date
  for ( day = 1; day <= first_day*3; day++ )
  {
    printf(" ");
  }
  
  // Print all the dates for the month
  for ( day = 1; day <= days_in_month[month]; day++ )
  {
    printf("%2d", day );
    
    // Is day before Sat? Else start next line Sun.
    if ( ( day + first_day ) % 7 > 0 )
      printf(" " );
    else
      printf("\n" );
  }

}

int main(int argc, char** argv) {
	Book book;
	User user;
	int choice {0};
	std::cout<<"\tCounty Library management system"<<std::endl;
	std::cout<<"\nWelcome, What would you like to do today: \n";
	std::cout<<"1. Add User\n";
	std::cout<<"2. Add Book\n";
	std::cout<<"3. Print Calendar Month\n";
	std::cout<<"Your choice: ";
	std::cin>>choice;
	switch(choice) {
		case 1:
			user.add_user();
			std::cout<<"User Successfully added"<<std::endl;
			break;
		case 2:
			book.add_book();
			std::cout<<"Book Successfully added"<<std::endl;
			break;
		case 3:
			int year, month;
			Calendar calendar;
			std::cout<<"Enter year followed by month: ";
			std::cin>>year;
			std::cin>>month;
			calendar.print_calendar(year,month);
			break;
		default:
			std::cout<<"Invalid Choice\n";

	}
	
	return 0;
}



