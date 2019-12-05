/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#include "connection.h++"
using namespace libposh::database;

std::shared_ptr<struct sqlite3> connection::init_sqlite3(void)
{
    struct sqlite3 *sqlite3;
    auto path = std::string(getenv("HOME")) + "/.posh/db";
    auto err = sqlite3_open(path.c_str(), &sqlite3);
    if (err != SQLITE_OK) {
        perror("Unable to open sqlite database");
        abort();
    }

    sqlite3_busy_timeout(sqlite3, 1000);

    return std::shared_ptr<struct sqlite3>(
        sqlite3,
        [&](auto unused){ sqlite3_close(sqlite3); }
    );
}
