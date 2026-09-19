#include <stdlib.h>
#include <termios.h>
#include <unistd.h>



struct termios orgi_termios;

void disableRawMode(){
    tcsetattr(STDIN_FILENO, TCIFLUSH, &orgi_termios);
}


void enableRewMode () {
    tcgetattr(STDIN_FILENO, &orgi_termios);
    atexit(disableRawMode);
    
    struct termios raw = orgi_termios;
    raw.c_lflag &= ~(ECHO | ICANON);

    tcgetattr(STDIN_FILENO, &raw);

    raw.c_lflag &= ~(ECHO);
    
    tcsetattr(STDIN_FILENO, TCIFLUSH, &raw);
}

int main() {
    enableRewMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

  return 0;
}
