#pragma once

#include <map>

#include <simppl/any.h>
#include <simppl/interface.h>
#include <simppl/map.h>
#include <simppl/parameter_deduction.h>

namespace org::freedesktop::NetworkManager::Settings {
INTERFACE(Connection) {
    Method<simppl::dbus::out<std::map<std::string, std::map<std::string, simppl::dbus::Any>>>> GetSettings;
    Method<simppl::dbus::in<std::map<std::string, std::map<std::string, simppl::dbus::Any>>>> Update;

    Property<std::string> Filename;

    Connection()
        : INIT(GetSettings),
          INIT(Update),
          INIT(Filename) {
        // NOOP
    }
};
}  // namespace org::freedesktop::NetworkManager::Settings
