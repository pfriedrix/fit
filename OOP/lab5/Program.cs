using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintedEdition edition = new PrintedEdition("by keyboard");
            PrintedEdition edition2 = new PrintedEdition("copy", edition);
            Console.WriteLine(edition.Title + " " + edition2.Language);
            Magazine mag = new Magazine();
            mag = new Magazine("by keyboard", mag);
            Magazine mag2 = new Magazine("copy", mag);
            if (mag == mag2)
            {
                Console.WriteLine("They are equal");
            }
            else
            {
                Console.WriteLine("They are not equal");
            }

            mag2.Cost = mag2.Cost * 1.5;
            if (mag > mag2)
            {
                Console.WriteLine("mag is more");
            }
            else
            {
                Console.WriteLine("mag is not more");
            }

            mag--;
            Console.WriteLine(mag.Circulation);


            PrintedEdition[] arr = new PrintedEdition[3];
            arr[0] = edition;
            edition2.Title = "harrry 4";
            arr[1] = edition2;
            for (int i = 0; i < 3; i++)
            {
                arr[i].export();
            }
        }
    }
}                                                              