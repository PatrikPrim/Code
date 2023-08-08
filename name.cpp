#include "name.h"
#include <iostream>
#include <string>
#include "memtrace.h"

//konstruktorok
Name::Name(): title(""), last_n(""), first_n(""), nick_n(""){};

Name::Name(const std::string& t, const std::string& ln, const std::string& fn, const std::string& nn){
    this->title = t;
    this->last_n = ln;
    this->first_n = fn;
    this->nick_n = nn;
};

//masolo konstruktor
Name::Name(const Name& n){
    this->title = n.getTitle();
    this->last_n = n.getLastN();
    this->first_n = n.getFirstN();
    this->nick_n = n.getNickN();
};

//Getterek

std::string Name::getTitle() const{
    return this->title;
};
std::string Name::getLastN() const{
    return this->last_n;
}
std::string Name::getFirstN() const{
    return this->first_n;
}
std::string Name::getNickN() const{
    return this->nick_n;
}

//Setterek

void Name::setTitle(const std::string& s){
    this->title = s;
}
void Name::setLastN(const std::string& s){
    this->last_n = s;
}
void Name::setFirstN(const std::string& s){
    this->first_n = s;
}
void Name::setNickN(const std::string& s){
    this->nick_n = s;
}

//egyenloseg operator
//@param rhs: ezzel teszi egyenlove a Name-t
Name Name::operator=(const Name& rhs){
    this->title = rhs.getTitle();
    this->last_n = rhs.getLastN();
    this->first_n = rhs.getFirstN();
    this->nick_n = rhs.getNickN();
    return *this;
}

//igaz erteket ad, ha egy keresett szoveg megtalalhato a nevben (akar reszben is)
//@param s: a keresett szoveg
bool Name::is_in(const std::string& s){
    std::string fullname = this->getTitle() + " " + this->getLastN() + " " + this->getFirstN() + " " + this->getNickN();
    if(fullname.find(s) <= fullname.size())
        return true;
    return false;
}

//Destruktor
Name::~Name(){};