# TOP3BYTES
A tiny C program that finds the 3 biggest bytes. For example if you have a file like this:\
`0x65, 0x98, 0xFF, 0x99, 0x47, 0x00`\
The program will return this:
```
0xFF
0x99
0x98
```
As their integer value is the biggest.
### Random files
You can generate 200 million bytes of shit and test it. On my old server it runs at about 180 MB/s on a random file.
### Usage
It will say if you used it wrong, but you will like to follow there steps:
1. Create "top3bytes.c" in the current directory.
2. Compile it: `gcc -Wall -Wextra -O2 -o top3bytes top3bytes.c`
3. Run it on any of your files: `./top3bytes `
### Moments
On random files it will most likely answer like this:
```
0xFF
0xFE
0xFD
```
That's not a bug, that's just how binary files work.
### Why do you need that?
It can be useful if you want to know the real data type (text, binary, damaged, etc) without looking into it. ASCIIs are upto 0x7F. Binaries - 0xFF. And also just to play around of course
