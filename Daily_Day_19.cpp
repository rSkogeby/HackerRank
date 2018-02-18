#include <iostream>
#include <cmath>
// Interface
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};

// divisorSum returns the sum of all divisors of n
class Calculator : public AdvancedArithmetic{
  public:
    int divisorSum(int n){ 
        int sum = 0;
        int sqrt = (int) std::sqrt(n);
        for (int i = 1; i <= sqrt; i++) {
            if (n % i == 0) {
                sum += i + n/i; 
            }
        }
        if (sqrt * sqrt == n) {
            sum -= sqrt;
        }
        return sum;
    } 
};

int main(){

  Calculator f;

	std::cout << f.divisorSum(6) << std::endl;
}
