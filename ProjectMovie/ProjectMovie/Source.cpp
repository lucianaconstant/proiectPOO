#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

/* declarare si implementare clasa film */
class Film
{
private:
    const int id;
    char* denumire;
    int nrActori;
    int* varsteActori;
    static int contor;
public:
    /* Constructor fara parametrii */
    Film() :id(contor++)
    {
        this->nrActori = 0;
        this->denumire = nullptr;
        this->varsteActori = nullptr;
    }
    /* Constructor cu parametrii */
    Film(const char* denumire, int nrActori, int* varsteActori) :id(contor++)
    {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        this->nrActori = nrActori;
        this->varsteActori = new int[this->nrActori];
        for (int i = 0; i < this->nrActori; i++)
            this->varsteActori[i] = varsteActori[i];
    }
    /* contructor de copiere */
    Film(const Film& f) :id(contor++)
    {
        this->denumire = new char[strlen(f.denumire) + 1];
        strcpy_s(this->denumire, strlen(f.denumire) + 1, f.denumire);
        this->nrActori = f.nrActori;
        this->varsteActori = new int[this->nrActori];
        for (int i = 0; i < this->nrActori; i++)
            this->varsteActori[i] = f.varsteActori[i];
    }

    /* operator egal */
    Film operator =(const Film& f)
    {
        if (this->denumire != nullptr)
            delete[] this->denumire;
        if (this->varsteActori != nullptr)
            delete[] this->varsteActori;
        this->denumire = new char[strlen(f.denumire) + 1];
        strcpy_s(denumire, strlen(f.denumire) + 1, f.denumire);
        this->nrActori = f.nrActori;
        this->varsteActori = new int[this->nrActori];
        for (int i = 0; i < this->nrActori; i++)
            this->varsteActori[i] = f.varsteActori[i];
        return*this;
    }

    /* setteri si getteri */
    void setDenumire(const char* denumirenoua)
    {
        this->denumire = new char[strlen(denumirenoua) + 1];
        strcpy_s(this->denumire, strlen(denumirenoua) + 1, denumirenoua);
    }

    /* getter denumire */
    char* getDenumire()
    {
        return this->denumire;
    }

    /* setter nr actori */
    void setNrActori(int nrNou)
    {
        this->nrActori = nrNou;
    }

    /* getter nr actori */
    int getNrActori()
    {
        return this->nrActori;
    }

    /* getter varste actori */
    int* getVarsteActori()
    {
        for (int i = 0; i < this->nrActori; i++)
            return this->varsteActori;
    }

    /* setter varste actori */
    void setVarsteActori(int nrActori, int* varste) {
        if (varsteActori != nullptr)
            delete[] this->varsteActori;
        this->varsteActori = new int[nrActori];
        for (int i = 0; i < nrActori; i++) {
            this->varsteActori[i] = varste[i];
        }
    }

    /* supraincarcarea operatorul index */
    int& operator[](int index)
    {
        if (index > 0 && index < nrActori) return varsteActori[index];
        else throw new exception("index incorect");
    }

    /* supraincarcarea operatorul + */
    Film operator+(Film f)
    {
        Film temp = *this;
        temp.nrActori = this->nrActori + f.nrActori;
        return temp;
    }

    /* supraincarcarea operatorul ++ */
    Film operator++()
    {
        this->nrActori++;
        return*this;
    }

    /* supraincarcarea operator ++ */
    Film operator++(int)
    {
        Film temp = *this;
        this->nrActori++;
        return temp;
    }

    /* supraincarcarea operator int() (castare) */
    operator int()
    {
        return nrActori;
    }

    /* supraincarcarea operator ! (not) */
    bool operator!()
    {
        return nrActori <= 0;
    }

    /* supraincarcarea operator == */
    bool operator ==(Film f)
    {
        return denumire == f.denumire;
    }

    /* supraincarcarea operator >= */
    bool operator >=(Film f)
    {
        return this->nrActori >= f.nrActori;
    }

    /* destructor */
    ~Film()
    {

        if (this->denumire != nullptr)
            delete[] this->denumire;
        if (this->varsteActori != nullptr)
            delete[] this->varsteActori;
        contor--;
    }

    /* supraincarcarea operator << (afisare stdout) */
    friend void operator <<(ostream& iesire, Film f);

    /* supraincarcarea operator >> (citire stdin) */
    friend istream& operator >>(istream& intrare, Film& f);

};
/* initializare camp static contor = 0 */
int Film::contor = 0;

