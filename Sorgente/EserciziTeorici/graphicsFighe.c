#include <"/usr/include/graphics.h">

int main(int argc, char* arv[]) {

    int maxX, maxY;

    maxX = getmaxwidth();
    maxY = getmaxheight();

    initwindow(maxX, maxY, "Full screen window");
    line(0, 0, maxX, maxY);
    setcolor(BLUE);
    getch();
    closegraph()

    return 0;
}
