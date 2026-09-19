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
    raw.c_lflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_lflag &= ~(OPOST);
    raw.c_lflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON| IEXTEN |ISIG);

    tcsetattr(STDIN_FILENO, TCIFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c !='q') {
        if (iscntrl(c)) {
                    printf("%d\r\n", c);
        } else {
        printf("%d ('%c')\r\n", c, c);
        }
    }

    return 0;
}
