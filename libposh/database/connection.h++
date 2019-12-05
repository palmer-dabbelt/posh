/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#ifndef LIBPOSH__DATABASE__CONNECTION_HXX
#define LIBPOSH__DATABASE__CONNECTION_HXX

#include <sqlite3.h>
#include <memory>

namespace libposh {
    namespace database {
        /* A connection to the SQLite database. */
        class connection {
        private:
            std::shared_ptr<struct sqlite3> _sqlite3;

        public:
            /* Opens up a new sqlite3 connection. */
            connection(void)
            : _sqlite3(init_sqlite3())
            {}

        private:
            static decltype(_sqlite3) init_sqlite3(void);
        };
    }
}

#endif
