class Rational {
    private long a;
    private long b;

    public double toDouble() {
        return 1.0*a/b;
    }

    public static boolean isInfinite(Rational r) {
        return r.b == 0;
    }

    static Rational getRandomRational(Random random) {
        return new Rational(random.nextInt()%201-100, random.nextInt()%201-100);
    }

    Rational() {
        a = 0;
        b = 1;
    }

    Rational(long a) {
        this.a = a;
        b = 1;
    }

    Rational(long a, long b) {
        if (b == 0) {
            this.a = a;
            this.b = 0;
        } else {
            this.a = a * b / Math.abs(b);
            this.b = Math.abs(b);

            if (this.a == 0) {
                this.b = 1;
            }
        }
        reduce();
    }

    Rational(Rational r) {
        this.a = r.a;
        this.b = r.b;
    }

    public static Rational multiply(Rational r1, Rational r2) {
        return new Rational(r1.a*r2.a, r1.b*r2.b);
    }

    public static Rational divide(Rational r1, Rational r2) {
        return new Rational(r1.a*r2.b, r1.b*r2.a);
    }

    public static Rational sum(Rational r1, Rational r2) {
        long gcd = Main.gcd(r1.b, r2.b);
        return new Rational(r1.a*r2.b/gcd + r2.a*r1.b/gcd, r1.b*r2.b/gcd);
    }

    public static Rational difference(Rational r1, Rational r2) {
        long gcd = Main.gcd(r1.b, r2.b);
        return new Rational(r1.a*r2.b/gcd - r2.a*r1.b/gcd, r1.b*r2.b/gcd);
    }

    public Rational abs() {
        return new Rational(Math.abs(a), b);
    }

    public Rational doubleNumber() {
        a*=2;
        return this.reduce();
    }

    public long getHeight() {
        return Math.abs(a) + b;
    }

    public Rational squareNumber() {
        a*=a;
        b*=b;
        return this.reduce();
    }

    public static boolean isEqual(Rational r1, Rational r2) {
        return (r1.a == r2.a && r1.b == r2.b) || (r1.b==0 && r2.b==0);
    }

    public boolean isBigger(Rational r) {
        return 1.0*a/b > 1.0*r.a/r.b;
    }

    public Rational reduce() {
        for (int i = 2; i <= Math.abs(a); ++i) {
            while (Math.abs(a) >= i && Math.abs(a)%i==0 && Math.abs(b)%i==0) {
                a /= i;
                b /= i;
            }
        }
        return this;
    }

    public boolean isZero(){
        return a == 0;
    }

    public String toStringFull() {
        return a + "/" + b;
    }

    public String toString() {
        if (a == 0 && b != 0)
            return "0";
        else if (b == 1)
            return Long.toString(a);
        else
            return a + "/" + b;
    }
}
