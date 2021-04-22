

using System;
using System.Collections;
using System.Collections.Generic;

namespace lab4
{
    public class Magazine: PrintedEdition,  IComparer<Magazine>
    {
        private int public_year;
        private int numb_magazine;
        private int circulation;
        private int popularity;
        private int pages;
        public int points;


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
            points = 10;
        }

        public Magazine(string title, double cost, string language, string purpose, int publicYear, int numbMagazine,
            int circulation, int popularity) : base(title, cost, language, purpose)
        {
            public_year = publicYear;
            numb_magazine = numbMagazine;
            this.circulation = circulation;
            this.popularity = popularity;
            points = 10;
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
        
        public int Compare(Magazine x, Magazine y)
        {
            if (x.Pages > y.Pages)
            {
                if (y.points < 1)
                {
                    return 0;
                }
                y.points--;
            }
            else if (x.Pages < y.Pages)
            {
                if (x.points < 1)
                {
                    return 0;
                }
                x.points--;
            }

            if (x.Popularity > y.Popularity)
            {
                if (y.points < 1)
                {
                    return 0;
                }
                y.points--;
            }
            
            else if (x.Popularity < y.Popularity)
            {
                if (x.points < 1)
                {
                    return 0;
                }
                x.points--;
            }

            return 1;
        }

    }


    public class MagazinesEnum : IEnumerator
    {
        public Magazine[] _magazine;
        private int position = -1;

        public MagazinesEnum(Magazine[] list)
        {
            _magazine = list;
        }

        public bool MoveNext()
        {
            position++;
            return (position < _magazine.Length);
        }
        
        public void Reset() {position = -1;}

        object IEnumerator.Current
        {
            get
            {
                return Current;
            }
        }

        public Magazine Current
        {
            get
            {
                try
                {
                    return _magazine[position];

                }
                catch (IndexOutOfRangeException)
                {
                    throw new InvalidOperationException();
                }
            }
        }
    }

    class Magazines : IEnumerable
    {
        private Magazine[] _magazine;

        public Magazines(Magazine[] pArray) 
        {
            _magazine = new Magazine[pArray.Length];

            for (int i = 0; i < pArray.Length; i++)
            {
                _magazine[i] = pArray[i];
            }
        }
        
        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator) GetEnumerator();
        }

        public MagazinesEnum GetEnumerator()
        {
            return new MagazinesEnum(_magazine);
        }
    }
}
