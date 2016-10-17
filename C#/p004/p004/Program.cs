class main 
{
    static void Main()
    {
        //符号付き変数は全部算術シフトになるみたいです
        System.Console.WriteLine(+32 >> 2);
        System.Console.WriteLine(+32 << 2);
        System.Console.WriteLine(-32 >> 2);
        System.Console.WriteLine(-32 << 2);
        //unsignedだと論理シフトとのこと（unsignedに算術も論理もないのでは？？？）
        for (; ; ) ;
    }
}