/* implementare operator << */
void operator <<(ostream& out, Film f)
{
    out << f.denumire << endl << f.nrActori << endl;
    for (int i = 0; i < f.nrActori; i++)
        out << f.varsteActori[i];
    out << endl;
}

/* implementare operator >> */
istream& operator >> (istream& in, Film& f)
{
    char temp[30];
    cout << "Dati denumire film" << " ";
    in >> temp;
    f.setDenumire(temp);
    cout << "Dati numar actori" << " ";
    in >> f.nrActori;
    for (int i = 0; i < f.nrActori; i++)
    {
        cout << "Dati numar filme" << " ";
        in >> f.varsteActori[i];
    }
    return in;
}

/* declarare si implementare clasa bilet */
class Bilet
{
private:
    const int id;
    char* metodaPlata;
    int nrSpectatori;
    float* pretBilet;
    static int TVA;
public:
    /* constructor fara parametru */
    Bilet():id(TVA++)
    {
        this->nrSpectatori = 0;
        this->metodaPlata = nullptr;
        this->pretBilet = nullptr;
    }

    /* constructor fara parametru */
    Bilet(const char* metodaPlata, int nrSpectatori, float* pretBilet):id(TVA++)
    {
        this->metodaPlata = new char[strlen(metodaPlata) + 1];
        strcpy_s(this->metodaPlata, strlen(metodaPlata) + 1, metodaPlata);
        this->nrSpectatori = nrSpectatori;
        this->pretBilet = new float[nrSpectatori];
        for (int i = 0; i < nrSpectatori; i++) {
            this->pretBilet[i] = pretBilet[i];
        }
    }

    /* constructor de copiere */
    Bilet(const Bilet& b) :id(TVA++)
    {
        this->metodaPlata = new char[strlen(b.metodaPlata) + 1];
        strcpy_s(metodaPlata, strlen(b.metodaPlata) + 1, b.metodaPlata);
        this->nrSpectatori = b.nrSpectatori;
        this->pretBilet = new float[nrSpectatori];
        for (int i = 0; i < nrSpectatori; i++) {
            this->pretBilet[i] = b.pretBilet[i];
        }
    }

    /* suprascriere operator = */
    Bilet operator=(const Bilet& b)
    {
        if (this->metodaPlata == nullptr)
            delete[] this->metodaPlata;
        if (this->pretBilet)
            delete[] this->pretBilet;
        this->metodaPlata = new char[strlen(b.metodaPlata) + 1];
        strcpy_s(metodaPlata, strlen(b.metodaPlata) + 1, b.metodaPlata);
        this->nrSpectatori = b.nrSpectatori;
        this->pretBilet = new float[nrSpectatori];
        for (int i = 0; i < nrSpectatori; i++) {
            this->pretBilet[i] = b.pretBilet[i];
        }
        return *this;
    }

    /* destructor */
    ~Bilet()
    {
        delete[] this->metodaPlata;
        delete[] this->pretBilet;
        TVA--;
    }

    /* setter numar spectatori*/
    void setNrSpectatori(int nrSpectatori)
    {
        if (nrSpectatori > 0) {
            this->nrSpectatori = nrSpectatori;
        }
    }

    /* getter nr spectator */
    int getNrSpectatori() {
        return nrSpectatori;
    }

    /* getter metoda plata */
    char* getMetodaPlata()
    {
        return this->metodaPlata;
    }

    /* setter metoda plata */
    void setMetodaPlata(const char* metodaPlata)
    {
        if (strlen(metodaPlata) > 2) {
            if (metodaPlata != nullptr)
                delete[] metodaPlata;
            this->metodaPlata = new char[strlen(metodaPlata) + 1];
            strcpy_s(this->metodaPlata, strlen(metodaPlata) + 1, metodaPlata);
        }
    }

    /* getter pret bilet */
    float* getPretBilet()
    {
        return this->pretBilet;
    }

    /* setter pret bilet */
    void setPretBilet(int nrSpectatori, float* pret) {
        if (pretBilet != nullptr)
            delete[] this->pretBilet;
        this->pretBilet = new float[nrSpectatori];
        for (int i = 0; i < nrSpectatori; i++) {
            this->pretBilet[i] = pret[i];
        }
    }

