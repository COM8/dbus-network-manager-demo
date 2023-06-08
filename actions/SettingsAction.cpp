#include "actions/SettingsAction.hpp"

#include <iostream>

#include <simppl/dispatcher.h>
#include <simppl/objectpath.h>
#include <simppl/stub.h>

#include "interfaces/SettingsInterface.hpp"

namespace action {
std::vector<simppl::dbus::ObjectPath> getSettingObjectPaths(simppl::dbus::Dispatcher& d) {
    simppl::dbus::Stub<org::freedesktop::NetworkManager::Settings> settings(d, "org.freedesktop.NetworkManager", "/org/freedesktop/NetworkManager/Settings");

    try {
        return settings.ListConnections();
        //return result;
    } catch (std::exception& ex) {
        std::cerr << "Failed to access NetworkManager settings: " << ex.what() << std::endl;
    }
    return {};
}
}  // namespace action