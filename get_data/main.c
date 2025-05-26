
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

static char* output_path = nullptr;

static GOptionEntry entries[] =
{
    { "output", 'o', 0, G_OPTION_ARG_FILENAME, &output_path, "Output file to json file", "FILE" },
    G_OPTION_ENTRY_NULL
  };

int main(int argc, char *argv[]) {
    //
    // Parse options
    //
    GError *error = nullptr;
    GOptionContext* context = g_option_context_new("- get data");
    g_option_context_add_main_entries(context, entries, nullptr);

    if (!g_option_context_parse(context, &argc, &argv, &error)) {
        fprintf(stderr, "option parsing failed: %s\n", error->message);
        g_error_free(error);
        exit(EXIT_FAILURE);
    }

    g_option_context_free(context);

    if (output_path == nullptr) {
        fprintf(stderr, "output path not specified\n");
        exit(EXIT_FAILURE);
    }
}