#include <iostream>
// Day26: Nested Logic

struct Date{
  int day;
  int month;
  int year;
};

int main() {
  Date returnDate;
  Date expectedDate;
  std::cin >> returnDate.day >> returnDate.month >> returnDate.year;
  std::cin >> expectedDate.day >> expectedDate.month >> expectedDate.year;

  if( returnDate.year > expectedDate.year ){
    std::cout << 10000 << std::endl; 
  } else if (returnDate.year == expectedDate.year) {
      if ( returnDate.month > expectedDate.month ){
      std::cout << 500*(returnDate.month-expectedDate.month) << std::endl; 
    } else if ( returnDate.day > expectedDate.day ) {
      std::cout << 15 *(returnDate.day-expectedDate.day) << std::endl;  
    } else {
      std::cout << 0 << std::endl;  
    }
  } else {
    std::cout << 0 << std::endl;  
  }
  return 0;
}
