using System;
using System.ComponentModel;
using System.Linq;
using System.Reflection.PortableExecutable;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using lab4;

namespace lab4
{
    class Program
    {
        static void Action(Editor editor)
        {
            editor.export();
        }
        static void Main(string[] args)
        {
            Book book = new Book("Naruto", 123.0,"ru", "public", "Vasya", 200, 2001, 200000, 10);
            // book.export();
            Magazine magazine = new Magazine("Hacker", 200.0, "ru", "science", 1980,9989, 2000, 9);
            Action(book);
            book.setPopularity();

        }
    }
}