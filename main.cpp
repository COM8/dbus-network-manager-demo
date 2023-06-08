#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include <simppl/any.h>
#include <simppl/dispatcher.h>
#include <simppl/map.h>
#include <simppl/objectpath.h>
#include <simppl/tuple.h>
#include <simppl/vector.h>

#include "actions/SettingsAction.hpp"
#include "actions/SettingsConnectionAction.hpp"

void printAny(const simppl::dbus::Any& value) {
    if (value.is<int>()) {
        std::cout << value.as<int>();
    } else if (value.is<uint32_t>()) {
        std::cout << value.as<uint32_t>();
    } else if (value.is<bool>()) {
        std::cout << std::boolalpha << value.as<bool>() << std::noboolalpha;
    } else if (value.is<std::string>()) {
        std::cout << value.as<std::string>();
    } else if (value.is<simppl::dbus::ObjectPath>()) {
        std::cout << value.as<simppl::dbus::ObjectPath>().path;
    } else if (value.is<std::vector<std::string>>()) {
        std::cout << "[ ";

        for (const std::string& v : value.as<std::vector<std::string>>()) {
            std::cout << v << " ";
        }

        std::cout << "]";
    } else if (value.is<std::vector<simppl::dbus::ObjectPath>>()) {
        std::cout << "[ ";

        for (const simppl::dbus::ObjectPath& v : value.as<std::vector<simppl::dbus::ObjectPath>>()) {
            std::cout << v.path << " ";
        }

        std::cout << "]";
    } else if (value.is<std::tuple<uint32_t, uint32_t>>()) {
        auto v = value.as<std::tuple<uint32_t, uint32_t>>();

        std::cout << "{ " << std::get<0>(v) << ", " << std::get<1>(v) << " }";
    } else if (value.is<std::vector<std::map<std::string, simppl::dbus::Any>>>()) {
        auto vec = value.as<std::vector<std::map<std::string, simppl::dbus::Any>>>();

        std::cout << "[ ... ]";  // leave this open for exercise
    } else if (value.is<std::vector<std::vector<uint8_t>>>()) {
        std::cout << "[ ";

        for (const std::vector<uint8_t>& vec : value.as<std::vector<std::vector<uint8_t>>>()) {
            for (const uint8_t& v : vec) {
                std::cout << std::setw(2) << std::hex << std::setfill('0') << static_cast<int>(v) << std::setfill(' ') << std::dec << " ";
            }
        }

        std::cout << "]";
    } else {
        std::cout << "<unresolved>";
    }
}

int main(int /*argc*/, char** /*argv*/) {
    simppl::dbus::Dispatcher d("bus:system");

    std::vector<simppl::dbus::ObjectPath> paths = action::getSettingObjectPaths(d);

    for (const simppl::dbus::ObjectPath& path : paths) {
        try {
            action::connectionResponse_t connection = action::GetConnection(d, path);

            std::cout << path.path << " -> " << connection.fileName << "\n";
            for (const std::pair<const std::string, std::map<std::string, simppl::dbus::Any>>& group : connection.configuration) {
                std::cout << "[" << group.first << "]\n";
                for (const std::pair<const std::string, simppl::dbus::Any>& entry : group.second) {
                    std::cout << "  " << entry.first << " = ";
                    printAny(entry.second);
                    std::cout << "\n";
                }
            }
        } catch (std::exception& ex) {
            std::cerr << "Failed to access NetworkManager Settings: " << ex.what() << std::endl;
        }
        std::cout << "\n";
    }

    return EXIT_SUCCESS;
}