    /* supraincarcarea operator [] (index) */
    float& operator[](int index)
    {
        if (index < nrSpectatori && index >= 0)
        {
            return this->pretBilet[index];
        }
        else {
            throw new exception("index incorect");
        }
    }

    /* supraincarcarea operator ++ */
    Bilet operator++() {
        for (int i = 0; i < this->nrSpectatori; i++) {
            this->pretBilet[i]++;
        }
        return *this;
    }

    /* supraincarcarea operator ++ */
    Bilet operator++(int) {
        Bilet temporar = *this;
        for (int i = 0; i < this->nrSpectatori; i++) {
            this->pretBilet[i]++;
        }
        return temporar;
    }

    /* supraincarcarea operator castare int() */
    explicit operator int() {
        return this->nrSpectatori;
    }

    /* supraincarcarea operator + */
    Bilet operator+(Bilet b)
    {
        Bilet suma = *this;
        suma.nrSpectatori = this->nrSpectatori + b.nrSpectatori;
        return suma;
    }
    
    /* supraincarcarea operator ! (not) */
    bool operator!()
    {
        if (this->nrSpectatori > 0)
            return true;
        else return false;
    }

    /* supraincarcarea operator == ( egalitate ) */
    bool operator == (Bilet& b)
    {
        return strcmp(this->metodaPlata, b.metodaPlata) == 0;
    }

    /* supraincarcarea operator > */
    bool operator >(Bilet b) {
        return this->nrSpectatori > b.nrSpectatori;
    }

    /* supraincarcarea operator << ( afisare stdout ) */
    friend void operator<< (ostream& out, Bilet b);

    /* supraincarcarea operator >> ( citire stdin ) */
    friend istream& operator >> (istream& in, Bilet& b);

};
/* initializarea campului static TVA cu 0 */
int Bilet::TVA = 0;

/* implementare suprascriere operator << */
void operator <<(ostream& out, Bilet b)
{
    out << b.metodaPlata << endl << b.nrSpectatori << endl;
    for (int i = 0; i < b.nrSpectatori; i++)
        out << b.pretBilet[i] << endl;
    out << endl;
}

/* implementare suprascriere operator >> */
istream& operator >> (istream& in, Bilet& b)
{
    char temp[30];
    cout << "Dati metoda plata bilet" << " ";
    in >> temp;
    b.setMetodaPlata(temp);
    cout << "Dati numar spectatori" << " ";
    in >> b.nrSpectatori;
    for (int i = 0; i < b.nrSpectatori; i++)
    {
        cout << "Dati pret bilet" << " ";
        in >> b.pretBilet[i];
    }
    return in;
}

/* Declarare si implementare clasa cinematograf*/
class Cinematograf
{
private:
    const int id;
    char* nume;
    int nrSali;
    int* nrLocuriSala;
    static int autogenerator;
public:
    /* constructor fara parametrii */
    Cinematograf() :id(autogenerator++)
    {
        this->nrSali = 0;
        this->nume = nullptr;
        this->nrLocuriSala = nullptr;
    }

