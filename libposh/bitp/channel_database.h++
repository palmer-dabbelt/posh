/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#ifndef LIBPOSH__BITP__CHANNEL_DATABASE_HXX
#define LIBPOSH__BITP__CHANNEL_DATABASE_HXX

#include "channel.h++"
#include "connection.h++"
#include <libposh/database/connection.h++>
#include <list>
#include <string>

namespace libposh {
    namespace bitp {
        class channel_database {
        private:
            database::connection _db;

        public:
            /* There is only one channel database, so this is really more of a
             * connection to the channel database than an outright channel
             * database itself. */
            channel_database(database::connection& db)
            : _db(db)
            {}

            /* Creates a new channel. */
            channel create_channel(const std::list<connection>& c);
        };
    }
}

#endif
