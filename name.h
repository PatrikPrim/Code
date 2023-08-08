#ifndef UNTITLED_NAME_H
#define UNTITLED_NAME_H

#include <iostream>
#include <string>
#include "memtrace.h"

class Name{
private:
    std::string title;
    std::string last_n;
    std::string first_n;
    std::string nick_n;

public:
    //Konstruktorok
    Name();

    Name(const std::string& t, const std::string& ln, const std::string& fn, const std::string& nn);

    Name(const Name& n);

    //Getterek
    std::string getTitle() const;
    std::string getLastN() const;
    std::string getFirstN() const;
    std::string getNickN() const;

    //Setterek
    void setTitle(const std::string& s);
    void setLastN(const std::string& s);
    void setFirstN(const std::string& s);
    void setNickN(const std::string& s);

    //= operator
    Name operator=(const Name& rhs);

    //is in
    bool is_in(const std::string& s);

    //Destruktor
    ~Name();
};

#endif //UNTITLED_NAME_H
