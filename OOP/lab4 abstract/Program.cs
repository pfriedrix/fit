using System;
using lab4;

namespace lab4_abstract
{
    class Program
    {
        static void Main(string[] args)
        {
            Magazine mag = new Magazine("Harry Potter 1", 19.4, "us", "fantasy", 2000, 10, 1000, 10);
            mag.Purpose = "learning";
            mag.export();
        }
    }
}