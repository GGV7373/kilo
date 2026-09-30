This is GGV7373's attempt at [antirez's kilo](https://viewsourcecode.org/snaptoken/kilo/).

19.09: Enabled raw mode with termios, restored the terminal on exit with atexit(), added a die() helper for error handling, and added q to quit. Chapter 2 of 8 done.

30.09: Turned raw keypresses into a real editor screen: tildes, a welcome message, and a cursor you can move with the arrow and special keys.
