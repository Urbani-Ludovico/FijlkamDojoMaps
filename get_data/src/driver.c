#include "driver.h"

#include <stdlib.h>

CURL* curl_handle = nullptr;

int curl_init() {
    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    if (curl_handle == nullptr) {
        curl_end();
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "Mozilla/5.0");
    curl_easy_setopt(curl_handle, CURLOPT_AUTOREFERER, 1);

    return EXIT_SUCCESS;
}


void curl_end() {
    if (curl_handle != nullptr) {
        curl_easy_cleanup(curl_handle);
    }
    curl_global_cleanup();
}