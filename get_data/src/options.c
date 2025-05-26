#include "options.h"

#include <stdio.h>
#include <stdlib.h>


int parse_options(int argc, char* argv[]) {
    GError* error = nullptr;
    GOptionContext* context = g_option_context_new("- get data");
    g_option_context_add_main_entries(context, entries, nullptr);

    if (!g_option_context_parse(context, &argc, &argv, &error)) {
        fprintf(stderr, "option parsing failed: %s\n", error->message);
        g_error_free(error);
        return EXIT_FAILURE;
    }

    g_option_context_free(context);

    if (output_path == nullptr) {
        fprintf(stderr, "output path not specified\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
