#include <iostream>
#include "phonebook.h"
#include "gtest_lite.h"
#include "memtrace.h"


int main() {


    std::cout << "TESZT 1: Contact es Name konstruktorok tesztelese" << std::endl;
    Name n1("Dr", "Bubo", "Janos", "Jani");
    Contact t1(n1, "+36123456789", "+36987654321", "Budapest, Zsak utca 7.");
    if(
            t1.getPNum() == "+36123456789" &&
            t1.getWNum() == "+36987654321" &&
            t1.getAddr() == "Budapest, Zsak utca 7." &&
            t1.getName().getFirstN() == "Janos")
    {
        std::cout << "SIKERES" << std::endl;
    }
    else std::cout << "HIBAS" << std::endl;


    std::cout << std:: endl << "TESZT 2: Contact es Name setterek tesztelese" << std::endl;
    n1.setNickN("Jancsi");
    t1.setName(n1);
    t1.setAddr("Pecs, Hosok tere 12");
    t1.setPNum("+5178365918346");
    t1.setWNum("+1872578126189");
    if(
            t1.getPNum() == "+5178365918346" &&
            t1.getWNum() == "+1872578126189" &&
            t1.getAddr() == "Pecs, Hosok tere 12" &&
            t1.getName().getNickN() == "Jancsi")
    {
        std::cout << "SIKERES" << std::endl;
    }
    else std::cout << "HIBAS" << std::endl;

    std::cout << std::endl << "TESZT 3: Phonebook konstruktor, hozzaadas, listazas tesztelese" << std::endl;
    Phonebook p;
    p.add(t1);
    Name n2("", "Bubo", "Pestis", "Eznemvicces");
    p.add(Contact(n2, "+1237864187", "+48172648176", "Denver, Keszthelyi ut 36."));
    p.add(Contact(Name("Sir", "McCartney", "Paul", "Pali"), "+875236857", "", "London, Tivadar ter 69."));
    if(
            p[0].getPNum() == "+5178365918346" &&
            p[2].getAddr() == "London, Tivadar ter 69."
            )
    {
        std::cout << "SIKERES" << std::endl;
    }
    else std::cout << "HIBAS" << std::endl;

    std::cout << std::endl << "TESZT 4: Editorok operator tesztelese" << std::endl;
    std::cout << std::endl;
    Name n3("Dr", "Polgar", "Jeno", "Hivatal");
    p.editName(n3, 0);
    p.editAddr("Hivatal, A Jenonel", 1);
    p.editPNum("+1746891746", 0);
    p.editWNum("+8317561387", 1);
    if(
            p[0].getPNum() == "+1746891746" &&
            p[1].getAddr() == "Hivatal, A Jenonel" &&
            p[1].getWNum() == "+8317561387" &&
            p[0].getName().getNickN() == "Hivatal"
            )
    {
        std::cout << "SIKERES" << std::endl;
    }
    else std::cout << "HIBAS" << std::endl;

    std::cout << "Listazas tesztje: " << std::endl;
    p.list_all();
    std::cout << std::endl;
    p.list_searched("Jeno");

    std::cout << std::endl << "Gtestes tesztek: " << std::endl;

    p.file_write("teszt.txt");

    TEST(Phonebook_test, del)

        EXPECT_NO_THROW(p.remove(1));
        EXPECT_ANY_THROW(p.remove(100));

    END

    TEST(Phonebook_test, fileio)

        EXPECT_NO_THROW(p.file_write("teszt.txt"));
        EXPECT_ANY_THROW(p.file_read("nemteszt"));
        EXPECT_NO_THROW(p.file_read("teszt.txt"));

    END

    return 0;
}
