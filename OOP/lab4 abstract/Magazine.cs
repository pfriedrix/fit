using System;

namespace lab4
{
    class Magazine : PrintedEdition, Editor
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

        public Magazine(string title, double cost, string language, string purpose, int publicYear, int numbMagazine,
            int circulation, int popularity) : base(title, cost, language, purpose)
        {
            public_year = publicYear;
            numb_magazine = numbMagazine;
            this.circulation = circulation;
            this.popularity = popularity;
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
    }
}