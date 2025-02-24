char* fmt(uint8_t value, char pad) {
    static char buffer[4];
    int pos = 3;
    buffer[pos] = '\0';

    if (value == 0) {
        buffer[--pos] = '0';
    } else {
        while (value > 0 && pos > 0) {
            buffer[--pos] = (value % 10) + '0';
            value /= 10;
        }
    }
    return &buffer[pos];
}
