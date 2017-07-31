//ta technika jest przydatna do tworzenia niektórych rodzajów interpreterów lub programów przetwarzających listy
#include <iostream>
using namespace std;

#define DF(N) void N() { \
     cout<<"function " #N<<endl; }
DF(a);
DF(b);
DF(c);
DF(d);
DF(e);
DF(f);
DF(g);

//koncepcja programu sterowanego tabelą
void(*func_table[])() = {a,b,c,d,e,f,g}; //aby wybrać funkcję, wystarczy wybrać indeks tablicy i wyłuskać wskaźnik
                                        //automatyczna inicjalizacja agregatowa
int main() {
    while (1) {
        cout << "Enter letter from a to g or w to finish the program: ";
        char c;
        cin.get(c);
        cin.sync();
        if (c == 'w')
            break;
        if (c < 'a' or c > 'g') {
            cout << "--" << endl;
            continue;
        }
        (*func_table[c - 'a'])();
    }
    return 0;
}
