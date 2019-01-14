/**
 * @file ServiceException.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServiceException.hpp"
#include <string.h>

using namespace std;
using namespace server;

ServiceException::ServiceException (HttpStatus status, std::string msg)
    : httpStatus(status),msg(msg) {
}

HttpStatus ServiceException::status () const {
    return httpStatus;
}

const char* ServiceException::what () const noexcept (false){
    return msg.c_str();
}
