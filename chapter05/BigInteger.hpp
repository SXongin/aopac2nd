#ifndef Biginteger_H_
#define Biginteger_H_
#include <iostream>
#include <string>
#include <vector>

class BigInteger {
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& big_integer);
    friend std::istream& operator>>(std::istream& is, BigInteger& big_integer);
    friend BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs);
    friend BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs);
    friend BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs);
    friend BigInteger operator/(const BigInteger& lhs, const BigInteger& rhs);

   private:
    static const int kBase  = 100000000;
    static const int kWidth = 8;
    std::vector<int> number;
    void remove_ahead_zero();
    BigInteger multi_int_at_index(const int integer, const int index) const;

   public:
    BigInteger(long long num = 0) { *this = num; }
    BigInteger& operator=(long long num);
    BigInteger& operator=(const std::string& str);
    BigInteger& operator+=(const BigInteger& rhs);
};

std::ostream& operator<<(std::ostream& os, const BigInteger& big_integer);
std::istream& operator>>(std::istream& is, BigInteger& big_integer);

BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs);
BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs);
BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs);

#endif