#pragma once

#include <iostream>

class String {
public:
    String();

    String(const char *str);

    String(const char *str, size_t size);

    String(const String &str);

    size_t size() const;

    char getChar(size_t index) const;

    bool empty() const;

    const char *c_str() const;

    void append(const char *str);

    void append(const char *str, size_t count);

    void append(const String &str);

    void assign(const char *str, size_t len);

    void clear();

    void shrink_to_fit();

    void print();

    void println();

    String &operator+=(char c);

    String &operator+=(const char *str);

    String &operator+=(String &str);

    char &operator[](size_t index);

    const char &operator[](size_t index) const;

    String &operator=(const String &str);

    friend bool operator<(const String &a, const String &b);

    friend bool operator==(const String&a, const String& b);

private:
    char *data;
    size_t length;
    size_t capacity;

    void ensure_capacity(size_t count);
};


