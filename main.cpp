#include <cstdlib>
#include <iostream>

#include <simppl/dispatcher.h>

int main(int /*argc*/, char** /*argv*/) {
    simppl::dbus::Dispatcher d("bus:system");

    return EXIT_SUCCESS;
}