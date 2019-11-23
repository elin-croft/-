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
        Test animal1;
        //Test test1 = new Test();
        //test container
        ArrayList<Object> mylist = new ArrayList<Object>();
        mylist.add(test);
        if(mylist.get(0) instanceof Test){
            animal1 = (Test)mylist.get(0);
            System.out.println("done");
        }
    }

}