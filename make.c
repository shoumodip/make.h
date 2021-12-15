#include "make.h"

#define CC "cc"
#define CFLAGS "-Wall", "-Wextra", "-std=c11", "-pedantic"

int main(int argc, char **argv)
{
    make_rebuild(argc, argv);
    make_assert(argc > 1, "no subcommand provided");

    if (strcmp(argv[1], "build") == 0) {
        make_cc("sample", "sample.c", CFLAGS, "-Werror");
    } else if (strcmp(argv[1], "run") == 0) {
        make_cc("sample", "sample.c", CFLAGS, "-Werror");
        make_cmd("./sample");
    } else {
        make_error("unknown subcommand `%s`", argv[1]);
    }
}
