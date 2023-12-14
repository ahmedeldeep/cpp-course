
class Point {
 public:
  int x, y;
};

class Shape {  // abstract class
 public:
  virtual void rotate(int) = 0;   // pure virtual function
  virtual void draw() const = 0;  // pure virtual function
  // ...
  virtual ~Shape();  // virtual
};

class Circle : public Shape {
 public:
  Circle(Point p, int r) : _center{p}, _radius(r) {}
  void rotate(int) override {}
  void draw() const override;

 private:
  Point _center;
  int _radius;
};

int main() {
  //
}
