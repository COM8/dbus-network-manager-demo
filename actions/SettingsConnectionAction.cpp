#include "actions/SettingsConnectionAction.hpp"

#include <iostream>
#include <map>

#include <simppl/dispatcher.h>
#include <simppl/objectpath.h>
#include <simppl/stub.h>

#include "interfaces/SettingsConnectionInterface.hpp"

namespace action {
connectionResponse_t GetConnection(simppl::dbus::Dispatcher& d, const simppl::dbus::ObjectPath& path) {
    simppl::dbus::Stub<org::freedesktop::NetworkManager::Settings::Connection> connection(d, "org.freedesktop.NetworkManager", path.path.c_str());

    try {
        return connectionResponse_t{
            connection.GetSettings(), connection.Filename.get()};
    } catch (std::exception& ex) {
        std::cerr << "Failed to access NetworkManager settings: " << ex.what() << std::endl;
    }
    return {};
}
}  // namespace action