
class Line {
    Rational k;
    Rational b;

    Line() {
        k = new Rational();
        b = new Rational();
    }

    Line(Point p1, Point p2) {
        k = new Rational(p2.y-p1.y, p2.x-p1.x);
        if (p2.x==p1.x) {
            b = new Rational(p1.x);
        } else {
            b = Rational.difference(new Rational(p1.y), Rational.multiply(new Rational(p1.x), k));
        }
    }

    public String toString() {
        return "y = " + k + "x + " + b;
    }

    static public boolean isParallel(Line l1, Line l2) {
        return Rational.isEqual(l1.k, l2.k) && !Rational.isEqual(l1.b, l2.b);
    }

    static public boolean isEqual(Line l1, Line l2) {
        return Rational.isEqual(l1.k, l2.k) && Rational.isEqual(l1.b, l2.b);
    }
}
