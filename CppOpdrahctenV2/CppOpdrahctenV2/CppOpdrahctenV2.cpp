
//De rule of 350 is een vuistregel die wordt gebruikt in softwareontwikkeling om te bepalen of een bepaalde klasse te complex is.
//Volgens deze regel mag een klasse niet meer dan 350 regels code bevatten. Het doel van deze regel is om de
//complexiteit van een klasse te beperken en de leesbaarheid,
//onderhoudbaarheid en herbruikbaarheid van de code te verbeteren/

//In dit voorbeeld wordt een klasse genaamd MyClass gedefinieerd. De klasse heeft een
//dynamisch gealloceerd array data en een variabele size. Het volgt de Rule
//of 3 door een destructor, kopieconstructor en toekenning-operator te implementeren.
class MyClass {

private:
    int* data;
    int size;

public:
    // Constructor
    MyClass(int s) : size(s) {
        data = new int[size];
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    // Kopieconstructor
    MyClass(const MyClass& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Toekenning-operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};
