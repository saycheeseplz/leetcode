// public class hi {
// // psvm public static main method

// public static void main(String[] args) {
// // sout print a string to system.out
// // print not line ,println down line
// System.out.println(9);
// System.out.println("helloo");
// System.out.print("me kieeps");
// // \n down line \" add space \t contain 4 space
// System.out.println(" fuke me");
// System.out.println("i love you but \n little do you now \t i want you little
// do you know \" ");

// }
// }
// kieu co so int ,long
// kieu warpper class Integer ,Long

import java.util.Scanner;

public class hi {
    // public static void main(String[] args) {
    // System.out.println("max cua kieu int " + Integer.MAX_VALUE);
    // System.out.println("min cua kieu int " + Integer.MIN_VALUE);
    // }
    public static void main(String[] args) {
        float diemad = 2.3f;
        System.out.println(diemad);
        diemad = 32;
        System.out.println(diemad);
        // hang so
        final int BOIL = 100;
        System.out.println(BOIL);
        ////////////////
        /// ep kieu du lieu
        int a = 2;
        int b = 4;
        float c;
        c = a / b;
        System.out.println(c);
        c = (float) a / b;
        System.out.println(c);
        // int long float double
        System.out.println("hello mother fucker " + c);
        System.out.println(c > 9 || c < 0);
        System.out.println(!(c > 9 || c < 0));
        // input from user
        Scanner sc = new Scanner(System.in);

    }
}