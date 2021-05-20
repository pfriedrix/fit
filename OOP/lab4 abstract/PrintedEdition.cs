
using System;
using System.Linq;


namespace lab4
{

    abstract class PrintedEdition
    {
        private string title;
        private double cost;
        private string language;
        private string purpose;
        protected string[] purposes ={
            "science", "learning", "socio-political"};

        public string Purpose
        {
            get => purpose;
            set
            {
                if (purposes.Contains(value)) purpose = value;
            }
        }

        public string Title
        {
            get => title;
            set => title = value;
        }

        public double Cost
        {
            get => cost;
            set => cost = value;
        }

        public string Language
        {
            get => language;
            set => language = value;
        }
    
        public PrintedEdition(string title, double cost, string language, string purpose)
        {
            this.title = title;
            this.cost = cost;
            this.language = language;
            if (purposes.Contains(purpose)) this.purpose = purpose;
        }

        public void export()
        {
            Console.WriteLine("Title: " + title + " Cost: " + cost + " Lang: " + language + " purpose: " + purpose);
        }
    }
}