#include "bigint.hpp"
#include <cstring>
#include <algorithm>
#include <stdexcept>

using biv::LongNumber;

LongNumber::LongNumber() : numbers(nullptr), length(1), sign(1) {
    numbers = new int[1]{0};
}

LongNumber::LongNumber(const char* const str) {
    const char* p = str;
    if (*p == '-') p++;
    if (*p == '\0') throw std::invalid_argument("Empty number string");
    
    while (*p) {
        if (*p < '0' || *p > '9') {
            throw std::invalid_argument("Invalid character in number");
        }
        p++;
    }

    // Определение длины и знака
    const char* num_start = str;
    if (*str == '-') {
        sign = -1;
        num_start++;
    } else {
        sign = 1;
    }

    // Пропуск ведущих нулей
    while (*num_start == '0' && *(num_start+1) != '\0') num_start++;

    length = get_length(str);
    numbers = new int[length];

    // Заполнение массива цифр (в обратном порядке)
    for (int i = 0; i < length; i++) {
        numbers[i] = num_start[length - 1 - i] - '0';
    }

    // Обработка -0
    if (length == 1 && numbers[0] == 0) {
        sign = 1;
    }
}
LongNumber::LongNumber(const LongNumber& x) : length(x.length), sign(x.sign) {
    numbers = new int[length];
    std::copy(x.numbers, x.numbers + length, numbers);
}

LongNumber::LongNumber(LongNumber&& x) : numbers(x.numbers), length(x.length), sign(x.sign) {
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
}

LongNumber::~LongNumber() {
    if (numbers) {
        delete[] numbers;
    }
    numbers = nullptr;
    length = 0;
    sign = 1;
}

LongNumber& LongNumber::operator=(const char* const str) {
    *this = LongNumber(str);
    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
    if (this != &x) {
        if (numbers) {
            delete[] numbers;
        }
        length = x.length;
        sign = x.sign;
        numbers = new int[length];
        std::copy(x.numbers, x.numbers + length, numbers);
    }
    return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& x) {
    if (this != &x) {
        if (numbers) {
            delete[] numbers;
        }
        numbers = x.numbers;
        length = x.length;
        sign = x.sign;
        x.numbers = nullptr;
        x.length = 0;
        x.sign = 1;
    }
    return *this;
}

bool LongNumber::operator==(const LongNumber& x) const {
    if (sign != x.sign || length != x.length) return false;
    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) return false;
    }
    return true;
}