    /* constructor cu parametru */
    Cinematograf(const char* nume, int nrSali, int* nrLocuriSala) :id(autogenerator++)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->nrSali = nrSali;
        this->nrLocuriSala = new int[this->nrSali];
        for (int i = 0; i < this->nrSali; i++)
            this->nrLocuriSala[i] = nrLocuriSala[i];

    }

    /* constructor de copiere */
    Cinematograf(const Cinematograf& c) :id(autogenerator++)
    {
        this->nume = new char[strlen(c.nume) + 1];
        strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
        this->nrSali = c.nrSali;
        this->nrLocuriSala = new int[this->nrSali];
        for (int i = 0; i < this->nrSali; i++)
            this->nrLocuriSala[i] = c.nrLocuriSala[i];
    }

    /* suprascriere operator = */
    Cinematograf operator=(const Cinematograf& c)
    {
        if(this->nume != nullptr)
            delete[] this->nume;
        if(this->nrLocuriSala != nullptr)
            delete[] this->nrLocuriSala;
        this->nume = new char[strlen(c.nume) + 1];
        strcpy(nume, c.nume);
        this->nrSali = c.nrSali;
        this->nrLocuriSala = new int[this->nrSali];
        for (int i = 0; i < this->nrSali; i++)
            this->nrLocuriSala[i] = c.nrLocuriSala[i];
        return*this;
    }

    /* setter nume */
    void setNume(const char* numeNou)//setteri si getteri
    {
        this->nume = new char[strlen(numeNou) + 1];
        strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);
    }
    
    /* getter nume */
    char* getNume()
    {
        return this->nume;
    }

    /* setter nr sali */
    void setNrSali(int nr)
    {
        this->nrSali = nr;
    }

    /* getter nr sali */
    int getNrSali()
    {
        return this->nrSali;
    }

    /* getter nr locuri sala */
    int* getNrLocuriSala()
    {
        for (int i = 0; i < this->nrSali; i++)
            return this->nrLocuriSala;
    }

    /* setter nr locuri sala */
    void setNrLocuriSala(int nrSali, int* locuri) {
        if (nrLocuriSala != NULL)
            delete[]this->nrLocuriSala;
        this->nrLocuriSala = new int[nrSali];
        for (int i = 0; i < nrSali; i++) {
            this->nrLocuriSala[i] = locuri[i];
        }
    }

    /* supraincarcarea operator [] (index) */
    int& operator[](int index) //operatorul index
    {
        if (index > 0 && index < nrSali) return nrLocuriSala[index];
        else throw"index incorect";
    }

    /* supraincarcarea operator + */
    Cinematograf operator+(Cinematograf aux)
    {
        Cinematograf temp = *this;
        temp.nrSali = this->nrSali + aux.nrSali;
        return temp;
    }

    /* supraincarcarea operatorului ++ */
    Cinematograf operator++()
    {
        this->nrSali++;
        return*this;
    }

    /* supraincarcare operator ++ */
    Cinematograf operator++(int)
    {
        Cinematograf temp = *this;
        this->nrSali++;
        return temp;
    }

    /* supraincarcare operator int() (castare) */
    operator int()
    {
        return nrSali;
    }

    /* supraincarcare operator ! (not) */
    bool operator!()
    {
        if (nrSali > 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    /* supraincarcare operator == */
    bool operator == (Cinematograf c)
    {
        return strcmp(this->nume, c.nume) == 0;
    }
    
    /* supraincarcare operator >= */
    bool operator >=(Cinematograf c)
    {
        return this->nrSali >= c.nrSali;
    }

    /* destructor */
    ~Cinematograf()
    {
        delete[] this->nume;
        delete[] this->nrLocuriSala;
    }

    /* supraincarcarea operatorului << (afisare stdout) */
    friend void operator <<(ostream& out, Cinematograf c);

    /* supraincarcarea operatorului >> (citire stdin) */
    friend istream& operator >> (istream& in, Cinematograf& c);
};

/* initializarea variabilei statice autogenerator cu 0 */
int Cinematograf::autogenerator = 0;

/* implementarea operatorului << */
void operator <<(ostream& out, Cinematograf c)
{
    out << c.nume << endl << c.nrSali << endl;
    for (int i = 0; i < c.nrSali; i++)
        out << c.nrLocuriSala[i] << endl;
    out << endl;
}

/* implementarea operatorului >> */
istream& operator >> (istream& in, Cinematograf& c)
{
    char aux[30];
    cout << "Dati nume cinematografului" << " ";
    in >> aux;
    c.setNume(aux);
    cout << "Dati numar sali" << " ";
    in >> c.nrSali;
    for (int i = 0; i < c.nrSali; i++)
    {
        cout << "Dati numar locuri per sala" << " ";
        in >> c.nrLocuriSala[i];
    }
    return in;
}


int main()
{
    Film f1;
    cout << f1;
    int vector[2];
    vector[0] = 2;
    vector[1] = 6;
    Film f2("Prison break", 2, vector);
    cout << f2;
    Film f3 = f2;
    cout << f3;
    Film f4;
    f4 = f1;
    cout << f4;
    f2.setDenumire("Hulk");
    cout << f2.getDenumire();


    Bilet b1;
    cout << b1;
    Bilet b2("cash", 2, new float[2]{ 22, 24 });
    cout << b2;
    Bilet b3 = b2;
    cout << b3;
    Bilet b4;
    b4 = b1;
    b2.setMetodaPlata("card");
    cout << b2.getMetodaPlata();


    Cinematograf c1;
    cout << c1;
    Cinematograf c2("Cinema", 2, vector);
    cout << c2;
    Cinematograf c3 = c2;
    cout << c3;
    Cinematograf c4;
    c4 = c1;
    cout << c4;
    c2.setNume("Arta");
    cout << c2.getNume();
       
    return 0;
}

