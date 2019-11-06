import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

import javax.swing.text.Position;

class ship{
    private ArrayList<String> localposition;
    private String _name;
    private String [] _position;
    void setName(String name)
    {
        _name = name;
    }
    void setship()
    {
        get_Position();
        localposition = new ArrayList<>();
        for(int i =0; i < _position.length; i++)
        {
            localposition.add(_position[i]);
        }
    }

    void get_Position()
    {
        Scanner sc = new Scanner(System.in);
        _position = new String[3];
        for(int i =0; i < 3; i++)
        {
            _position[i] = new String(sc.nextLine());
        }
        //sc.close();
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
    //private Scanner sc = new Scanner(System.in);
    void addships(ship [] yourship)
    {
        System.out.println("setting your ships' position");
        for(int i =0; i < yourship.length; i++)
        {
            ships.add(yourship[i]);
        }
    }
    void play()
    {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        int index;
        System.out.println("please input your guess");
        for(ship tmp:ships)
        {
            if(tmp.selfcheck(input))
            {
                if(tmp.iskilled())
                {
                    index = ships.indexOf(tmp);
                    ships.remove(index);
                    System.out.println(tmp.getName() + " is killed");
                }
                else
                {
                    System.out.println(tmp.getName() + " is hit");
                }
                break;
            }
        }
        //sc.close();
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
        ship [] ships = new ship[3];
        System.out.println("set your ship's name and position");
        for(int i =0;i<3;i++){
            ships[i] = new ship();
            System.out.println("set your ship's name");
            ships[i].setName(sc.nextLine());
            System.out.println("set your ship's position");
            ships[i].setship();
        }
        board.addships(ships);
        while(!board.isEmpty())
        {
            board.play();
        }
        sc.close();
    }
}