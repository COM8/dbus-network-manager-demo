#pragma once

// Do not include in the same file as 'SettingsConnectionInterface.hpp' to prevent name clash between namespace and class.

#include <vector>

#include <simppl/interface.h>
#include <simppl/objectpath.h>
#include <simppl/parameter_deduction.h>
#include <simppl/vector.h>

namespace org::freedesktop::NetworkManager {
INTERFACE(Settings) {
    Method<simppl::dbus::out<std::vector<simppl::dbus::ObjectPath>>> ListConnections;

    Settings()
        : INIT(ListConnections) {}
};
}  // namespace org::freedesktop::NetworkManager
