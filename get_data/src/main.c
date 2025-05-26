
#include <stdlib.h>

#include "driver.h"
#include "options.h"


int main(const int argc, char* argv[]) {
    //
    // Parse options
    //
    if (parse_options(argc, argv) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    //
    // Curl init
    //
    if (curl_init() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
