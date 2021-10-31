#include <iostream>
#include <string>
#include <sstream>  
using namespace std;
class shapeBase {
    public:
        virtual string str() const =0 ;
};

class Circle : public shapeBase {
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

class Square : public shapeBase {
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


class ColoredShape : public shapeBase {
    private:
        shapeBase& shape;
        string color;
    public:
        ColoredShape(shapeBase &s, std::string color): shape(s), color(color) {}
        string str() const override {
            ostringstream oss;
            oss << shape.str() <<"has the color" << color;
            return oss.str();   
        }
};
int main()
{
	Square s(2.0);
	std::string color("red");
	ColoredShape cs(s,color);
	std::string shapeStr = cs.str();
	std::cout << shapeStr <<std::endl;
	return 0;
}
