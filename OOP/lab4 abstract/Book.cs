using System;

namespace lab4
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

        public Book(string title, double cost, string language, string purpose, string author, int pages,
            int publicYear, int circulation, int popularity) : base(title, cost, language, purpose)
        {
            this.author = author;
            this.pages = pages;
            public_year = publicYear;
            this.circulation = circulation;
            this.popularity = popularity;
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
    }
}