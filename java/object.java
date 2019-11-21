import java.util.ArrayList;
import java.lang.Object;
class object{
    public static Object getobject(Object o)
    {
        return o;
    }
    public static void main(String [] args)
    {
        Test test = new Test();
        Animals animal = new Animals();
        //Test test1 = new Test();
        //test container
        ArrayList<Object> mylist = new ArrayList<Object>();
        mylist.add(test);
        mylist.getClass();
        System.out.println("test");
    }

}