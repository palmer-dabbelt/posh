/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#ifndef LIBPOSH__TTY__LAUNCH_HXX
#define LIBPOSH__TTY__LAUNCH_HXX

#include "display.h++"
#include <libposh/bitp/channel_database.h++>

namespace libposh {
    namespace tty {
        /* Launches a TTY, returning the local half. */
        display launch(bitp::channel_database& db,
                       const std::list<bitp::connection>& conns);
    }
}

#endif
