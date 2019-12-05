/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#ifndef LIBPOSH__TTY__LOCAL_HXX
#define LIBPOSH__TTY__LOCAL_HXX

#include <libposh/bitp/channel_database.h++>

namespace libposh {
    namespace tty {
        /* The display side of a TTY. */
        class display {
        private:
            bitp::channel _channel;

        public:
            /* Creates the display half of a TTY. */
            display(bitp::channel channel)
            : _channel(channel)
            {}

            /* Waits for the remote to terminate and send back the response,
             * continuing to forward the  */
            int join(void);
        };
    }
}

#endif
