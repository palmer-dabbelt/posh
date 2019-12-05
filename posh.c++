/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0+ OR BSD-3-Clause */

#include <libposh/bitp/connection_database.h++>
#include <libposh/bitp/channel_database.h++>
#include <libposh/database/connection.h++>
#include <libposh/tty/launch.h++>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <random>

static void show_help_text(std::string name)
{
    std::cerr
        << name << " <hostname>: Another remote shell\n"
        << "    --help                        Prints this help text\n"
        << std::flush;
}

template <typename T>
auto sample(const T& in)
{
    T out;

    std::sample(
        in.begin(), in.end(),
        std::back_inserter(out),
        1,
        std::mt19937{std::random_device{}()}
    );

    return *(out.begin());
}

int main(int argc, const char **argv)
{
    const char *help_argv[] = {argv[0], "--help", nullptr};
    int ret = 0;
    if (argc == 1) {
        argc = 2;
        argv = help_argv;
        ret = 1;
    }

    bool dashdash = false;
    for (int i = 1; i < argc; ++i) {
        auto scn = [&](const char *s) {
            return std::strcmp(argv[i], s) == 0;
        };
        auto ssn = [&](const char *s) {
            return std::strncmp(argv[i], s, strlen(s)) == 0;
        };
        auto avi = [&](int o) {
            if (i+o > argc) {
                std::cerr << argv[i] << " requires an argument, but none provided\n";
                abort();
            }
            return std::string(argv[i+o]);
        };

        if (scn("--help")) {
            show_help_text(argv[0]);
        } else if (scn("--")) {
            dashdash = true;
        } else if (!dashdash && ssn("--")) {
            std::cerr << "Unknown argument " << std::string(argv[i]) << "\n";
            abort();
        } else {
            auto db = libposh::database::connection();
            auto host = avi(1);
            auto conns = [&](){
                auto cdb = libposh::bitp::connection_database(db);
                auto conns = cdb.find_by_hostname(host);
                if (conns.size() > 0)
                    return conns;
                return decltype(conns){cdb.connect_to_hostname(host)};
            }();

            auto shell = [&](){
                auto cdb = libposh::bitp::channel_database(db);
                return libposh::tty::launch(cdb, conns);
            }();
            ret = shell.join();
        }
    }

    return ret;
}
