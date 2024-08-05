import java.util.Random;
import java.util.Scanner;

class Polygon {
    public static boolean isTrapezoid(Point[] points) {
        int length = 4;
        if (points.length != length) {
            return false;
        }
        Segment[] sides = new Segment[length];
        for (int i = 0; i < length; ++i) {
            sides[i] = new Segment(points[i], points[(i+1)%length]);
        }

        for (int i = 0; i < length; ++i) {
            if (Segment.isParallel(sides[i], sides[(i+2)%length]) && !Segment.isParallel(sides[(i+1)%length], sides[(i+3)%length])) {
                return true;
            }
        }
        return false;
    }

    public static long gcd(long a, long b) {
        return b>0 ? gcd(b, a % b) : a;
    }

    public static void main(String[] args) {
        Random random = new Random();
        //ExtraChecker.run();
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; ++i) {
            points[i] = Point.nextPoint(scanner);
        }

        Point zeroPoint = new Point();
        double minDist = -1;
        for (int i = 0; i < n; ++i) {
            Segment segment = new Segment(zeroPoint, points[i]);
            if (minDist == -1 || minDist > segment.getLength()) {
                minDist = segment.getLength();
            }
        }

        double maxDiag = -1;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+2; j < n && (j+1)%n != i; ++j) {
                Segment segment = new Segment(points[i], points[j]);
                if (maxDiag == -1 || maxDiag < segment.getLength()) {
                    maxDiag = segment.getLength();
                }
            }
        }
        System.out.println(minDist + " " + maxDiag + " " + (isTrapezoid(points)? 1: 0));
    }

    public static double triangleArea(Point A, Point B, Point C) {
        double Area;
        Segment AB = new Segment(A, B);
        Segment AC = new Segment(A, C);
        Segment BC = new Segment(B, C);
        double a = AB.getLength();
        double b = AC.getLength();
        double c = BC.getLength();
        double p = (a + b + c) / 2;
        Area = Math.sqrt(p * (p - a) * (p - b) * (p - c));
        return Area;
    }

    public static boolean isSegmentEnd(Segment AB, Point C) {
        return (AB.p1.x == C.x && AB.p1.y == C.y) ||
                (AB.p2.x == C.x && AB.p2.y == C.y);
    }
}
