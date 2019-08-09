#include "Shape.h"
#include <algorithm>

Rectangle::~Rectangle(void){}

bool Rectangle::overlaps(const Shape& r) const{
    return r.overlaps(*this);
}

bool Rectangle::overlaps(const Circle& r) const{

    int xn = std::min(std::max(r.center.x, this->position.x),this->position.x+this->width);
    int yn = std::min(std::max(r.center.y, this->position.y),this->position.y+this->height);

    int dx = xn - r.center.x;
    int dy = yn - r.center.y;

    int d = dx*dx+dy*dy;

    return d < (r.radius * r.radius);
}

bool Rectangle::overlaps(const Rectangle& r) const {
    bool x_overlap = (this->position.x < r.position.x + r.width) && (this->position.x + this->width > r.position.x);
    bool y_overlap = (this->position.y < r.position.y + r.height) && (this->position.y + this->height > r.position.y);

    return x_overlap && y_overlap;
}

bool Rectangle::fits_in(const Rectangle& r) const {
    // Check if x or y is greater the r's x,y but do not extend past the r'x x_width/y+height
    bool x_fit = (this->position.x >= r.position.x) && (this->position.x + this->width <= r.position.x + r.width);
    bool y_fit = (this->position.y >= r.position.y) && (this->position.y + this->height <= r.position.y + r.height);

    return x_fit && y_fit;
}

void Rectangle::draw(void) const {
    std::cout << "<rect x=\"" << position.x << "\" y=\"" << position.y << "\" width=\"" << width <<"\" height=\"" << height << "\"/>" << std::endl;
}

Circle::~Circle(void){}

bool Circle::overlaps(const Shape& r) const {
    return r.overlaps(*this);
}

bool Circle::overlaps(const Circle& r) const {
    bool fits = (this->radius - r.radius)*(this->radius - r.radius) < (this->center - r.center).norm2() &&
                (this->center - r.center).norm2() < (this->radius + r.radius)*(this->radius + r.radius);

    return fits;
}

bool Circle::overlaps(const Rectangle& r) const {
    return r.overlaps(*this);
}

bool Circle::fits_in(const Rectangle& r) const {
    bool in_x = this->center.x-this->radius >= r.position.x &&
            this->center.x+this->radius <= r.position.x + r.width;

    bool in_y = this->center.y-this->radius >= r.position.y &&
            this->center.y+this->radius <= r.position.y + r.height;

    //in_x = true; in_y = true;
    return in_x && in_y;
}

void Circle::draw(void) const {
    std::cout << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\"/>" <<std::endl;

}