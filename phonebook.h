#ifndef UNTITLED_PHONEBOOK_H
#define UNTITLED_PHONEBOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include "contact.h"
#include "memtrace.h"

class Phonebook
{
private:
    size_t size;
    Contact* contacts;

public:
    //Konstruktorok
    Phonebook();

    Phonebook(size_t s);

    Phonebook(const Phonebook& p);

    size_t getSize() const;

    Phonebook operator=(const Phonebook& rhs);

    Contact operator[](size_t idx) const;

    void editName(const Name& n, size_t idx);

    void editPNum(const std::string& s, size_t idx);

    void editWNum(const std::string& s, size_t idx);

    void editAddr(const std::string& s, size_t idx);

    //Hozzaado fuggveny
    void add(Contact c);

    //Torlo fuggveny
    void remove(size_t idx);

    //Fajlba iro/Fajlbol olvaso fuggvenyek
    void file_read(const std::string& file_name);

    void file_write(const std::string& file_name);

    //Listazo fuggvenyek
    void list_all();

    void list_searched(const std::string& s);

    //Destruktor
    ~Phonebook();
};

#endif //UNTITLED_PHONEBOOK_H
