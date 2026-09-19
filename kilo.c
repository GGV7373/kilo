#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>



struct termios orgi_termios;

void disableRawMode(){
    tcsetattr(STDIN_FILENO, TCIFLUSH, &orgi_termios);
}


void enableRawMode () {
    tcgetattr(STDIN_FILENO, &orgi_termios);
    atexit(disableRawMode);
    
    struct termios raw = orgi_termios;
    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCIFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c !='q') {
        if (iscntrl(c)) {
                    printf("%d\n", c);
        } else {
        printf("%d\n ('%c')\n", c, c);
        }
    }

    return 0;
}
