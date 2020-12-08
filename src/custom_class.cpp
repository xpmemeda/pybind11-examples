#ifndef _CUSTOM_CLASS_H_
#define _CUSTOM_CLASS_H_

#include <string>
#include "custom_class.h"


Pet::Pet(const std::string& name) : _name(name), public_name(name) {}
void Pet::setName(const std::string& name) { _name = name; }
const std::string& Pet::getName() const { return _name; }

#endif