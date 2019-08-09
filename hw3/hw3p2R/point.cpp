// Moe Ko Latt
// ID: 915866164
#include "Point.h"

Point Point::operator+ (const Point& rhs) const{
    return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator- (const Point &rhs) const{
    return Point(x - rhs.x, y - rhs.y);
}

std::ostream& operator<< (std::ostream& os, const Point& p){
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

std::istream& operator>> (std::istream& is, Point& p){
    is >> p.x >> p.y;
    return is;
}