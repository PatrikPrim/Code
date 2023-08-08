#include "contact.h"
#include <iostream>
#include <string>
#include "memtrace.h"

//konstruktorok
Contact::Contact(): name(), p_num(""), w_num(""), address("") {};

Contact::Contact(const Name& name, const std::string& pnum, const std::string& wnum, const std::string& addr){
    this->name = name;
    this->p_num = pnum;
    this->w_num = wnum;
    this->address = addr;
};

//masolo konstruktor
Contact::Contact(const Contact& c){
    this->name = c.getName();
    this->p_num = c.getPNum();
    this->w_num = c.getWNum();
    this->address = c.getAddr();
}

//getterek

Name Contact::getName() const{
    return this->name;
}

std::string Contact::getPNum() const{
    return this->p_num;
}

std::string Contact::getWNum() const{
    return this->w_num;
}

std::string Contact::getAddr() const{
    return this->address;
}

//setterek

void Contact::setName(const Name& n) {
    this->name=n;
}

void Contact::setPNum(const std::string& num){
    this->p_num = num;
}

void Contact::setWNum(const std::string& num){
    this->w_num = num;
}

void Contact::setAddr(const std::string& addr){
    this->address = addr;
}

//egyenloseg operator
//@param rhs: ezzel teszi egyenlove a contactot
Contact Contact::operator=(const Contact& rhs){
    this->name = rhs.getName();
    this->p_num = rhs.getPNum();
    this->w_num = rhs.getWNum();
    this->address = rhs.getAddr();
    return *this;
}

//igaz erteket ad, ha egy keresett szoveg megtalalhato a contact adatai kozott (akar reszben is)
//@param s: a keresett szoveg
bool Contact::is_in(const std::string& s){
    if(this->name.is_in(s) || this->getPNum().find(s) <= this->getPNum().size() ||
    this->getWNum().find(s) <= this->getWNum().size() || this->getAddr().find(s) <= this->getAddr().size())
        return true;
    return false;
}

//kiirato operator
//@param os: erre a kimenetre ir
//@param c: ezt a Contactot irja ki
std::ostream& operator<<(std::ostream& os, const Contact& c){
    return os << c.getName().getTitle() << ";" << c.getName().getLastN() << ";" << c.getName().getFirstN() <<
              ";" << c.getName().getNickN() << ";" << c.getPNum() << ";" << c.getWNum() << ";" << c.getAddr() << ";";
}

//destruktor
Contact::~Contact(){};








