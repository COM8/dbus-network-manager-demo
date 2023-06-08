#pragma once

#include <vector>

#include <simppl/interface.h>
#include <simppl/objectpath.h>
#include <simppl/parameter_deduction.h>
#include <simppl/vector.h>

namespace org::freedesktop::NetworkManager {
INTERFACE(Settings) {
    Method<simppl::dbus::out<std::vector<simppl::dbus::ObjectPath>>> ListConnections;

    Settings()
        : INIT(ListConnections) {
        // NOOP
    }
};
}  // namespace org::freedesktop::NetworkManager
