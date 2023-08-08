#ifndef UNTITLED_CONTACT_H
#define UNTITLED_CONTACT_H

#include <iostream>
#include <string>
#include "name.h"
#include "memtrace.h"

class Contact
{
private:
    Name name;
    std::string p_num;
    std::string w_num;
    std::string address;
public:
    //Konstruktor
    Contact();

    Contact(const Name& name, const std::string& pnum, const std::string& wnum, const std::string& addr);

    Contact(const Contact& c);

    //Getter
    Name getName() const;
    std::string getPNum() const;
    std::string getWNum() const;
    std::string getAddr() const;

    //Setter
    void setName(const Name& n);
    void setPNum(const std::string& num);
    void setWNum(const std::string& num);
    void setAddr(const std::string& addr);

    //= operator
    Contact operator=(const Contact& rhs);

    //is in
    bool is_in(const std::string& s);

    //Destruktor
    ~Contact();
};

std::ostream& operator<<(std::ostream& os, const Contact& c);

#endif //UNTITLED_CONTACT_H
