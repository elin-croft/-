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
        ship ship1=new ship();
        int [] location = {2,3,4};
        String result;
        ship1.setship(location);
        int [] input ={3,4,2};
        for(int i:input)
         {
            result = ship1.selfcheck(i);
            System.out.println(result);
        }   
    }
}