#include <iostream>
#include <string>
#include <sstream>  
using namespace std;
class shape {
    public:
        virtual string str() const =0 ;
};

/*class Circle : public shape {
    private:
        float radius;
    public:
        Circle() {}
        Circle(float radius): radius(radius) {}
        
        void resize(float factor) {
            radius *= factor;
        }
        
        string str() const override {
            ostringstream oss;
            oss << "A circle of radius" << radius;
            return oss.str();
        }
};

class Square : public shape {
    private:
        float side;
    public:
        Square() {}
        Square(float side): side(side) {}
        
        void resize(float factor) {
            side *= factor;
        }
        
        string str() const override {
            ostringstream oss;
            oss << "A sqaure with side" << side;
            return oss.str();
        }
};
*/
class ColoredShape : public shape {
    private:
        shape* shape;
        string color;
    public:
        explicit ColoredShape(shape *s, const string& color);
        string str() const override {
            ostringstream oss;
            oss << shape.str() <<"has the color" << color;
            return oss.str();   
        }
};
ColoredShape::ColoredShape(shape *s, const string& color):shape(shape), color(color) {}
int main()
{
   // Square s(5);https://www.onlinegdb.com/online_c++_compiler#tab-stdin
   // Colored_shape red_square(s, std::string("red"));
   // std::cout << s.str() << endl << red_square.str() << endl;
}
