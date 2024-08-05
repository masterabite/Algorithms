/*
  Набор функций, для определения, соответствует ли строка формату числа.
  ссылка на условие: https://leetcode.com/problems/valid-number/submissions/
*/

bool isChar(string& str, size_t& pos, char ch) {
    if (str[pos] == ch) {
        ++pos;
        return true;
    }
    return false;
}

bool isSign(string& str, size_t& pos) {
    if (str[pos] == '+' || str[pos] == '-') {
        ++pos;
        return true;
    }
    return false;
}

bool isDigit(string& str, size_t& pos) {
    if (str[pos] >= '0' && str[pos] <= '9') {
        ++pos;
        return true;
    }
    return false;
}

bool isUnsignedInteger(string& str, size_t& pos) {
    if (isDigit(str, pos)) {
        return true | isUnsignedInteger(str, pos);
    } else {
        return false;
    }
}

bool isInteger(string& str, size_t& pos) {
    isSign(str, pos);
    return isUnsignedInteger(str, pos);
}

bool isExhibitor(string& str, size_t& pos) {

    return 
        (isChar(str, pos, 'E') || isChar(str, pos, 'e')) && 
        isInteger(str, pos);
}


bool isDouble(string& str, size_t& pos) {
    if (isInteger(str, pos)) {
        isChar(str, pos, '.');
        isUnsignedInteger(str, pos);
        return true;
    } else {
        return isChar(str, pos, '.') && isUnsignedInteger(str, pos);
    }
    
}

bool isNumber(string s) {
    size_t pos = 0;
    if (!isDouble(s, pos)) {
        return false;
    }
    return s[pos] == '\0' || (isExhibitor(s, pos) && s[pos] == '\0');
}
