extern void sys_write(volatile char *msg);

int main(int argc, char** argv) {
    volatile char *msg = "somE variable length texto\n";
    sys_write(msg);
    return 0;
}
