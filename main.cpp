/*************************************** 
* Community Library management system  *
* Requires atleast c++11.              *
* Might however include c++20 features *
* Written by Titus Njiru               *
* February 2021                        *
***************************************/
#include <iostream>
#include<vector>
#include<string.h>

using namespace std;
//parent class
class Library {
  bool is_logged_in = false;
  const string admin_pass = "password";
public:
 //login user
  void login(string pass){
    if(pass == admin_pass) {
      is_logged_in = true;
    }
  }
  //check if user is logged in
  bool check_login(){
    return is_logged_in;
  }

  void logout(){
    is_logged_in = false;
  }

};

class Book:public Library{
	string title;
	string author;
	string ISBN;
	int copies;
public:
	bool add_book(const string t,const string a,const string i, const int c, const string pass);
};

class User:public Library{
	string name;
	string gender;
	string phone_number;
	string id_no;
	bool is_staff;
	bool is_admin;
	string password;
public:
	bool add_user(const string n,const string g,const string p,const string id, const bool stf, const bool admn, const string pass);
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

bool Book::add_book(const string t,const string a,const string i, const int c, const string pass){
  login(pass);
  if(check_login()){
	title = t;
	author = a;
	ISBN = i;
	copies = c;
  logout();
  return true;
  }
  return false;

}

bool User::add_user(const string n,const string g,const string p,const string id, const bool stf, const bool admn, const string pass){
  login(pass);
  if(check_login()) {
    name = n;
    gender = g;
    phone_number = p;
    id_no = id;
    is_staff = stf;
    is_admin = admn;
    logout();
    return true;
  }
  return false;
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

int main() {
	Book book;
	User user;
	Calendar calendar;
  bool result;
  cout<<"\tCommunity Library Management System\n";
	calendar.print_calendar(2021,2);
  cout<<endl;
  //Try to add Book
	result = book.add_book("Grasp","Sanjay sarma","61234678",5,"password");
  if (result) cout<<"Successful"<<endl;
  else cout << "Failed" << endl;
  
  //Try to add user
	result = user.add_user("Titus Njiru","male","0707015033","123456",true,false,"kimanthi");
  if (result) cout<<"Successful"<<endl;
  else cout << "Failed" << endl;
	
	return 0;
}



