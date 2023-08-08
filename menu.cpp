#include <iostream>
#include <string>
#include "menu.h"
#include "contact.h"
#include "name.h"
#include "memtrace.h"

//Kiirja a menupontokat
void menu::lista() {
    std::cout << "       Valassz ki egy muveletet!" << std::endl << std::endl <<
         "[1] Listazas" << std::endl << "[2] Hozzaadas" << std::endl << "[3] Kereses" << std::endl << "[4] Mentes" << std::endl << "[5] Betoltes" << std::endl
         << "[6] Kilepes" << std::endl << std::endl
         << "---------------------------------------" << std::endl;
}

//Elvegzi az adott menuponthoz szukseges muveleteket
//@param pont: vegrehajtando menupont
//@param phonebook: Telefonkonyv, amin a muveleteket vegzi
void menu::vegrehajt(int pont, Phonebook* phonebook) {
    switch (pont) {
        case 1:
            phonebook->list_all();
            std::cout << std::endl;
            break;
        case 2: {
            std::string title, lastname, firstname, nickname, pnumber, wnumber, address;
            std::cout << "Elonev: ";
            std::cin >> title;
            std::cout << "Vezeteknev: ";
            std::cin >> lastname;
            std::cout << "Keresztnev: ";
            std::cin >> firstname;
            std::cout << "Becenev: ";
            std::cin >> nickname;
            std::cout << "Privat szam: ";
            std::cin >> pnumber;
            std::cout << "Munkahelyi szam: ";
            std::cin >> wnumber;
            std::cout << "Lakcim: ";
            std::cin >> address;
            Name n(title, lastname, firstname, nickname);
            Contact c(n, pnumber, wnumber, address);
            phonebook->add(c);
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::string filter;
            std::cout << "Keresesi feltetel: ";
            std::cin >> filter;
            phonebook->list_searched(filter);
            std::cout << std::endl;
            int tovabbi = 0;
            std::cout << std::endl << "Tovabbi muveletek: " << std::endl << "[1] Szerkesztes" << std::endl << "[2] Torles" <<
            std::endl << "[3] Vissza" << std::endl << std::endl;
            std::cin >> tovabbi;
            switch (tovabbi) {
                case 1: {
                    size_t idx = 0;
                    int adat = 0;
                    std::cout << "Szerkeszteni kivant elem indexe: ";
                    std::cin >> idx;
                    std::cout << std::endl << "Szerkesztendo adat: " << std::endl << "[1] Nev" << std::endl << "[2] Szemelyes szam" <<
                              std::endl << "[3] Munkahelyi szam" << std::endl << "[4] Lakcim" << std::endl << std::endl;
                    switch (adat) {
                        case 1: {
                            std::string title1, lastname1, firstname1, nickname1;
                            std::cout << "Uj elonev: ";
                            std::cin >> title1;
                            std::cout << "Uj vezeteknev: ";
                            std::cin >> lastname1;
                            std::cout << "Uj keresztnev: ";
                            std::cin >> firstname1;
                            std::cout << "Uj becenev: ";
                            std::cin >> nickname1;
                            Name n1(title1, lastname1, firstname1, nickname1);
                            phonebook->editName(n1, idx);
                            break;
                        }
                        case 2: {
                            std::string pnumber1;
                            std::cout << "Uj privat szam: ";
                            std::cin >> pnumber1;
                            phonebook->editPNum(pnumber1, idx);
                            break;
                        }
                        case 3: {
                            std::string wnumber1;
                            std::cout << "Uj munkahelyi szam: ";
                            std::cin >> wnumber1;
                            phonebook->editWNum(wnumber1, idx);
                            break;
                        }
                        case 4: {
                            std::string address1;
                            std::cout << "Uj lakcim: ";
                            std::cin >> address1;
                            phonebook->editAddr(address1, idx);
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    size_t idx_del = 0;
                    std::cout << "Torlendo elem indexe: ";
                    std::cin >> idx_del;
                    phonebook->remove(idx_del);
                    break;
                }
                case 3: {
                    break;
                }
            }
            std::cout << std::endl;
            break;
        }
        case 4: {
            std::string savefile_name;
            std::cout << "Mentesi fajl neve: ";
            std::cin >> savefile_name;
            phonebook->file_write(savefile_name);
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::string loadfile_name;
            std::cout << "Betoltendo fajl neve: ";
            std::cin >> loadfile_name;
            phonebook->file_read(loadfile_name);
            std::cout << std::endl;
            break;
        }
    }
}

//vegtelen ciklusban ujra és ujra meghivja a menupont vegrehajtasat, amig a felhasznalo ki nem lep
void menu::fomenu() {
    Phonebook phonebook;
    int valasztas;
    while (true) {
        menu::lista();
        std::cin >> valasztas;
        if (valasztas==6) {
            return;
        }
        if (valasztas>6 || valasztas<0)
            throw "ervenytelen karakter";
        menu::vegrehajt(valasztas, &phonebook);
    }
}

