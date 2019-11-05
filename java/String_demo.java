class str{
    public static void main(String [] args)
    {
        String str1 = "hello world";
        String str2 = "hello world";
        String str3 = new String("hello world");
        String str4 = new String("hello world");
        System.out.print("str1 and str2 ");
        System.out.println( str1 == str2);
        System.out.println("str1 and str2 in memory");
        System.out.println("str1 " + System.identityHashCode(str1));
        System.out.println("str2 " + System.identityHashCode(str2));
        System.out.print("str1 and str3 ");
        System.out.println( str1 == str3);
        System.out.println("content in str1 and str3 " + str1.equals(str3));
        System.out.print("str3 and str4 ");
        System.out.println( str3 == str4);
        System.out.println("str3 and str4 in memory");
        System.out.println("str1 " + System.identityHashCode(str3));
        System.out.println("str2 " + System.identityHashCode(str4));

    }
}