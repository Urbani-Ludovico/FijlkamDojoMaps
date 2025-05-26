
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
        options_free();
        return EXIT_FAILURE;
    }

    curl_end();
    options_free();

    return EXIT_SUCCESS;
}
