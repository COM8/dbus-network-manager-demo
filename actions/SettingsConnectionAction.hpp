#pragma once

#include <map>

#include "simppl/any.h"
#include "simppl/dispatcher.h"
#include "simppl/objectpath.h"

namespace action {
struct connectionResponse_t {
    std::map<std::string, std::map<std::string, simppl::dbus::Any>> configuration;
    std::string fileName;
} __attribute__((aligned(128)));

connectionResponse_t GetConnection(simppl::dbus::Dispatcher& d, const simppl::dbus::ObjectPath& path);
}  // namespace action