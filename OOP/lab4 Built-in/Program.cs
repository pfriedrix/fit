using System;
using System.Collections;
using lab4;

namespace lab4_IComparable
{
    class Program
    {
        static void Main(string[] args)
        {
            Magazine[] printedArray = new Magazine[3]
            {
                new Magazine("Harry Potter 1", 19.4, "us", "fantasy", 2000, 10, 1000, 10, 504),
                new Magazine("Harry Potter 2", 12.4, "us", "fantasy", 2000, 10, 1000, 10, 1552),
                new Magazine("Harry Potter 3", 18.4, "us", "fantasy", 2010, 11, 1100, 20, 332)
            };

            Magazines magazineList = new Magazines(printedArray);
            ArrayList magazines = new ArrayList();
            Console.WriteLine("Iterator");
            foreach (var p in magazineList)  Console.WriteLine(p.Title);
            foreach (var p in magazineList) magazines.Add(p);
            magazines.Sort();
            Console.WriteLine("Sorted by Cost");
            Magazines sorted = new Magazines((Magazine[])magazines.ToArray(typeof(Magazine)));
            foreach (var p in sorted) Console.WriteLine(p.Title);
            Array.Sort(printedArray, Magazine.sort());

            Magazines sorted2 = new Magazines(printedArray);
            Console.WriteLine("Sorted by Pages and Popularity");
            foreach (var p in sorted2) Console.WriteLine(p.Title);

        }
    }
}