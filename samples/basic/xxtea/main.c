#include <stdio.h>
#include <string.h>

#include "crypto.h"

int main() {
    const char *text = "Hello World!";
    const char *key = "1234567890";
    size_t len;

    unsigned char *encrypt_data = xxtea_encrypt(text, strlen(text), key, &len);
    char * base64_data = base64_encode(encrypt_data, len);
    printf("%s\n", base64_data);

    char *decrypt_data = xxtea_decrypt(encrypt_data, len, key, &len);
    if (strncmp(text, decrypt_data, len) == 0) {
        printf("success!\n");
    } else {
        printf("fail!\n");
    }

    free(encrypt_data);
    free(decrypt_data);
    free(base64_data);

    return 0;
}
