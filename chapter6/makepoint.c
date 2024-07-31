#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point pt1;
    struct Point pt2;
};

struct Point makepoint(int x, int y) {
    struct Point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points */
struct Point addpoint(struct Point p1, struct Point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct Point p, struct Rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
/* canonrect: canonicalize coordinates of rectangle */
struct Rect canonrect(struct Rect r) {
    struct Rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

int main() {

    struct Rect screen;
    screen.pt1 = makepoint(200,30);
    screen.pt2 = makepoint(1200,1200);

    struct Rect s2 = canonrect(screen);

    struct Point pt, *pp;
    pp = &s2.pt1;

    pt.x = 12;
    pt.y=3;

    printf("%d,%d\n",pt.x, pt.y);
    printf("pointer version:%d,%d\n",pp->x, pp->y);

    double number = 25;
    double result = sqrt(number);
    printf("%f\n", sqrt((double)pt.x * pt.x + (double)pt.y * pt.y));
    double dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    return 0;
}