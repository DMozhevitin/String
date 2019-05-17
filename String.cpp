#include <cstring>
#include "String.h"

String::String() {
    data = static_cast<char *>(malloc(sizeof(char *)));
    data[0] = '\0';
    length = 0;
    capacity = 1;
}

String::String(const char *str) {
    length = strlen(str);
    capacity = length * 2 + 1;
    data = static_cast<char *>(malloc(sizeof(char *) * capacity));
    for (size_t i = 0; i < length; i++) {
        data[i] = str[i];
    }
    data[length] = '\0';
}

String::String(const char *str, size_t size) {
    __glibcxx_assert(size <= strlen(str));

    length = size;
    capacity = length * 2 + 1;
    data = static_cast<char *>(malloc(sizeof(char *) * capacity));

    for (size_t i = 0; i < length; i++) {
        data[i] = str[i];
    }

    data[length] = '\0';
}

String::String(const String &str) {
    length = str.size();
    capacity = length * 2;
    data = static_cast<char *>(malloc(sizeof(char *) * capacity));

    for (size_t i = 0; i < length; i++) {
        data[i] = str[i];
    }

    data[length] = '\0';
}

size_t String::size() const {
    return length;
}

char String::getChar(size_t index) const {
    __glibcxx_assert(index < size());
    return data[index];
}

bool String::empty() const {
    return length == 0;
}

const char *String::c_str() const {
    return data;
}

void String::append(const char *str) {
    size_t tmp = strlen(str);
    ensure_capacity(tmp);

    for (size_t i = 0; i < tmp; i++) {
        data[length + i] = str[i];
    }

    length += tmp;
    data[length] = '\0';
}

void String::append(const char *str, size_t count) {
    ensure_capacity(count);

    for (size_t i = 0; i < count; i++) {
        data[length + i] = str[i];
    }

    length += count;
    data[length] = '\0';
}

void String::append(const String &str) {
    size_t tmp = str.size();
    ensure_capacity(tmp);

    for (size_t i = 0; i < tmp; i++) {
        data[length + i] = str[i];
    }

    length += tmp;
    data[length] = '\0';
}

void String::assign(const char *str, size_t len) {
    __glibcxx_assert(size <= strlen(str));

    free(data);
    length = len;
    capacity = length * 2 + 1;
    data = static_cast<char *>(malloc(sizeof(char *) * capacity));

    for (size_t i = 0; i < length; i++) {
        data[i] = str[i];
    }

    data[length] = '\0';
}

void String::clear() {
    free(data);
    length = 0;
    capacity = 1;
    data[0] = '\0';
}


void String::shrink_to_fit() {
    capacity = length + 1;
    char *w = static_cast<char *>(malloc(sizeof(char *) * length));
    for (size_t i = 0; i < length; i++) {
        w[i] = data[i];
    }

    free(data);
    data = static_cast<char *>(malloc(sizeof(char *) * capacity));
    for (size_t i = 0; i < length; i++) {
        data[i] = w[i];
    }
    free(w);
}

void String::print() {
    for (size_t i = 0; i < length; i++) {
        std::cout << data[i];
    }
}

void String::println() {
    print();
    std::cout << "\n";
}

void String::ensure_capacity(size_t count) {
    if (length + count + 1 >= capacity) {
        capacity *= 2;
        char *w = static_cast<char *>(malloc(sizeof(char *) * length));
        for (size_t i = 0; i < length; i++) {
            w[i] = data[i];
        }

        free(data);
        data = static_cast<char *>(malloc(sizeof(char *) * capacity));
        for (size_t i = 0; i < length; i++) {
            data[i] = w[i];
        }

        free(w);
        data[length] = '\0';
    }
}

String &String::operator+=(char c) {
    ensure_capacity(1);
    data[length] = c;
    data[++length] = '\0';
    return *this;
}

String &String::operator+=(const char *str) {
    append(str);
    return *this;
}

String &String::operator+=(String &str) {
    append(str);
    return *this;
}

char &String::operator[](size_t index) {
    __glibcxx_assert(index < size());

    return data[index];
}

const char &String::operator[](size_t index) const {
    __glibcxx_assert(index < size());

    return data[index];
}

String &String::operator=(const String &str) {
    free(data);

    length = str.size();
    capacity = length * 2 + 1;
    data = static_cast<char *>(malloc(sizeof(char *) * capacity));

    for (size_t i = 0; i < length; i++) {
        data[i] = str[i];
    }

    data[length] = '\0';

    return *this;
}

bool operator< (const String& a, const String& b) {
    return strcmp(a.data, b.data) == -1;
}

bool operator==(const String&a, const String& b) {
    return strcmp(a.data, b.data) == 0;
}
