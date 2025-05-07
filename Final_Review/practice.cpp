// Classes

class Rectangle {
    public:
        Rectangle(int w, int l){
            width = w;
            length = l;
        }

        int area() { // these methods do not take arguments. They use the object's already existing width & length
            return width*length;
        }

        int perimeterr() {
            return 2*width + 2*length;
        }

    private:
        int width;
        int length;
}; // don't forget the semicolon here

class Circle {
    private:
        double radius;
    
    public:
        Circle(double r) : radius(r) {}
    
        double area(){
            return radius*radius*3.14; //always use the class member! That is, radius, not r
        }
};