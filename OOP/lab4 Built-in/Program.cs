using System;
using lab4;

namespace lab4_IComparable
{
    class Program
    {
        static void Main(string[] args)
        {
            Magazine[] printedArray = new Magazine[3]
            {
                new Magazine("Harry Potter 1", 10.4, "us", "fantasy", 2000, 10, 1000, 10),
                new Magazine("Harry Potter 2", 12.4, "us", "fantasy", 2000, 10, 1000, 10),
                new Magazine("Harry Potter 3", 110.4, "us", "fantasy", 2010, 11, 1100, 20),
            };

            Magazines magazineList = new Magazines(printedArray);
            foreach (var p in magazineList) Console.WriteLine(p.Title);
        }
    }
}