

using System;
using System.Collections;
using System.Collections.Generic;

namespace lab4
{
    public class Magazine: PrintedEdition, IComparable
    {
        private int public_year;
        private int numb_magazine;
        private int circulation;
        private int popularity;
        private int pages;


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
        }

        public Magazine(string title, double cost, string language, string purpose, int publicYear, int numbMagazine,
            int circulation, int popularity, int pages) : base(title, cost, language, purpose)
        {
            public_year = publicYear;
            numb_magazine = numbMagazine;
            this.circulation = circulation;
            this.popularity = popularity;
            this.pages = pages;
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
        
       
        public int CompareTo(object obj)
        {
            if (obj == null) return 1;
            Magazine other = obj as Magazine;
            if (other != null) return this.Cost.CompareTo(other.Cost);
            else throw new ArgumentException("Object is not a Magazine");
        }

        public static IComparer sort()
        {
            return (IComparer) new sortByPagesAndPopularity();
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

    class sortByPagesAndPopularity : IComparer
    {
        public int Compare(object x, object y)
        {
            Magazine x1 = (Magazine) x;
            Magazine y1 = (Magazine) y; 

            
            if (x1.Pages > y1.Pages || x1.Popularity > y1.Popularity)
            {
                return 1;
            }
            else if (x1.Pages < y1.Pages || x1.Popularity < y1.Popularity)
            {
                return -1;
            }
            else
            {
                return 0;
            }

        }
    }
}
