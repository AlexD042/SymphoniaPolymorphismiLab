#include <string>
#include <iostream>
#include <vector>


class Instrument {
protected:
    std::string name;
    std::string sound;
    int repetitions;

public:
    Instrument(std::string name, std::string sound, int repetitions) : name(name), sound(sound), repetitions(repetitions) {}

    virtual void play() {
        std::cout << name << ": ";
        for (int i = 0; i < repetitions; ++i) {
            std::cout << sound << (i == repetitions - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
};

class Trumpet : public Instrument {
public:
    Trumpet() : Instrument("Trumpet", "doot", 3) {}
};

class Violin : public Instrument {
public:
    Violin() : Instrument("Violin", "vwa", 5) {}
};

class Piano : public Instrument {
public:
    Piano() : Instrument("Piano", "dee dee", 1) {}
};

class Trombone : public Instrument {
public:
    Trombone() : Instrument("Trombone", "dwooooo~", 1) {}
};

class Singer : public Instrument {
public:
    Singer() : Instrument("Singer", "lah", 6) {}
};

class Orchestra {
private:
    std::vector<Instrument*> instruments;

public:
    void addInstrument(Instrument* i) {
        instruments.push_back(i);
    }

    void play() {
        for (Instrument* i : instruments) {
            i->play();
        }
    }
};

int main() {
    Orchestra o;

    o.addInstrument(new Trumpet);
    o.addInstrument(new Violin);
    o.addInstrument(new Piano);
    o.addInstrument(new Trombone);
    o.addInstrument(new Trumpet);
    o.addInstrument(new Singer);

    o.play();

	return 0;
}