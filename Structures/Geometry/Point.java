
class Point {
    long x;
    long y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(long x, long y) {
        this.x = x;
        this.y = y;
    }

    Point(Point other) {
        x = other.x;
        y = other.y;
    }

    public int cmp(Point other) {
        if (x > other.x) return 1;
        else if (x < other.x) return -1;
        else if (y > other.y) return 1;
        else if (y < other.y) return -1;
        else return 0;
    }

    public static Point nextPoint(Scanner scanner) {
        return new Point(scanner.nextLong(), scanner.nextLong());
    }

    public static Point nextPoint(Random random) {
        return new Point((random.nextLong()%21)-10, (random.nextLong()%21)-10);
    }

    public String toString() {
        String str = "(" + Long.toString(this.x) + ", " + Long.toString(this.y) + ")";
        return str;
    }

    public static boolean isEqual(Point A, Point B) {
        boolean flag;
        if (A.x == B.x & A.y == B.y)
            flag = true;
        else
            flag = false;
        return flag;
    }

    public double smallerDistance(Segment AB) {
        Point p1 = AB.p1;
        Point p2 = AB.p2;
        Long a1 = Math.abs(p1.x - this.x);
        Long a2 = Math.abs(p1.y - this.y);
        Long a3 = Math.abs(p2.x - this.x);
        Long a4 = Math.abs(p2.y - this.y);
        double distance1 = 0;
        double distance2 = 0;
        if (p1.x == this.x)
            distance1 = a2;
        else if (p1.y == this.y)
            distance1 = a1;
        else
            distance1 = Math.sqrt(a1 * a1 + a2 * a2);
        if (p2.x == this.x)
            distance2 = a4;
        else if (p2.y == this.y)
            distance2 = a3;
        else
            distance2 = Math.sqrt(a3 * a3 + a4 * a4);

        if (distance1 < distance2)
            return distance1;
        else
            return distance2;
    }

    public void move(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
