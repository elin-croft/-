class test{
    private void priv_hello() 
    {
        System.out.println("priv_hello in this class is a private function you can't access by merely call p_hello function");    
    }
    void hello()
    {
        System.out.println("hello in this class is a public function");
    }
    void call_priv_hello()
    {
        priv_hello();
        System.out.println("you can call private function by using a public functiono");
    }
}
class run{
    public static void main(String [] args)
    {
        test p = new test();
        p.hello();
        p.call_priv_hello();
    }
}