class Segment {
    Point p1;
    Point p2;

    Segment() {
        p1 = new Point();
        p2 = new Point();
    }

    Segment(Point A, Point B) {
        if (A.cmp(B) <= 0) {
            p1 = new Point(A);
            p2 = new Point(B);
        } else {
            p1 = new Point(B);
            p2 = new Point(A);
        }
    }

    public double getLength() {
        double len = 0;
        Long a1 = Math.abs(p1.x - p2.x);
        Long a2 = Math.abs(p1.y - p2.y);
        if (p1.x == p2.x)
            return a2;
        else if (p1.y == p2.y)
            return a1;
        else
            return Math.sqrt(a1 * a1 + a2 * a2);
    }

    public double getCircleArea() {
        double Area = Math.PI * getLength() * getLength() / 4;
        return Area;
    }

    public double greaterDistance(Point A) {
        Long a1 = Math.abs(p1.x - A.x);
        Long a2 = Math.abs(p1.y - A.y);
        Long a3 = Math.abs(p2.x - A.x);
        Long a4 = Math.abs(p2.y - A.y);
        double distance1 = 0;
        double distance2 = 0;
        if (p1.x == A.x)
            distance1 = a2;
        else if (p1.y == A.y)
            distance1 = a1;
        else
            distance1 = Math.sqrt(a1 * a1 + a2 * a2);
        if (p2.x == A.x)
            distance2 = a4;
        else if (p2.y == A.y)
            distance2 = a3;
        else
            distance2 = Math.sqrt(a3 * a3 + a4 * a4);

        if (distance1 > distance2)
            return distance1;
        else
            return distance2;
    }

    //Одинаковые отрезки - true
    public static boolean isEqual(Segment first, Segment second) {
        return Point.isEqual(first.p1, second.p1) && Point.isEqual(first.p2, second.p2) ||
                Point.isEqual(first.p1, second.p2) && Point.isEqual(first.p2, second.p1);
    }


    public Point getMiddle() {
        return new Point((p1.x+p2.x)/2, (p1.y+p2.y)/2);
    }

    static public boolean isParallel(Segment s1, Segment s2) {
        Line l1 = new Line(s1.p1, s1.p2);
        Line l2 = new Line(s2.p1, s2.p2);
        //System.out.printf("%s || %s\t: %s\n", l1.toString(), l2.toString(), Line.isParallel(l1, l2));
        return Line.isParallel(l1, l2);
    }
}
