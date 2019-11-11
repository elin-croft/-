class Animals{
    int food;
    void makeNosie(){}
    void eat(){System.out.println("don't know");}
    void sleep(){
        System.out.println("well sleep like a dog");
    }
    void roam(){}
}
class canine extends Animals{
    void roam()
    {
        System.out.println("walk like a dog");
    }
    void eat()
    {
        super.eat();
        System.out.println("eat meat");
    }

}
class wolf extends canine{
    void makeNosie()
    {
        System.out.println("Wo~");
    }
    void unique()
    {
        System.out.println("hi guys, i'm not in any superclass");
    }
}
public class  inheritance{
    public static void main(String [] args)
    {
        Animals Wolf = new wolf();
        wolf Wolf1 = new wolf();
        Wolf.eat();
        Wolf.sleep();
        //Wolf.unique();
        System.out.println("-----------------------------");
        Wolf1.eat();
        Wolf1.sleep();
        Wolf1.unique();
    }
}
