import java.util.Scanner;

class ship{
    private int [] localposition;
    int hitparts = 0;

    void setship(int [] position)
    {
        localposition = position;
    }

    String selfcheck(int input)
    {
        String result = "miss";
        for(int cell:localposition)
        {
            if(cell == input)
            {
                hitparts += 1;
                result = "hit";
                break;
            }
        }
        if(hitparts == localposition.length)
        {
            result = "killed";
        }
        return result;
    }

};
class game{
    public static void main(String [] args)
    {
        Scanner sc = new java.util.Scanner(System.in);
        int input_test;
        ship ship1=new ship();
        int [] location = {2,3,4};
        String result;
        ship1.setship(location);
        int [] input ={3,4,2};
        for(int i =0; i<3;i+=1)
        {
            input_test = sc.nextInt();
            result = ship1.selfcheck(input_test);
            System.out.println(result);
        }
        sc.close();
    }
}