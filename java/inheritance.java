import java.util.ArrayList;

class Animals{
    int food;
    void makeNosie(){}
    void eat(){System.out.println("don't know");}
    void sleep(){
        System.out.println("well sleep like a dog");
    }
    void roam(){System.out.println("like dogs");}
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
    void roam()
    {
        System.out.println("like a wolf");
    }
}
class animallist{
    animallist()
    {
        animals = new Animals[5];
        index = 0;
    }
    private Animals [] animals;
    private int index;
    void getAnimalNumber()
    {
        System.out.println(index);
    }
    void add(Animals animal)
    {
        if(index >= 5)
        {
            return;
        }
        animals[index] = new Animals();
        animals[index] = animal;
        index++;
    }

}
public class  inheritance{
    public static void main(String [] args)
    {
        Animals Wolf = new wolf();
        animallist animalList = new animallist();
        wolf Wolf1 = new wolf();
        canine Wolf2 = new canine();
        Wolf.eat();
        Wolf.sleep();
        //Wolf.unique();
        System.out.println("-----------------------------");
        Wolf1.eat();
        Wolf1.sleep();
        Wolf1.unique();
        Wolf2.roam();
        Wolf.roam();
        System.out.println("-----------------------------");
        animalList.add(Wolf);
        animalList.add(Wolf1);
        animalList.getAnimalNumber();
    }
}
