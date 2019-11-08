import java.util.ArrayList;
import java.util.Scanner;


class ship{
    private ArrayList<String> localposition;
    private String _name;
    private String [] _position;
    public static Scanner sc = new Scanner(System.in);
    void setName(String name)
    {
        _name = name;
    }
    void setship()
    {
        
        _position = new String[3];
        localposition = new ArrayList<>();
        for(int i =0; i < _position.length; i++)
        {
            _position[i] = new String(sc.nextLine());
            while(localposition.indexOf(_position[i])>=0)
            {
                System.out.println(_position[i] + " is exsited, please input again");
                _position[i] = new String(sc.nextLine());
            }
            localposition.add(_position[i]);
        }
    }

    void get_Position()
    {
        for(int i =0; i < 3; i++)
        {
            _position[i] = new String(sc.nextLine());
        }
    }

    String getName()
    {
        return _name;
    }

    boolean selfcheck(String input)
    {
        boolean result = false;
        int index = localposition.indexOf(input);
        if(index >= 0){
            localposition.remove(index);
            result = true;
        }
        return result;
    }
    boolean iskilled()
    {
        return localposition.isEmpty();
    }

};

class grid{
    private ArrayList<ship> ships = new ArrayList<>();
    public static Scanner sc = new Scanner(System.in);
    private ship [] myships;
    void addships()
    {
        System.out.println("setting your ships' position");
        for(int i =0; i < myships.length; i++)
        {
            ships.add(myships[i]);
        }
    }
    void setship()
    {
        myships = new ship[3];
        for(int i =0;i<3;i++){
            myships[i] = new ship();
            System.out.println("set your ship's name");
            myships[i].setName(sc.nextLine());
            System.out.println("set "+ myships[i].getName() + "'s position");
            myships[i].setship();
        }
    } 
    void play()
    {
        System.out.println("please input your guess");
        String input = sc.nextLine();
        int index;
        String result = "miss";
        for(ship tmp:ships)
        {
            if(tmp.selfcheck(input))
            {
                if(tmp.iskilled())
                {
                    index = ships.indexOf(tmp);
                    ships.remove(index);
                    result = "killed";
                    System.out.println(tmp.getName() + " is " + result);
                }
                else
                {
                    result = "hit";
                    System.out.println(tmp.getName() + " is " + result);
                }
                break;
            }
        }
        System.out.println(result);

    }
    boolean isEmpty()
    {
        return ships.isEmpty();
    }
};
public class game{
    
    public static Scanner sc = new Scanner(System.in);
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        //public static final Scanner sc = new Scanner(System.in);
        grid board = new grid();
        board.setship();
        board.addships();
        while(!board.isEmpty())
        {
            board.play();
        }
        sc.close();
    }
}