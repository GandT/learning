class program {
    static void Main(){
        System.Console.WriteLine("日本語");
        System.Console.WriteLine("nihongo dehanai");
        System.Console.WriteLine(124);
        System.Console.WriteLine(0x124);
        System.Console.WriteLine(3.1415);
        System.Console.WriteLine(.81810606);
        System.Console.WriteLine(81.81810606e10);  //0x81.81810606e10は駄目だそうです
        System.Console.WriteLine(true);
        System.Console.WriteLine('∨');
        System.Console.WriteLine("\'∨\'");
        System.Console.WriteLine("\a\a\a\a\a\a\a\a");  //連続で書いても一回しかならない（と思われる）
        for (; ; ) ;
    }
}