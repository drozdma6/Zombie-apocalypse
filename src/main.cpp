#include <iostream>
#include <memory>

#include "CApplication.h"
#include "SRandom.h"

using namespace std;

int main() {
    SRandom::Init();
    try {
        auto interface = make_shared<CInterface>(cin, cout);
        CApplication app(interface);
        app.Run();
        return 0;
    }
    catch (const runtime_error &ex) {
        if (cin.eof()) {
            return 0;
        }
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }
    catch (const logic_error &ex) {
        cerr << "Error: " << ex.what() << endl;
        return 2;
    }
}
