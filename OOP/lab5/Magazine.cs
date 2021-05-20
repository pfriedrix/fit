using System;

namespace lab5
{
    class Magazine : PrintedEdition
    {
        private int public_year;
        private int numb_magazine;
        private int circulation;
        private int popularity;

        public int PublicYear
        {
            get => public_year;
            set => public_year = value;
        }

        public int NumbMagazine
        {
            get => numb_magazine;
            set => numb_magazine = value;
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
            const double paper_cost = 0.33;
            const double edition = 1.01;
            const double tax = 0.19;
            popularity = (int) (sold + circulation * paper_cost + circulation * edition + circulation * tax);
        }
        public Magazine() {}
        public Magazine(string title, double cost, string language, string purpose, int publicYear, int numbMagazine,
            int circulation, int popularity) : base(title, cost, language, purpose)
        {
            public_year = publicYear;
            numb_magazine = numbMagazine;
            this.circulation = circulation;
            this.popularity = popularity;
        }

        public Magazine(string code, Magazine magazine)
        {
            if (code == "by keyboard")
            {
                Console.WriteLine("Enter the number this magazine: ");
                NumbMagazine = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the popularity this magazine: ");
                Popularity = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the year publication this magazine: ");
                PublicYear = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the circulation this magazine: ");
                Circulation = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the title this book: ");
                Title = Console.ReadLine();
                Console.WriteLine("Enter the pages this book: ");
                Cost = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the lang this book: ");
                Language = Console.ReadLine();
                Console.WriteLine("Enter the purpose this book: ");
                Purpose = Console.ReadLine();
            }
            else if (code == "copy")
            {
                this.NumbMagazine = magazine.NumbMagazine;
                this.PublicYear = magazine.PublicYear;
                this.Popularity = magazine.Popularity;
                this.Circulation = magazine.Circulation;
                base.Title = magazine.Title;
                base.Cost = magazine.Cost;
                base.Language = magazine.Language;
                base.Purpose = magazine.Purpose;
            }
            else
            {
                throw new Exception("Invalid code!");
            }
        }

        public void export()
        {
            Console.Write("\nMagazine\n" + "year: " + this.public_year +
                          "\ncirculation: " + this.circulation +
                          "\npopularity: " + this.popularity +
                          "\ntitle: " + this.Title +
                          "\ncost: " + this.Cost +
                          "\nlanguage: " + this.Language +
                          "\npurpose: " + this.Purpose);
        }
        
        public override void setCost()
        {
            Cost = Circulation * NumbMagazine * 0.3 * 0.5 * 0.1 * 0.9;
        }
        
        public override void setCirculation()
        {
            Circulation = (int) (Cost * 0.7);
        }
        
        public static bool operator >(Magazine Magazine1, Magazine Magazine2)
        {
            if (Magazine1.Cost > Magazine2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator <(Magazine Magazine1, Magazine Magazine2)
        {
            if (Magazine1.Cost < Magazine2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static bool operator ==(Magazine Magazine1, Magazine Magazine2)
        {
            if (Magazine1.Cost == Magazine2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator !=(Magazine Magazine1, Magazine Magazine2)
        {
            if (Magazine1.Cost != Magazine2.Cost)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        public static Magazine operator +(Magazine c1, Magazine c2)
        {
            return new Magazine { Circulation = c1.Circulation + c2.Circulation };
        }
        
        public static Magazine operator -(Magazine c1, Magazine c2)
        {
            return new Magazine { Circulation = c1.Circulation - c2.Circulation };
        }
        
        public static Magazine operator --(Magazine c1)
        {
            return new Magazine { Circulation = c1.Circulation - 1 };
        }
        
        public static Magazine operator ++(Magazine c1)
        {
            return new Magazine { Circulation = c1.Circulation + 1 };
        }
        
        public static Magazine operator -(Magazine c1)
        {
            return new Magazine { Circulation = -c1.Circulation };
        }
    }
}