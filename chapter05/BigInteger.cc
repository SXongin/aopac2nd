#include "BigInteger.hpp"
#include <iomanip>

BigInteger& BigInteger::operator=(long long num)
{
    number.clear();
    do {
        number.push_back(num % kBase);
        num /= kBase;
    } while (num > 0);
    return *this;
}

BigInteger& BigInteger::operator=(const std::string& str)
{
    number.clear();
    if (str == "") {
        number.push_back(0);
        return *this;
    }
    int len = (str.size() - 1) / kWidth + 1;
    for (int i = 0; i < len; ++i) {
        int end   = str.size() - i * kWidth;
        int start = std::max(0, end - kWidth);
        number.push_back(std::stoi(str.substr(start, end - start)));
    }
    this->remove_ahead_zero();
    return *this;
}

void BigInteger::remove_ahead_zero()
{
    while (number.size() > 1 && number.back() == 0) {
        number.pop_back();
    }
}

std::ostream& operator<<(std::ostream& os, const BigInteger& big_integer)
{
    auto itr = big_integer.number.rbegin();
    os << *itr;
    char old_char = os.fill('0');
    for (++itr; itr != big_integer.number.rend(); ++itr) {
        os << std::setw(BigInteger::kWidth) << *itr;
    }
    os.fill(old_char);
    return os;
}

std::istream& operator>>(std::istream& is, BigInteger& big_integer)
{
    std::string str;
    if (!(is >> str)) return is;
    big_integer = str;
    big_integer.remove_ahead_zero();
    return is;
}

BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs)
{
    BigInteger result;
    result.number.clear();
    for (int i = 0, c = 0;; ++i) {
        if (c == 0 && i >= lhs.number.size() && i >= rhs.number.size()) break;
        if (i < lhs.number.size()) c += lhs.number[i];
        if (i < rhs.number.size()) c += rhs.number[i];
        result.number.push_back(c % BigInteger::kBase);
        c /= BigInteger::kBase;
    }
    result.remove_ahead_zero();
    return result;
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs) { return *this = *this + rhs; }

BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs)
{
    BigInteger result;
    result.number.clear();
    for (int i = 0, c = 0;; ++i) {
        if (c == 0 && i >= lhs.number.size() && rhs.number.size()) break;
        if (i < lhs.number.size()) c += lhs.number[i];
        if (i < rhs.number.size()) c += -rhs.number[i];
        if (c < 0) {
            c += BigInteger::kBase;
            result.number.push_back(c);
            c = -1;
        } else {
            result.number.push_back(c);
            c = 0;
        }
    }
    result.remove_ahead_zero();
    return result;
}

BigInteger BigInteger::multi_int_at_index(const int integer, const int index) const
{
    BigInteger result;
    result.number.clear();
    for (int i = 0; i < index; ++i) {
        result.number.push_back(0);
    }
    for (int i = 0, c = 0;; ++i) {
        if (c == 0 && i >= number.size()) break;
        if (i < number.size()) c += number[i] * integer;
        result.number.push_back(c % kBase);
        c /= kBase;
    }
    result.remove_ahead_zero();
    return result;
}

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs)
{
    BigInteger result;
    for (int i = 0; i < rhs.number.size(); ++i) {
        result += lhs.multi_int_at_index(rhs.number[i], i);
    }
    result.remove_ahead_zero();
    return result;
}
