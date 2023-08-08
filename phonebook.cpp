#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>
#include "memtrace.h"

//konstruktorok
Phonebook::Phonebook(){
    this->size = 0;
    this->contacts = new Contact[size];
}

Phonebook::Phonebook(size_t s){
    this->size = s;
    this->contacts = new Contact[size];
}


//masolo konstruktor
Phonebook::Phonebook(const Phonebook& p) {
    this->size = p.getSize();
    delete[] this->contacts;
    this->contacts = new Contact[p.getSize()];
    for (size_t i = 0; i < size; ++i) {
        this->contacts[i] = p.contacts[i];
    }
}

//egyenloseg operator
//@param rhs: ezzel teszi egyenlove a phonebookot
Phonebook Phonebook::operator=(const Phonebook& rhs) {
    this->size = rhs.getSize();
    delete[] this->contacts;
    this->contacts = new Contact[rhs.getSize()];
    for (size_t i = 0; i < size; ++i) {
        this->contacts[i] = rhs[i];
    }
    return *this;
}

//indexelo operator, visszaadja a megfelelo elemet Contact tipuskent
//@param idx: a kivalasztando elem indexe
Contact Phonebook::operator[](size_t idx) const {
    return this->contacts[idx];
}

//editorok: egy elem megfelelo adatat valtoztatjak meg
//@param n/s: erre valtoztatja meg az adatot
//@param idx: a valtoztatando elem indexe a tombben

void Phonebook::editName(const Name& n, size_t idx) {
    this->contacts[idx].setName(n);
}

void Phonebook::editPNum(const std::string& s, size_t idx) {
    this->contacts[idx].setPNum(s);
}

void Phonebook::editWNum(const std::string& s, size_t idx) {
    this->contacts[idx].setWNum(s);
}

void Phonebook::editAddr(const std::string& s, size_t idx) {
    this->contacts[idx].setAddr(s);
}

//size getter
size_t Phonebook::getSize() const {
    return this->size;
}

//a tomb vegere, a tombot dinamikusan novelve beszur egy elemet
//@param c: a beszurando Contact elem
void Phonebook::add(Contact c) {
    Contact* temp = new Contact[this->size + 1];
    for (size_t i = 0; i < size; ++i) {
        temp[i] = contacts[i];
    }
    temp[size] = c;
    size++;
    delete[] contacts;
    contacts = temp;
}

//beolvas egy fajlt, es az abban levo elemeket a telefonkonyv vegehez hozzafuzi
//@param file_name: a beolvasando fajl neve
void Phonebook::file_read(const std::string& file_name) {
    std::ifstream file(file_name);

    if(!file.is_open())
        throw "Nem lehetett megnyitni a fajlt";

    std::string line;

    for(size_t i=0; getline(file, line); i++)
    {
        std::string substrings[7] = {"", "", "", "", "", "", ""};
        for (int j = 0; j < 7; ++j) {
            substrings[j]=(line.substr(0,line.find(";")));
            line = line.substr(line.find(";")+1, line.size());
        }
        Name temp(substrings[0], substrings[1], substrings[2], substrings[3]);
        Contact toadd(temp, substrings[4], substrings[5], substrings[6]);
        add(toadd);
    }
    file.close();
};

//kiirja egy fajlba a telefonkonyv elemeit
//@param file_name: ebbe a fjalba irja
void Phonebook::file_write(const std::string& file_name) {
    std::ofstream file(file_name);

    if(!file.is_open())
        throw "Nem lehetett megnyitni a fajlt";

    for (size_t i = 0; i < this->size; ++i) {
        file << this->contacts[i] << std::endl;
    }
    file.close();
}

//kilistazza a telefonkonyv osszes elemet
void Phonebook::list_all() {
    for (size_t i = 0; i < this->size; ++i) {
        std::cout << i << " " << this->contacts[i] << std::endl;
    }
}

//kilistazza a telefonkonyv azon elemeit, amiben egy keresett szoveg megtalalhato
//@param s: a keresett string
void Phonebook::list_searched(const std::string& s) {
    for (size_t i = 0; i < this->size; ++i) {
        if(this->contacts[i].is_in(s))
            std::cout << i << " " << this->contacts[i] << std::endl;
    }
}

//kitorol egy elemet a telefonkonyvbol, es csokkenti annak meretet
//@param idx: a kitorlendo elem indexe
void Phonebook::remove(size_t idx) {
    if(idx < 0 || idx >= this->size) throw "Hibas index!";
    for (size_t i = idx; i < this->size-1; ++i) {
        this->contacts[i] = this->contacts[i+1];
    }
    this->size = size-1;
}

//destruktor: felszabaditja a dinamikus tombot
Phonebook::~Phonebook() {
    delete[] contacts;
}