bool LongNumber::operator!=(const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator>(const LongNumber& x) const {
    if (sign != x.sign) return sign > x.sign;
    if (length != x.length) return (length > x.length) == (sign == 1);
    for (int i = length-1; i >= 0; i--) {
        if (numbers[i] != x.numbers[i]) {
            return (numbers[i] > x.numbers[i]) == (sign == 1);
        }
    }
    return false;
}

bool LongNumber::operator<(const LongNumber& x) const {
    return !(*this > x || *this == x);
}

bool LongNumber::operator>=(const LongNumber& x) const {
    return (*this > x) || (*this == x);
}

bool LongNumber::operator<=(const LongNumber& x) const {
    return (*this < x) || (*this == x);
}

LongNumber LongNumber::operator-() const {
    LongNumber result(*this);
    if (result.length != 1 || result.numbers[0] != 0) {
        result.sign = -sign;
    }
    return result;
}

LongNumber LongNumber::operator+(const LongNumber& x) const {
    if (sign == x.sign) {
        LongNumber result;
        result.sign = sign;
        
        int max_len = std::max(length, x.length) + 1;
        result.numbers = new int[max_len]{};
        result.length = max_len;
        
        int carry = 0;
        for (int i = 0; i < max_len; i++) {
            int a = i < length ? numbers[i] : 0;
            int b = i < x.length ? x.numbers[i] : 0;
            int sum = a + b + carry;
            result.numbers[i] = sum % 10;
            carry = sum / 10;
        }
        
        // Удаление ведущих нулей
        while (result.length > 1 && result.numbers[result.length-1] == 0) {
            result.length--;
        }
        
        return result;
    }
    return *this - (-x);
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    if (sign != x.sign) {
        return *this + (-x);
    }
    
    if (sign == -1) {
        return (-x) - (-*this);
    }
    
    bool this_larger = true;
    if (length != x.length) {
        this_larger = length > x.length;
    } else {
        for (int i = length-1; i >= 0; i--) {
            if (numbers[i] != x.numbers[i]) {
                this_larger = numbers[i] > x.numbers[i];
                break;
            }
        }
    }
    
    if (!this_larger) {
        return -(x - *this);
    }
    
    LongNumber result;
    result.sign = 1;
    result.numbers = new int[length]{};
    result.length = length;
    
    int borrow = 0;
    for (int i = 0; i < length; i++) {
        int a = numbers[i];
        int b = i < x.length ? x.numbers[i] : 0;
        int diff = a - b - borrow;
        
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.numbers[i] = diff;
    }
    
    // Удаление ведущих нулей
    while (result.length > 1 && result.numbers[result.length-1] == 0) {
        result.length--;
    }
    
    return result;
}

LongNumber LongNumber::operator*(const LongNumber& x) const {
    LongNumber result;
    result.sign = sign * x.sign;
    result.length = length + x.length;
    result.numbers = new int[result.length]{};
    
    for (int i = 0; i < length; i++) {
        int carry = 0;
        for (int j = 0; j < x.length; j++) {
            int product = numbers[i] * x.numbers[j] + result.numbers[i+j] + carry;
            carry = product / 10;
            result.numbers[i+j] = product % 10;
        }
        if (carry > 0) {
            result.numbers[i + x.length] += carry;
        }
    }
    
    // Удаление ведущих нулей
    while (result.length > 1 && result.numbers[result.length-1] == 0) {
        result.length--;
    }
    
    // Обработка -0
    if (result.length == 1 && result.numbers[0] == 0) {
        result.sign = 1;
    }
    
    return result;
}

LongNumber LongNumber::operator/(const LongNumber& x) const {
    if (x.length == 1 && x.numbers[0] == 0) {
        throw std::runtime_error("Division by zero");
    }
    
    LongNumber dividend(*this);
    dividend.sign = 1;
    LongNumber divisor(x);
    divisor.sign = 1;
    
    if (dividend < divisor) {
        return LongNumber("0");
    }
    
    LongNumber quotient;
    quotient.sign = sign * x.sign;
    quotient.length = length;
    quotient.numbers = new int[quotient.length]{};
    
    LongNumber current;
    for (int i = length - 1; i >= 0; i--) {
        current = current * LongNumber("10") + LongNumber(std::to_string(numbers[i]).c_str());
        
        int digit = 0;
        while (current >= divisor) {
            current = current - divisor;
            digit++;
        }
        
        quotient.numbers[i] = digit;
    }
    
    // Удаление ведущих нулей
    while (quotient.length > 1 && quotient.numbers[quotient.length-1] == 0) {
        quotient.length--;
    }
    
    return quotient;
}

LongNumber LongNumber::operator%(const LongNumber& divisor) const {
    if (divisor == LongNumber("0")) {
        throw std::runtime_error("Division by zero");
    }
    
    LongNumber dividend = *this;
    dividend.sign = 1;
    LongNumber abs_divisor = divisor;
    abs_divisor.sign = 1;
    LongNumber remainder;
    for (int i = dividend.length - 1; i >= 0; i--) {
        remainder = remainder * LongNumber("10") + LongNumber(std::to_string(dividend.numbers[i]).c_str());
        while (remainder >= abs_divisor) {
            remainder = remainder - abs_divisor;
        }
    }

    if (this->is_negative() && remainder != LongNumber("0")) {
        remainder = abs_divisor - remainder;
    }
    
    return remainder;
}

int LongNumber::get_digits_number() const noexcept {
    return length;
}
bool LongNumber::is_negative() const noexcept {
    return sign == -1;
}

namespace biv {
    std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
        if (x.is_negative()) os << '-';
        for (int i = x.get_digits_number() - 1; i >= 0; i--) {
            os << x.numbers[i];
        }
        return os;
    }
}

int LongNumber::get_length(const char* const str) const noexcept {
    const char* p = str;
    if (*p == '-') p++;
    
    while (*p == '0') p++; // Пропускаем ведущие нули
    
    if (*p == '\0') return 1; // Для "0" или "-0"
    
    return static_cast<int>(strlen(p));
}
