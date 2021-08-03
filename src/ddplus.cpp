#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "misc.hpp"
#include "option.hpp"
#include "target.hpp"

int main(int argc, char* argv[])
{
    param param;
    option_parser parser(argc, argv);
    if(parser.parse_cmdopt(param)){
        ERROR(argv[0], "");
    }

    off_t offset = 1024 * 1024 * 1024;
    size_t length = 4096u;
    target mem("/dev/mem", static_cast<std::size_t>(offset), length);
    target out(1);
    mem.transfer_to(out);

    return 0;
}

// vim: expandtab shiftwidth=0 tabstop=4 :