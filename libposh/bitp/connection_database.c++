/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#include "connection_database.h++"
using namespace libposh::bitp;

std::list<connection> connection_database::find_by_hostname(std::string hostname)
{
    throw "unimplemented";
}

connection connection_database::connect_to_hostname(std::string hostname)
{
    throw "unimplemented";
}
