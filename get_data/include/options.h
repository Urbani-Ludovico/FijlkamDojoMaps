#ifndef OPTIONS_H
#define OPTIONS_H

[[maybe_unused]] static char* output_path = nullptr;

int parse_options(int argc, char* argv[]);

void options_free();

#endif
