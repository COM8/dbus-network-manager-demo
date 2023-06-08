#pragma once

#include <vector>

#include "simppl/dispatcher.h"
#include "simppl/objectpath.h"

namespace action {
std::vector<simppl::dbus::ObjectPath> getSettingObjectPaths(simppl::dbus::Dispatcher& d);
}  // namespace action