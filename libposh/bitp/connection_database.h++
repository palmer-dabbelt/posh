/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#ifndef LIBPOSH__BITP__CONNECTION_DATABASE_HXX
#define LIBPOSH__BITP__CONNECTION_DATABASE_HXX

#include "connection.h++"
#include <libposh/database/connection.h++>
#include <list>
#include <string>

namespace libposh {
    namespace bitp {
        class connection_database {
        private:
            database::connection _db;

        public:
            /* There is only one connection database, so this is really more of
             * a connection to the connection database than an outright
             * connection database itself. */
            connection_database(database::connection& db)
            : _db(db)
            {}

            /* Finds all the connections that attach to a particular host. */
            std::list<connection> find_by_hostname(std::string hostname);

            /* Creates a new connection to some host. */
            connection connect_to_hostname(std::string hostname);

        };
    }
}

#endif
