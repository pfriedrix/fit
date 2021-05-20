using System;
using System.Security.Cryptography;

namespace lab5
{
    class Book : PrintedEdition
    {
        private string author;
        private int pages;
        private int public_year;
        private int circulation;
        private int popularity;

        public string Author
        {
            get => author;
            set => author = value;
        }

        public int Pages
        {
            get => pages;
            set => pages = value;
        }

        public int PublicYear
        {
            get => public_year;
            set => public_year = value;
        }

        public int Circulation
        {
            get => circulation;
            set => circulation = value;
        }

        public int Popularity
        {
            get => popularity;
            set { popularity = value; }
        }

        public void setPopularity()
        {
            Random random = new Random();
            double rand = random.Next(0, 100) / 100;
            int sold = (int) (circulation * rand);
            const double paper_cost = 0.32;
            const double edition = 1.51;
            const double tax = 0.19;
            popularity = (int) (sold + circulation * paper_cost + circulation * edition + circulation * tax);
        }

        public Book() { }

        public Book(string title, double cost, string language, string purpose, string author, int pages,
            int publicYear, int circulation, int popularity) : base(title, cost, language, purpose)
        {
            this.author = author;
            this.pages = pages;
            public_year = publicYear;
            this.circulation = circulation;
            this.popularity = popularity;
        }

        public Book(string code, Book book)
        {
            if (code == "by keyboard")
            {
                Console.WriteLine("Enter the author this book: ");
                Author = Console.ReadLine();
                Console.WriteLine("Enter the pages this book: ");
                Pages = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the popularity this book: ");
                Popularity = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the year publication this book: ");
                PublicYear = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the circulation this book: ");
                Circulation = Convert.ToInt32(Console.ReadLine());    
            }
            else if (code == "copy" && book != null)
            {
                this.Pages = book.Pages;
                this.Author = book.Author;
                this.Popularity = book.Popularity;
                this.Circulation = book.Circulation;
                base.Title = book.Title;
                base.Cost = book.Cost;
                base.Language = book.Language;
                base.Purpose = book.Purpose;
            }
            else
            {
                throw new Exception("Invalid code!");
            }
        }

        public override void setCost()
        {
            Cost = Circulation * Pages * 0.3 * 0.5 * 0.1 * 0.9;
        }

        public override void setCirculation()
        {
            Circulation = (int) (Cost * 0.9);
        }

        public void export()
        {
            Console.Write("\nBook\n" +
                          "author: " + this.author +
                          "\npages: " + this.pages +
                          "\nyear: " + this.public_year +
                          "\ncirculation: " + this.circulation +
                          "\npopularity: " + this.popularity +
                          "\ntitle: " + this.Title +
                          "\ncost: " + this.Cost +
                          "\nlanguage: " + this.Language +
                          "\npurpose: " + this.Purpose);
        }

        public static bool operator >(Book book1, Book book2)
        {
            if (book1.Cost > book2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator <(Book book1, Book book2)
        {
            if (book1.Cost < book2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static bool operator ==(Book book1, Book book2)
        {
            if (book1.Cost == book2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator !=(Book book1, Book book2)
        {
            if (book1.Cost != book2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        public static Book operator +(Book c1, Book c2)
        {
            return new Book { Circulation = c1.Circulation + c2.Circulation };
        }
        
        public static Book operator -(Book c1, Book c2)
        {
            return new Book { Circulation = c1.Circulation - c2.Circulation };
        }
        
        public static Book operator --(Book c1)
        {
            return new Book { Circulation = c1.Circulation - 1 };
        }
        
        public static Book operator ++(Book c1)
        {
            return new Book { Circulation = c1.Circulation + 1 };
        }
        
        public static Book operator -(Book c1)
        {
            return new Book { Circulation = -c1.Circulation };
        }
        
    }
}