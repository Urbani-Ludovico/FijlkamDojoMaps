#ifndef OPTIONS_H
#define OPTIONS_H

#include <glib.h>

static char* output_path = nullptr;

static GOptionEntry entries[] = {{"output", 'o', 0, G_OPTION_ARG_FILENAME, &output_path, "Output file to json file", "FILE"}, G_OPTION_ENTRY_NULL};

auto const URL = "https://www.fijlkam.it/dove-siamo/societ%C3%A0.html?cerca-societa=Cerca&start=";

int parse_options(int argc, char* argv[]);

#endif
