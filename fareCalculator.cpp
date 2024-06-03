#include <iostream>
#include <vector>

std::vector<double> fares = {2.75, 32.00, 121.00};
std::vector<std::string> fare_options = {"pay per ride", "seven day unlimited", "thirty day unlimited"};


std::vector<double> cost_per_ride(int days, int rides){

  double payper_price = 2.75;

  double seven_day_price = (days / 7) * 32.00;
  if(days % 7 > 0){
    seven_day_price += 32.00;
  }

  seven_day_price /= rides;

  double thirty_day_price = 121.00 / rides;

  std::vector<double> ride_prices = {payper_price, seven_day_price, thirty_day_price };

  return ride_prices;
}

void get_best_fare(int days, int rides){

  std::vector<double> ride_prices = cost_per_ride(days, rides);

  double lowest = ride_prices[0];

  int lowest_price_index = 0;

  for(int i = 0; i <ride_prices.size(); i++){
    if(ride_prices[i] < lowest){
      lowest = ride_prices[i];
      lowest_price_index = i;
    }
  }

  std::cout << "The best fare option is: " << fare_options[lowest_price_index] << "\n" << "Your fare will be: $" << lowest << "\n";

};

int main(){

  int days;
  int rides;

  std::cout << "Welcome to the Fare Calculator\n";

  std::cout << "How many days will you be using the metro?\n";

  std::cin >> days;

  std::cout << "How many rides do you anticipate taking?\n";

  std::cin >> rides;

  get_best_fare(days, rides);

}